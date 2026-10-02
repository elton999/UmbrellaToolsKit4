#pragma once
#include <glm/glm.hpp>

namespace Umbrella
{
    class IRenderComponent
    {
        private:
            glm::vec3 _position;

        public:
            void SetPosition(glm::vec3 position)
            {
                _position = position;
            }

            glm::vec3 GetPosition()
            {
                return _position;
            }

            virtual void Draw();
    };
}
