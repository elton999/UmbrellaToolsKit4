#pragma once
#include <glm/glm.hpp>

namespace Umbrella
{
    class Camera
    {
        private:
            glm::vec3 _position;
            glm::vec3 _rotation;
            glm::vec3 _scale;

            glm::ivec2 _size;

        public:
            void SetPosition(glm::vec3 position);
            glm::vec3 GetPosition();

            void SetRotation(glm::vec3 rotation);
            glm::vec3 GetRotation();

            void SetScale(glm::vec3 scale);
            glm::vec3 GetScale();

            void SetSize(glm::ivec2);
            glm::ivec2 GetSize();

            glm::mat4 GetCameraMatrix();
    };
} // namespace Umbrella
