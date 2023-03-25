//
// Created by brucegoose on 3/25/23.
//

#ifndef TOLIET_CONFIG_HPP
#define TOLIET_CONFIG_HPP

#include "infrastructure/camera/camera.hpp"
#include "infrastructure/websocket/websocket.hpp"

struct Config:
        public infrastructure::CameraConfig,
        public infrastructure::WebsocketConfig
{
    /* camera */
    [[nodiscard]] std::pair<int, int> get_camera_width_height() const final {
#ifdef PLATFORM_BROOSE
        return { 848, 480 };
#else
        return { 1536, 864 };
#endif
    };
    // as opposed to 30
    [[nodiscard]] int get_fps() const final {
        return 30;
    };
    [[nodiscard]] int get_camera_buffer_count() const final {
        return 6;
    };

    /* websocket */
    [[nodiscard]] std::string get_websocket_server_host() const final {
        return "192.168.1.69";
    };
    [[nodiscard]] int get_websocket_server_port() const final {
        return 6969;
    };
    [[nodiscard]] std::chrono::seconds get_websocket_connection_timeout() const final {
        return 10s;
    };
    [[nodiscard]] std::chrono::milliseconds get_websocket_rw_timeout() const final {
        return 3s;
    };
    [[nodiscard]] std::chrono::milliseconds get_websocket_write_delay() const final {
        return 50ms;
    };
};


#endif //TOLIETPIDISPLAY_CONFIG_HPP
