//
// Created by brucegoose on 3/24/23.
//

#ifndef TOLIETPIDISPLAY_WEBSOCKET_HPP
#define TOLIETPIDISPLAY_WEBSOCKET_HPP

#include <string>
#include <chrono>
using namespace std::literals;

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>

#include "utils/common.hpp"

#include "context.hpp"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace infrastructure {
    struct WebsocketConfig {
        [[nodiscard]] virtual std::string get_websocket_server_host() const = 0;
        [[nodiscard]] virtual int get_websocket_server_port() const = 0;
        [[nodiscard]] virtual std::chrono::seconds get_websocket_connection_timeout() const = 0;
        [[nodiscard]] virtual std::chrono::milliseconds get_websocket_rw_timeout() const = 0;
        [[nodiscard]] virtual std::chrono::milliseconds get_websocket_write_delay() const = 0;
    };

    class WebsocketManager {
    public:
        virtual void PostMessage(DisplayMessageType message_type, std::shared_ptr<void>&& buffer) = 0;
    };

class Websocket: public std::enable_shared_from_this<Websocket>{
    public:
        static std::shared_ptr<Websocket> Create(
            const WebsocketConfig &config, net::io_context &context, std::shared_ptr<WebsocketManager> manager
        ) {
            return std::make_shared<Websocket>(config, context, std::move(manager));
        }
        Websocket() = delete;
        Websocket (const Websocket&) = delete;
        Websocket& operator= (const Websocket&) = delete;
        ~Websocket() { Stop(); }
        Websocket (
            const WebsocketConfig &config, net::io_context &context, std::shared_ptr<WebsocketManager> manager
        );
        void Start();
        void Stop();
    private:
        void startConnection(const bool is_initial_connection);
        void onConnection(beast::error_code ec);

        void onHandshake(beast::error_code ec);
        void write(beast::error_code ec);
        void onWrite(beast::error_code ec, std::size_t bytes_transferred);
        void onRead(beast::error_code ec, std::size_t bytes_read);
        void disconnect(beast::error_code ec);

        std::shared_ptr<WebsocketManager> _manager;
        std::atomic<bool> _is_stopped = {true};
        std::atomic<bool> _is_connected = {false};
        std::chrono::milliseconds _rw_timeout;
        std::chrono::seconds _connection_timeout;
        std::chrono::seconds _write_delay;
        tcp::endpoint _remote_endpoint;

        const std::string _data_request = "GET_DATA";
        beast::flat_buffer _buffer;

        net::io_context &_context;
        websocket::stream<beast::tcp_stream> _ws;
        net::steady_timer _timer;
    };
}



#endif //TOLIETPIDISPLAY_WEBSOCKET_HPP
