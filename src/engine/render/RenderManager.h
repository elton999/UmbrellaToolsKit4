#pragma once

#include "../UmbrellaRoot.h"
#include "IRenderComponent.h"
#include <string>
#include <map>

namespace Umbrella
{
    class RenderManager
    {
        private:
            std::list<std::string, Umbrella::IRenderComponent*> _layersAndComponents;

        public:
            RenderManager(UmbrellaRoot* root);

            void StartUp();
            void Run();
            void ShutDown();

            void AddRenderComponent(IRenderComponent* renderComponent);
            void AddRenderComponent(IRenderComponent *renderComponent, std::string layer);
            void RemoveRenderComponet(IRenderComponent* renderComponent);
            bool HasComponent(IRenderComponent* renderComponent);

            std::string GetComponentLayer(IRenderComponent* renderComponent);
            void AddLayer(std::string layer);
            bool HasLayer(std::string layer);
    };
}
