//
// Created by brucegoose on 3/24/23.
//

#ifndef TOLIET_INFRASTRUCTURE_WEBSOCKET_CONTEXT_HPP
#define TOLIET_INFRASTRUCTURE_WEBSOCKET_CONTEXT_HPP

#include <memory>
#include <boost/asio.hpp>
#include <thread>
#include <iostream>

namespace net = boost::asio;

namespace infrastructure {

    class WebsocketContext {
    public:

        static std::shared_ptr<WebsocketContext> Create() {
            return std::make_shared<WebsocketContext>();
        }
        // reason for the one is code reuse; only one websocket, so we only really need one
        // thread
        WebsocketContext() :
            _context(1),
            _guard(net::make_work_guard(_context)),
            _pool(std::vector<std::jthread>(1))
        {}

        void Start() noexcept {
            std::generate(
                    _pool.begin(),
                    _pool.end(),
                    [&context = this->_context]()-> std::jthread {
                        return std::jthread([&context](std::stop_token st) {
                            while (!st.stop_requested()) {
                                try {
                                    context.run();
                                } catch (std::exception const &e) {
                                    std::cout << e.what() << std::endl;
                                } catch (...) {
                                    std::cout << "WTF Error" << std::endl;
                                }
                            }
                        });
                    }
            );
        }

        void Stop() {
            if (!_context.stopped()) {
                _guard.reset();
                _context.stop();
                if (!_pool.empty()) {
                    for (auto &thread : _pool) {
                        thread.request_stop();
                        thread.join();
                    }
                    _pool.clear();
                }
            }
        }
        // should be marked friend and make this protected, or just use the member directly
        net::io_context &GetContext() {
            return _context;
        }
    private:
        net::io_context _context;
        net::executor_work_guard<net::io_context::executor_type> _guard;
        std::vector<std::jthread> _pool;
    };
}

#endif //TOLIET_INFRASTRUCTURE_WEBSOCKET_CONTEXT_HPP
