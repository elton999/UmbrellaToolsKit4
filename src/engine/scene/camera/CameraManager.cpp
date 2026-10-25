#include "CameraManager.h"
#include "scene/camera/Camera.h"

void Umbrella::CameraManager::StartUp()
{
    _camerasByLayer = {};
    SetCamera("default", CreateCamera());
}

void Umbrella::CameraManager::ShutDown()
{
    _camerasByLayer.clear();
}

void Umbrella::CameraManager::SetCamera(std::string layer, Umbrella::Camera* camera)
{
    if (_camerasByLayer.find(layer) != _camerasByLayer.end())
    {
        _camerasByLayer[layer] = camera;
        return;
    }
    _camerasByLayer.insert({layer, camera});
}

Umbrella::Camera* Umbrella::CameraManager::GetCamera(std::string layer)
{
    if (_camerasByLayer.find(layer) != _camerasByLayer.end())
    {
        return _camerasByLayer[layer];
    }

    return _camerasByLayer["default"];
}

Umbrella::Camera* Umbrella::CameraManager::CreateCamera()
{
    Umbrella::Camera* camera = new Umbrella::Camera;
    return camera;
}
