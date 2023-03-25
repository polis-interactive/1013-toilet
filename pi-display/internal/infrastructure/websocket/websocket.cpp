//
// Created by brucegoose on 3/24/23.
//

#include "websocket.hpp"

namespace infrastructure {
    Websocket::Websocket(
        const infrastructure::WebsocketConfig &config, net::io_context &context,
        std::shared_ptr<WebsocketManager> manager
    ):
        _remote_endpoint(
            net::ip::address::from_string(config.get_websocket_server_host()),
            config.get_websocket_server_port()
        ),
        _context(context),
        _timer(net::make_strand(context), config.get_websocket_write_delay()),
        _ws(net::make_strand(context)),
        _connection_timeout(config.get_websocket_connection_timeout()),
        _rw_timeout(config.get_websocket_rw_timeout()),
        _manager(std::move(manager))
    {}
    void Websocket::Start() {
        if (_is_stopped) {
            _is_stopped = false;
            startConnection(true);
            _manager->PostWsMessage(DisplayMessageType::WEBSOCKET_DISCONNECTED, nullptr);
        }
    }

    void Websocket::Stop() {
        if (!_is_stopped) {
            _is_stopped = true;
            auto self(shared_from_this());
            boost::asio::post(
                net::make_strand(_context),
                [this, self]() {
                    beast::error_code ec;
                    disconnect(ec);
                }
            );
        }
    }

    void Websocket::startConnection(const bool is_initial_connection) {
        if (!is_initial_connection) {
            if (_is_stopped) return;
            std::this_thread::sleep_for(5s);
        }
        if (_is_stopped) return;
        std::cout << "Websocket running async connect" << std::endl;
        beast::get_lowest_layer(_ws).expires_after(_connection_timeout);
        beast::get_lowest_layer(_ws).async_connect(
            _remote_endpoint,
            std::bind_front(
                &Websocket::onConnection,
                shared_from_this()
            )
        );
    }

    void Websocket::onConnection(beast::error_code ec) {
        if (ec || _is_stopped) {
            if (ec) {
                std::cout << "Websocket failed to connect; trying again..." << std::endl;
            }
            disconnect(ec);
            return;
        }
        std::cout << "Websocket initiated; starting handshake" << std::endl;
        beast::get_lowest_layer(_ws).expires_never();
        _ws.set_option(
            websocket::stream_base::timeout::suggested(
                beast::role_type::client
            )
        );
        _ws.set_option(websocket::stream_base::decorator(
            [](websocket::request_type& req) {
                req.set(
                    http::field::user_agent,
                    std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-client-async"
                );
            }
        ));
        auto host = _remote_endpoint.address().to_string() + ":" + std::to_string(_remote_endpoint.port());
        _ws.async_handshake(host, "/ws", std::bind_front(
            &Websocket::onHandshake, shared_from_this()
        ));
    }
    void Websocket::onHandshake(beast::error_code ec) {
        if (ec || _is_stopped) {
            if (ec) {
                std::cout << "Websocket handshake failed; reconnecting..." << std::endl;
            }
            disconnect(ec);
            return;
        }
        _is_connected = true;
        _manager->PostWsMessage(DisplayMessageType::WEBSOCKET_CONNECTED, nullptr);
        std::cout << "Websocket connecting; starting write read loop" << std::endl;
        write(ec);
    }

    void Websocket::write(beast::error_code ec) {
        if (ec || _is_stopped) {
            if (ec) {
                std::cout << "Couldn't write as last op failed; reconnecting..." << std::endl;
            }
            disconnect(ec);
            return;
        }
        _ws.async_write(
            net::buffer(_data_request),
            std::bind_front(
                &Websocket::onWrite,
                shared_from_this()
            )
        );
    }

    void Websocket::onWrite(beast::error_code ec, std::size_t bytes_transferred) {
        if (ec || bytes_transferred != _data_request.size() || _is_stopped) {
            if (ec) {
                std::cout << "Failed to write; reconnecting..." << std::endl;
            } else if (!_is_stopped) {
                std::cout << "Couldn't write full payload [" << _data_request << "]"
                    << "; wrote " << bytes_transferred << " of " << _data_request.size() << " bytes"
                    << std::endl;
            }
            disconnect(ec);
            return;
        }
        _ws.async_read(
            _buffer,
            std::bind_front(
                &Websocket::onRead,
                shared_from_this()
            )
        );
    }

    void Websocket::onRead(beast::error_code ec, std::size_t bytes_read) {
        if (ec || bytes_read == 0 || _is_stopped) {
            if (ec) {
                std::cout << "Websocket failed to read; reconnecting..." << std::endl;
            } else if (!_is_stopped) {
                std::cout << "Websocket read no data; reconnecting..." << std::endl;
            }
            disconnect(ec);
            return;
        }
        auto message = beast::buffers_to_string(_buffer.data());
        _buffer.consume(bytes_read);
        if (message.size() < 3 or message.at(1) != ':') {
            std::cout << "Websocket read ill-formed message: " << message << "; reconnecting..." << std::endl;
            disconnect(ec);
            return;
        }
        const bool beam_is_broken = message.at(0) == '1';
        const bool toilet_is_flushed = message.at(2) == '1';
        auto message_data = new WebsocketMessage(beam_is_broken, toilet_is_flushed);
        auto message_ptr = std::shared_ptr<void>((void *) message_data, [](void *ptr) {
            auto message_ptr = static_cast<WebsocketMessage *>(ptr);
            delete message_ptr;
        });
        _manager->PostWsMessage(DisplayMessageType::WEBSOCKET_MESSAGE, std::move(message_ptr));
        // _timer.async_wait(std::bind_front(&Websocket::write, shared_from_this()));
        write(ec);
    }

    void Websocket::disconnect(beast::error_code ec) {
        _manager->PostWsMessage(DisplayMessageType::WEBSOCKET_DISCONNECTED, nullptr);
        _is_connected = false;
        auto self(shared_from_this());
        _ws.async_close(
            websocket::close_code::normal,
            [this, self](beast::error_code ec) {
                startConnection(false);
            }
        );
    }
}
