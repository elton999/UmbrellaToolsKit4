#include "IComponent.h"
#include "GameObject.h"
#include "Scene.h"

Umbrella::IComponent::IComponent(std::string gameObjectId, Scene* scene, std::string componentId)
{
    _gameObjectId = gameObjectId;
    _scene = scene;
    _componentInstanceId = componentId;
}

void Umbrella::IComponent::Inicialization()
{
    if (!GetActiveStatus())
        return;
    if (!_isStartUp)
    {
        OnStartUp();
        _isStartUp = true;
    }
}

void Umbrella::IComponent::InicializationFirstFrame()
{
    if (!GetActiveStatus())
        return;
    if (!_isStartUp)
    {
        OnStartUp();
        _isStartUp = true;
    }

    if (!_isStarted)
    {
        OnInit();
        OnEnable();
        _isStarted = true;
    }
}

GameObject* Umbrella::IComponent::GetGameObject()
{
    if (this == nullptr)
    {
        return nullptr;
    }

    if (_scene == nullptr)
    {
        return nullptr;
    }

    if (_gameObjectId.empty())
    {
        return nullptr;
    }

    return _scene->GetGameObject(_gameObjectId);
}

void Umbrella::IComponent::SetGameObject(GameObject* gameobejct)
{
    _gameObjectId = gameobejct->Id;
}

void Umbrella::IComponent::SetScene(Umbrella::Scene* scene)
{
    _scene = scene;
}

Umbrella::Scene* Umbrella::IComponent::GetScene()
{
    return _scene;
}

std::string Umbrella::IComponent::GetInstanceId()
{
    return _componentInstanceId;
}

void Umbrella::IComponent::SetActive(bool status)
{
    _isEnable = status;
}

bool Umbrella::IComponent::GetActiveStatus()
{
    if (GetGameObject() == nullptr)
    {
        return false;
    }
    return _isEnable && GetGameObject()->IsEnable;
}
