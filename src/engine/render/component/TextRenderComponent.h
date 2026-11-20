#pragma once
#include "../../resources/FontResource.h"
#include "MeshRenderComponent.h"

namespace Umbrella
{
    class Material;

    class TextRenderComponent : public MeshRenderComponent
    {
        private:
            FontResource* _font = nullptr;
            float _fontSize = 1;
            Material* _material = nullptr;

        public:
            TextRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId)
                : MeshRenderComponent(gameObjectId, scene, componentId)
            {
            }
            void SetFont(FontResource* font);
            bool HasFont();

            void SetFontSize(float fontSize);
            float GetFontSize();

            void Draw() override;
    };
} // namespace Umbrella
