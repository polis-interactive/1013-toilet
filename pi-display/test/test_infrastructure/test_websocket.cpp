//
// Created by brucegoose on 3/24/23.
//

#include <doctest.h>
#include <iostream>
#include <chrono>
using namespace std::literals;
typedef std::chrono::high_resolution_clock Clock;

#include "infrastructure/websocket/context.hpp"
#include "infrastructure/websocket/websocket.hpp"

struct TestWebsocketConfig:
    public infrastructure::WebsocketConfig
{
    [[nodiscard]] std::string get_websocket_server_host() const override {
        return "192.168.1.69";
    };
    [[nodiscard]] int get_websocket_server_port() const override {
        return 6969;
    };
    [[nodiscard]] std::chrono::seconds get_websocket_connection_timeout() const override {
        return 10s;
    };
    [[nodiscard]] std::chrono::milliseconds get_websocket_rw_timeout() const override {
        return 3s;
    };
    [[nodiscard]] std::chrono::milliseconds get_websocket_write_delay() const override {
        return 50ms;
    };
};

using WebsocketCallback = std::function<void(DisplayMessageType message_type, std::shared_ptr<void>&& buffer)>;

class TestWebsocketManager: public infrastructure::WebsocketManager {
public:
    explicit TestWebsocketManager(WebsocketCallback callback):
        _callback(std::move(callback))
    {}
    void PostWsMessage(DisplayMessageType message_type, std::shared_ptr<void>&& buffer) {
        _callback(message_type, std::move(buffer));
    };
private:
    WebsocketCallback _callback;
};

TEST_CASE("INFRASTRUCTURE_WEBSOCKET_CONTEXT-Start-and-stop") {
    std::chrono::time_point< std::chrono::high_resolution_clock> t1, t2, t3, t4;
    {
        t1 = Clock::now();
        auto ctx = infrastructure::WebsocketContext::Create();
        t2 = Clock::now();
        ctx->Start();
        t3 = Clock::now();
        ctx->Stop();
        t4 = Clock::now();
    }
    auto d1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
    auto d2 = std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2);
    auto d3 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3);
    std::cout << "test_infrastructure/websocket/context startup and teardown: " <<
          d1.count() << ", " << d2.count() << ", " << d3.count() << std::endl;
}

TEST_CASE("INFRASTRUCTURE_WEBSOCKET-Connect-to-pico") {
    auto ctx = infrastructure::WebsocketContext::Create();
    ctx->Start();
    auto conf = TestWebsocketConfig();
    std::atomic_bool first_message = false;
    std::atomic_bool has_connected = false;
    std::atomic_int disconnect_count = 0;
    auto callback = [&first_message, &has_connected, &disconnect_count](
        DisplayMessageType message_type, std::shared_ptr<void>&& buffer
    ) mutable {
        switch (message_type) {
            case DisplayMessageType::CAMERA_IMAGE:
                break;
            case DisplayMessageType::WEBSOCKET_DISCONNECTED:
                disconnect_count++;
                break;
            case DisplayMessageType::WEBSOCKET_CONNECTED:
                has_connected = true;
                break;
            case DisplayMessageType::WEBSOCKET_MESSAGE:
                auto message = std::static_pointer_cast<WebsocketMessage>(buffer);
                std::cout << "Received message: beam broken? " << message->head_beam_is_broken
                    << "; toilet flushed? " << message->toilet_is_flushed << std::endl;
                first_message = true;
        }
    };
    auto manager = std::make_shared<TestWebsocketManager>(callback);
    auto sock = infrastructure::Websocket::Create(conf, ctx->GetContext(), manager);
    sock->Start();
    std::this_thread::sleep_for(10s);
    sock->Stop();
    ctx->Stop();
    REQUIRE(first_message == true);
    REQUIRE(has_connected == true);
    REQUIRE_GT(disconnect_count.load(), 0);
}