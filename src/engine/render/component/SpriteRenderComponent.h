#pragma once

#include "MeshRenderComponent.h"
#include "../Sprite.h"
#include "../Mesh.h"
#include "../Material.h"
#include "../Shader.h"

#include <vector>
#include <glm/glm.hpp>

namespace Umbrella
{
    class SpriteRenderComponent : public MeshRenderComponent
    {
        private:
            glm::vec2 _scale;
            glm::vec4 _spriteColor;
            glm::vec4 _fillSpriteColor;
            float _transparence;
            Sprite* _sprite;

        public:
            void OnStartUp() override;
            void OnUpdate(float deltaTime) override;

            void SetScale(float scale);
            void SetScale(glm::vec2 scale);
            glm::vec2 GetScale();

            void SetTransparence(float transparence);
            float GetTransparence();

            void SetSpriteColor(glm::vec4 color);
            glm::vec4 GetSpriteColor();

            void SetFillSpriteColor(glm::vec4 color);
            glm::vec4 GetFillSpriteColor();

            void SetRotation(float rotation);
            float GetRotation2D();

            void SetSprite(Sprite* sprite);
            Sprite* GetSprite();
            bool HasSprite();
    };
}
