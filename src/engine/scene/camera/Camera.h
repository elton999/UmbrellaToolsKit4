#pragma once
#include "glm/ext/vector_float3.hpp"
#include <glm/glm.hpp>

namespace Umbrella
{
    class Camera
    {
        private:
            glm::vec3 _position;
            glm::vec3 _rotation;
            glm::vec3 _scale;

        public:
            void SetPosition(glm::vec3 position);
            glm::vec3 GetPosition();

            void SetRotation(glm::vec3 rotation);
            glm::vec3 GetRotation();

            void SetScale(glm::vec3 scale);
            glm::vec3 GetScale();
    };
} // namespace Umbrella
