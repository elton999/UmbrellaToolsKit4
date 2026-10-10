#pragma once

#include "../IRenderComponent.h"

namespace Umbrella
{
    class Material;
    class Mesh;

    class MeshRenderComponent : public IRenderComponent
    {
        private:
            Material _material;
            Mesh _mesh;

        public:

            void SetMaterial(Material material);
            Material GetMaterial();
            bool HasMaterial();

            void SetMesh(Mesh mesh);
            Mesh GetMesh();
            bool HasMesh();

            void Draw() override;
    };
}
