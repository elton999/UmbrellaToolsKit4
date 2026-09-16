#include "Scene.h"

void Umbrella::Scene::AddGameObject(GameObject* gameobject)
{
    if (Umbrella::Scene::HasGameObject(gameobject)) return;
    Umbrella::Scene::_gameObjects.push_back(gameobject);
}

void Umbrella::Scene::RemoveGameObject(GameObject* gameObject)
{
    if (!Umbrella::Scene::HasGameObject(gameObject)) return;
    Umbrella::Scene::_gameObjects.remove(gameObject);
}

GameObject* Umbrella::Scene::CreateGameObject()
{
    return new GameObject
    {
        Umbrella::UniqueId::GetId()
    };
}

bool Umbrella::Scene::HasGameObject(GameObject* gameObject)
{
    for (auto item : _gameObjects)
    {
        if (item->Id.compare(gameObject->Id) == 0)
        {
            return true;
        }
    }

    return false;
}

void Umbrella::Scene::AddComponent(GameObject* gameObject, IComponent* component)
{
    if (!HasGameObject(gameObject))
    {
        Log::MsgError("GameObject not found in the current scene");
        return;
    }

    if (HasComponent(component))
    {
        Log::MsgWarning("Component already been in the current scene");
    }

    component->SetGameObejct(gameObject);
    component->SetScene(this);
    _components.push_back(component);
}

void Umbrella::Scene::RemoveComponent(IComponent* component)
{
    if (!HasGameObject(component->GetGameObject()))
    {
        Log::MsgError("GameObject not found in the current scene");
        return;
    }

    if (!HasComponent(component))
    {
        Log::MsgError("Component not found in the current scene");
    }

    _components.remove(component);
    component->OnDestroy();
}

bool Umbrella::Scene::HasComponent(IComponent* component)
{
    if (!HasGameObject(component->GetGameObject()))
    {
        Log::MsgError("GameObject not found in the current scene");
        return false;
    }

    for(auto componentItem : _components)
    {
        if (componentItem->GetInstanceId().compare(component->GetInstanceId()) == 0)
        {
            return true;
        }
    }

    return false;
}

void Umbrella::Scene::Update(float deltaTime)
{

}

void Umbrella::Scene::UpdateData(float deltaTime)
{

}
