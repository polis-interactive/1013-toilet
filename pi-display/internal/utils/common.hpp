//
// Created by brucegoose on 3/24/23.
//

#ifndef TOILET_UTILS_MESSAGES_HPP
#define TOILET_UTILS_MESSAGES_HPP

enum class DisplayMessageType {
    WEBSOCKET_CONNECTED,
    WEBSOCKET_MESSAGE,
    WEBSOCKET_DISCONNECTED,
    CAMERA_IMAGE
};

struct WebsocketMessage {
    WebsocketMessage(const bool beam_is_broken, const bool is_flushed):
        head_beam_is_broken(beam_is_broken),
        toilet_is_flushed(is_flushed)
    {}
    const bool head_beam_is_broken;
    const bool toilet_is_flushed;
};

#endif //TOILET_UTILS_MESSAGES_HPP
