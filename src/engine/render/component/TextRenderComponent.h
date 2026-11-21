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
            std::string _text = "";

        public:
            TextRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId)
                : MeshRenderComponent(gameObjectId, scene, componentId)
            {
            }

            void OnStartUp() override;
            void SetFont(FontResource* font);
            bool HasFont();
            FontResource* GetFont();

            void SetFontSize(float fontSize);
            float GetFontSize();

            std::string GetText();
            void SetText(std::string text);
            bool HasText();

            void Draw() override;
    };
} // namespace Umbrella
