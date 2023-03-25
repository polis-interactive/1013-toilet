//
// Created by brucegoose on 3/24/23.
//

#ifndef TOILET_INFRASTRUCTURE_GRAPHICS_HPP
#define TOILET_INFRASTRUCTURE_GRAPHICS_HPP

#include <memory>
#include <thread>
#include <queue>
#include <mutex>
#include <atomic>
#include <map>

#define GLAD_GL_IMPLEMENTATION
#include "glad/glad_egl.h"
#include "glad/glad.h"

#define GLFW_INCLUDE_NONE 1
#include <GLFW/glfw3.h>

#define GLFW_EXPOSE_NATIVE_EGL 1
#define GLFW_NATIVE_INCLUDE_NONE 1
#include <GLFW/glfw3native.h>

#include "utils/buffers.hpp"
#include "utils/common.hpp"

#include <chrono>
using namespace std::literals;
typedef std::chrono::high_resolution_clock Clock;

using time_stamp = std::chrono::time_point< std::chrono::high_resolution_clock>;

struct EglBuffer
{
    EglBuffer() : fd(-1) {}
    int fd;
    size_t size;
    GLuint texture;
};

namespace infrastructure {
class Graphics : public std::enable_shared_from_this<Graphics> {
    public:
        static std::shared_ptr<Graphics> Create() {
            return std::make_shared<Graphics>();
        }
        Graphics() {}
        ~Graphics() {
            Stop();
        }
        void Start();
        void Stop();
        void PostImage(std::shared_ptr<CameraBuffer>&& buffer);
        void PostParameters(std::shared_ptr<WebsocketMessage>&& message);
        void PostToiletConnected(const bool toilet_is_connected);
    private:

        void run(std::stop_token st);

        void setWindowHints();
        void setupDisplay();

        std::mutex _image_mutex;
        std::atomic_bool _is_ready = false;
        std::atomic_bool _toilet_is_connected = false;
        std::atomic<time_stamp> _last_toilet_flush = Clock::now();
        std::atomic_bool _person_detected = false;
        std::unique_ptr<std::jthread> graphics_thread = nullptr;
        std::queue<std::shared_ptr<CameraBuffer>> _image_queue;

        const int _width = 1920;
        const int _height = 1080;
        GLFWwindow *_window;
        std::map<int, EglBuffer> _buffers;
    };
}

#endif //TOILET_INFRASTRUCTURE_GRAPHICS_HPP
