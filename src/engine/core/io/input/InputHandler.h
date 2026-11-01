#pragma once
#include "IInputIntegration.h"
#include <glm/glm.hpp>
#include <string>

namespace Umbrella
{
    class InputHandler
    {
        private:
            IInputIntegration* _inputIntegration;

        public:
            InputHandler(IInputIntegration* integration);
            void StartUp();
            void Run();
            void ShutDown();

            bool KeyPressed(std::string nameKey);
            bool KeyDown(std::string nameKey);
            bool KeyUp(std::string nameKey);

            bool KeyPressed(InputKeys key);
            bool KeyDown(InputKeys key);
            bool KeyUp(InputKeys key);

            void AddInput(std::string nameKey, InputKeys key);
            bool HasKey(std::string nameKey);

            glm::vec2 GetVector2(std::string nameKey);
            float GetFloat(std::string nameKey);

            glm::vec2 GetVector2(InputKeys key);
            float GetFloat(InputKeys key);
    };
} // namespace Umbrella
