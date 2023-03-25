//
// Created by brucegoose on 3/25/23.
//

#include "application/config.hpp"
#include "infrastructure/camera/camera.hpp"
#include "infrastructure/websocket/context.hpp"
#include "infrastructure/websocket/websocket.hpp"
#include "infrastructure/graphics/graphics.hpp"

class Service:
    public infrastructure::InternalCameraManager,
    public infrastructure::WebsocketManager,
    public std::enable_shared_from_this<Service>
{
public:
    static std::shared_ptr<Service> Create(const Config &conf) {
        auto service =  std::make_shared<Service>();
        service->_graphics = infrastructure::Graphics::Create();
        service->_context = infrastructure::WebsocketContext::Create();
        service->_websocket = infrastructure::Websocket::Create(
            conf, service->_context->GetContext(), service->shared_from_this()
        );
        service->_camera = infrastructure::Camera::Create(conf, service->shared_from_this());
        return service;
    }
    void Start() {
        _graphics->Start();
        _context->Start();
        _websocket->Start();
        _camera->Start();
    }
    void Stop() {
        _websocket->Stop();
        _context->Stop();
        _graphics->Stop();
        _camera->Stop();
    }
    void PostMessage(DisplayMessageType message_type, std::shared_ptr<void>&& buffer) final {
        switch (message_type) {
            case DisplayMessageType::CAMERA_IMAGE:
                _graphics->PostImage(std::move(std::static_pointer_cast<CameraBuffer>(buffer)));
                break;
            case DisplayMessageType::WEBSOCKET_DISCONNECTED:
                _graphics->PostToiletConnected(false);
                break;
            case DisplayMessageType::WEBSOCKET_CONNECTED:
                _graphics->PostToiletConnected(true);
                break;
            case DisplayMessageType::WEBSOCKET_MESSAGE:
                _graphics->PostParameters(std::static_pointer_cast<WebsocketMessage>(buffer));
                break;
        }
    }
    Service()= default;
private:
    std::shared_ptr<infrastructure::Graphics> _graphics = nullptr;
    std::shared_ptr<infrastructure::WebsocketContext> _context = nullptr;
    std::shared_ptr<infrastructure::Websocket> _websocket = nullptr;
    std::shared_ptr<infrastructure::Camera> _camera = nullptr;
};
