//
// Created by brucegoose on 2/18/23.
//

#ifndef TOILET_INFRASTRUCTURE_CAMERA_HPP
#define TOILET_INFRASTRUCTURE_CAMERA_HPP

#include <map>
#include <queue>
#include <vector>
#include <mutex>

#include <libcamera/camera.h>
#include <libcamera/camera_manager.h>
#include <libcamera/framebuffer_allocator.h>

#include "utils/common.hpp"
#include "utils/buffers.hpp"

namespace infrastructure {
    struct CameraConfig {
        [[nodiscard]] virtual std::pair<int, int> get_camera_width_height() const = 0;
        // as opposed to 30
        [[nodiscard]] virtual int get_fps() const = 0;
        [[nodiscard]] virtual int get_camera_buffer_count() const = 0;
    };

    class InternalCameraManager {
    public:
        virtual void PostMessage(DisplayMessageType message_type, std::shared_ptr<void>&& buffer) = 0;
    };

    class Camera : public std::enable_shared_from_this<Camera> {
    public:
        Camera(const CameraConfig &config, std::shared_ptr<InternalCameraManager> manager):
            _manager(std::move(manager))
        {
            createCamera(config);
        };
        void Start();
        void Stop();
        ~Camera() {
            Stop();
            teardownCamera();
            closeCamera();
        }
    private:
        void createCamera(const CameraConfig &config);

        void openCamera();
        void configureViewFinder(const CameraConfig &config);
        void setupBuffers(const int &camera_buffer_count);

        void makeRequests();
        void setControls();
        void requestComplete(libcamera::Request *request);
        void queueRequest(CameraBuffer *buffer);

        void closeCamera();
        void teardownCamera();

        std::shared_ptr<InternalCameraManager> _manager;

        std::unique_ptr<libcamera::CameraManager> _camera_manager;
        std::shared_ptr<libcamera::Camera> _camera;
        std::unique_ptr<libcamera::CameraConfiguration> _configuration;

        std::mutex _camera_stop_mutex;
        bool _camera_acquired = false;
        bool _camera_started = false;

        float _frame_rate = 0.0;

        std::unique_ptr<libcamera::FrameBufferAllocator> _allocator;
        std::map<std::string, libcamera::Stream *> _streams;
        std::map<libcamera::Stream *, std::queue<libcamera::FrameBuffer *>> _frame_buffers;
        std::map<libcamera::FrameBuffer *, std::vector<libcamera::Span<uint8_t>>> _mapped_buffers;
        std::vector<std::unique_ptr<libcamera::Request>> _requests;

        std::mutex _camera_buffers_mutex;
        std::set<CameraBuffer *> _camera_buffers;

        libcamera::ControlList _controls;
    };
}

#endif //TOILET_INFRASTRUCTURE_CAMERA_HPP
