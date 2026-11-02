#pragma once

#include "../../io/input/IInputIntegration.h"
#include <GLFW/glfw3.h>

namespace Umbrella
{
    class GlfwInputIntegration : public IInputIntegration
    {
        private:
            GLFWwindow* _window;

        public:
            GlfwInputIntegration(GLFWwindow* window)
            {
                _window = window;
            }

            void Run() override
            {
            }

            bool IsKeyDown(Umbrella::InputKeys key) override
            {
		if (_window == nullptr) return false;
                int keyId = ConvertKey(key);
                if (keyId == -1)
                    return false;

                int state = 0;
                if (key == InputKeys::MOUSE_BUTTON_LEFT || key == InputKeys::MOUSE_BUTTON_RIGHT || key == InputKeys::MOUSE_SCROLL)
                    state = glfwGetMouseButton(_window, keyId);
                else
                    state = glfwGetKey(_window, keyId);
                return state == GLFW_PRESS;
            }

            bool IsKeyUp(Umbrella::InputKeys key) override
            {
		if (_window == nullptr) return false;
               	int keyId = ConvertKey(key);
                if (keyId == -1)
                    return false;
		 int state = 0;
                if (key == InputKeys::MOUSE_BUTTON_LEFT || key == InputKeys::MOUSE_BUTTON_RIGHT || key == InputKeys::MOUSE_SCROLL)
                    state = glfwGetMouseButton(_window, keyId);
                else
                    state = glfwGetKey(_window, keyId);

                state = glfwGetKey(_window, keyId);
                return state == GLFW_RELEASE;
            }

            int ConvertKey(Umbrella::InputKeys key)
            {
                switch (key)
                {
                    case Umbrella::InputKeys::MOUSE_BUTTON_LEFT:
                        return GLFW_MOUSE_BUTTON_LEFT;
                    case Umbrella::InputKeys::MOUSE_BUTTON_RIGHT:
                        return GLFW_MOUSE_BUTTON_RIGHT;
                    case Umbrella::InputKeys::MOUSE_SCROLL:
                        return GLFW_MOUSE_BUTTON_MIDDLE;
                    default:
                        return -1;
                }

                return -1;
            }

            glm::vec2 GetVector2(Umbrella::InputKeys key) override
            {
                if (key == Umbrella::InputKeys::MOUSE_POSITION)
                {
                    double xpos, ypos;
                    glfwGetCursorPos(_window, &xpos, &ypos);
                    return glm::vec2(xpos, ypos);
                }
                return glm::vec2(0, 0);
            }
    };
} // namespace Umbrella
