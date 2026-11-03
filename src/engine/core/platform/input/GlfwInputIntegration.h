#pragma once

#include "../../io/input/IInputIntegration.h"
#include <GLFW/glfw3.h>
#include <list>

namespace Umbrella
{
    class GlfwInputIntegration : public IInputIntegration
    {
        private:
            GLFWwindow* _window;
            std::list<Umbrella::InputKeys> _pressedKeys = {};

        public:
            GlfwInputIntegration(GLFWwindow* window)
            {
                _window = window;
            }

            void Run() override
            {
            }

            bool HasPressedKey(Umbrella::InputKeys key)
            {
                for (auto keyItem : _pressedKeys)
                {
                    if (keyItem == key)
                    {
                        return true;
                    }
                }

                return false;
            }

            bool IsKeyDown(Umbrella::InputKeys key) override
            {
                if (_window == nullptr)
                    return false;
                int keyId = ConvertKey(key);
                if (keyId == -1)
                    return false;

                int state = 0;
                if (key == InputKeys::MOUSE_BUTTON_LEFT || key == InputKeys::MOUSE_BUTTON_RIGHT || key == InputKeys::MOUSE_SCROLL)
                    state = glfwGetMouseButton(_window, keyId);
                else
                    state = glfwGetKey(_window, keyId);

                if (state == GLFW_PRESS)
                {
                    if (!HasPressedKey(key))
                    {
                        _pressedKeys.push_back(key);
                        return true;
                    }
                    return false;
                }

                return false;
            }

            bool IsKeyUp(Umbrella::InputKeys key) override
            {
                if (_window == nullptr)
                    return false;
                int keyId = ConvertKey(key);
                if (keyId == -1)
                    return false;
                int state = 0;
                if (key == InputKeys::MOUSE_BUTTON_LEFT || key == InputKeys::MOUSE_BUTTON_RIGHT || key == InputKeys::MOUSE_SCROLL)
                    state = glfwGetMouseButton(_window, keyId);
                else
                    state = glfwGetKey(_window, keyId);

                if (state == GLFW_RELEASE)
                {
                    if (HasPressedKey(key))
                    {
                        _pressedKeys.remove(key);
                        return true;
                    }
                    return false;
                }
                return false;
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
