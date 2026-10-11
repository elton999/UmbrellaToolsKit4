#pragma once
#include <glm/glm.hpp>
#include "../scene/IComponent.h"

namespace Umbrella
{
    class IRenderComponent : public IComponent
    {
        private:
            glm::vec3 _position;

        public:
            IRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : IComponent(gameObjectId, scene, componentId)
            {
            }

            void SetPosition(glm::vec3 position)
            {
                _position = position;
            }

            glm::vec3 GetPosition()
            {
                return _position;
            }

            virtual void Draw(){}
    };
}
