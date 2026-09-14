#include "Scene.h"
#include "../core/UniqueId.h"

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

}

void Umbrella::Scene::RemoveComponent(GameObject* gameObject, IComponent* component)
{

}

bool Umbrella::Scene::HasComponent(GameObject* gameObject, IComponent* component)
{
    return false;
}

void Umbrella::Scene::Update(float deltaTime)
{

}

void Umbrella::Scene::UpdateData(float deltaTime)
{

}
