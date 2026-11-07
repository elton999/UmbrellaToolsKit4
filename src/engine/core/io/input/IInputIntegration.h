#pragma once
#include "InputKeys.h"
#include <glm/glm.hpp>

namespace Umbrella
{
    class IInputIntegration
    {
        public:
            virtual bool IsKeyDown(InputKeys key)
            {
                return false;
            }

            virtual bool IsKeyUp(InputKeys key)
            {
                return false;
            }

            virtual float GetFloat(InputKeys key)
            {
                return 0;
            }

            virtual glm::vec2 GetVector2(InputKeys key)
            {
                return glm::vec2(0, 0);
            }

            virtual void Run() {}
    };
} // namespace Umbrella
