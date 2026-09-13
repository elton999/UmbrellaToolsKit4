#include "Scene.h"

void Umbrella::Scene::AddGameObject(GameObject* gameobject)
{

}

void Umbrella::Scene::RemoveGameObject(GameObject* gameObject)
{

}

GameObject* Umbrella::Scene::CreateGameObject()
{
	return nullptr;
}

bool Umbrella::Scene::HasGameObject(GameObject* gameObject)
{
    return false;
}

template <typename TComponent>
TComponent* Umbrella::Scene::AddComponent(GameObject* gameObject)
{

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
