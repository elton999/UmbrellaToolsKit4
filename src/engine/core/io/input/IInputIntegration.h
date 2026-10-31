#pragma once
#include "InputKeys.h"
#include <glm/glm.hpp>

namespace Umbrella
{
    class IInputIntegration
    {
        public:
            virtual bool IsKeyDown(InputKeys key);
            virtual bool IsKeyUp(InputKeys key);

            virtual float GetFloat(InputKeys key);
            virtual glm::vec2 GetVector2(InputKeys key);

            virtual void Run();
    };
} // namespace Umbrella
