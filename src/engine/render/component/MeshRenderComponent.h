#pragma once

#include "../IRenderComponent.h"

namespace Umbrella
{
    class Material;
    class Mesh;

    class MeshRenderComponent : public IRenderComponent
    {
        private:
            Material* _material = nullptr;
            Mesh* _mesh = nullptr;

        public:

            MeshRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : IRenderComponent(gameObjectId, scene, componentId)
            {
            }

            void SetMaterial(Material* material);
            Material* GetMaterial();
            bool HasMaterial();

            void SetMesh(Mesh* mesh);
            Mesh* GetMesh();
            bool HasMesh();

            void Draw() override;
    };
}
