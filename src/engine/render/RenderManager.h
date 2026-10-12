#pragma once

#include <string>
#include <map>
#include <list>

namespace Umbrella
{
    class UmbrellaRoot;
    class IRenderComponent;

    class RenderManager
    {
        private:
            std::map<std::string, std::list<Umbrella::IRenderComponent*>> _layersAndComponents;
            std::list<Umbrella::IRenderComponent*> _allComponents;
            Umbrella::UmbrellaRoot* _root;

        public:
            RenderManager(UmbrellaRoot* root);

            void StartUp();
            void Run();
            void ShutDown();

            void AddRenderComponent(IRenderComponent* renderComponent);
            void AddRenderComponent(IRenderComponent* renderComponent, std::string layer);
            void RemoveRenderComponet(IRenderComponent* renderComponent);
            bool HasComponent(IRenderComponent* renderComponent);

            std::string GetComponentLayer(IRenderComponent* renderComponent);
            void AddLayer(std::string layer);
            bool HasLayer(std::string layer);
    };
}
