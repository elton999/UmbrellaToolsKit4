#include "IRenderComponent.h"
#include "RenderManager.h"
#include "../UmbrellaRoot.h"

Umbrella::RenderManager::RenderManager(Umbrella::UmbrellaRoot* root)
{
    _root = root;
}

void Umbrella::RenderManager::StartUp()
{
    _layersAndComponents = {};
    _layersAndComponents.insert({ "default", {} });
    _allComponents = {};
}

void Umbrella::RenderManager::Run()
{
    if (_allComponents.size() == 0) return;

    for (auto layer : _layersAndComponents)
    {
        for (auto component : layer.second)
        {
            if (component->GetActiveStatus())
            {
                component->Draw();
            }
        }
    }
}

void Umbrella::RenderManager::ShutDown()
{
    _layersAndComponents.clear();
    _allComponents.clear();
}

void Umbrella::RenderManager::AddRenderComponent(IRenderComponent* renderComponent)
{
    if (HasComponent(renderComponent)) return;
    _layersAndComponents["default"].push_back(renderComponent);
    _allComponents.push_back(renderComponent);
}

void Umbrella::RenderManager::AddRenderComponent(IRenderComponent* renderComponent, std::string layer)
{
    if (HasComponent(renderComponent)) return;
    AddLayer(layer);
    _layersAndComponents[layer].push_back(renderComponent);
    _allComponents.push_back(renderComponent);
}

void Umbrella::RenderManager::RemoveRenderComponet(IRenderComponent* renderComponent)
{
    if (!HasComponent(renderComponent)) return;

    std::string layer = GetComponentLayer(renderComponent);

    _allComponents.remove(renderComponent);
    _layersAndComponents[layer].remove(renderComponent);
}

bool Umbrella::RenderManager::HasComponent(IRenderComponent* renderComponent)
{
    if (_allComponents.size() == 0) return false;

    for (auto component : _allComponents)
    {
        if (component->GetInstanceId().compare(renderComponent->GetInstanceId()) == 0)
            return true;
    }

    return false;
}

std::string Umbrella::RenderManager::GetComponentLayer(IRenderComponent* renderComponent)
{
    if (_allComponents.size() == 0) return "";

    for (auto layer : _layersAndComponents)
    {
        for (auto component : layer.second)
        {
            if (component->GetInstanceId().compare(renderComponent->GetInstanceId()) == 0)
                return layer.first;
        }
    }

    return "";
}

void Umbrella::RenderManager::AddLayer(std::string layer)
{
    if (HasLayer(layer)) return;

    _layersAndComponents.insert({ layer, {} });
}

bool Umbrella::RenderManager::HasLayer(std::string layer)
{
    for (auto layerItem : _layersAndComponents)
    {
        if (layerItem.first.compare(layer) == 0)
            return true;
    }
    return false;
}
