#pragma once

#include "MeshRenderComponent.h"
#include "../Mesh.h"
#include "../Material.h"
#include "../Shader.h"
#include <glm/glm.hpp>

namespace Umbrella
{
    class SquareRenderComponent : public MeshRenderComponent
    {
        private:
            glm::vec2 _size = { 10, 10 };

        public:
            SquareRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : MeshRenderComponent(gameObjectId, scene, componentId)
            {}

            void OnStartUp() override;
            void OnUpdate(float deltaTime) override;
            void SetSize(glm::vec2 size);
            glm::vec2 GetSize();
    };
}
