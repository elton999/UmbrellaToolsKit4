#pragma once
#include "../../resources/FontResource.h"
#include "../IRenderComponent.h"

namespace Umbrella
{
    class TextRenderComponent : public IRenderComponent
    {
        private:
            FontResource* _font;
            float fontSize = 1;

        public:
            TextRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId)
                : IRenderComponent(gameObjectId, scene, componentId)
            {
            }
            void SetFont(FontResource* font);
            bool HasFont();

            void SetFontSize(float fontSize);
            float GetFontSize();

            void Draw() override;
    };
} // namespace Umbrella
