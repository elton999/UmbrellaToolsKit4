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
                    case Umbrella::InputKeys::KEY_A:
                        return GLFW_KEY_A;
                    case Umbrella::InputKeys::KEY_B:
                        return GLFW_KEY_B;
                    case Umbrella::InputKeys::KEY_C:
                        return GLFW_KEY_C;
                    case Umbrella::InputKeys::KEY_D:
                        return GLFW_KEY_D;
                    case Umbrella::InputKeys::KEY_E:
                        return GLFW_KEY_E;
                    case Umbrella::InputKeys::KEY_F:
                        return GLFW_KEY_F;
                    case Umbrella::InputKeys::KEY_G:
                        return GLFW_KEY_G;
                    case Umbrella::InputKeys::KEY_H:
                        return GLFW_KEY_H;
                    case Umbrella::InputKeys::KEY_I:
                        return GLFW_KEY_I;
                    case Umbrella::InputKeys::KEY_J:
                        return GLFW_KEY_J;
                    case Umbrella::InputKeys::KEY_K:
                        return GLFW_KEY_K;
                    case Umbrella::InputKeys::KEY_L:
                        return GLFW_KEY_L;
                    case Umbrella::InputKeys::KEY_M:
                        return GLFW_KEY_M;
                    case Umbrella::InputKeys::KEY_N:
                        return GLFW_KEY_N;
                    case Umbrella::InputKeys::KEY_O:
                        return GLFW_KEY_O;
                    case Umbrella::InputKeys::KEY_P:
                        return GLFW_KEY_P;
                    case Umbrella::InputKeys::KEY_Q:
                        return GLFW_KEY_Q;
                    case Umbrella::InputKeys::KEY_R:
                        return GLFW_KEY_R;
                    case Umbrella::InputKeys::KEY_S:
                        return GLFW_KEY_S;
                    case Umbrella::InputKeys::KEY_T:
                        return GLFW_KEY_T;
                    case Umbrella::InputKeys::KEY_U:
                        return GLFW_KEY_U;
                    case Umbrella::InputKeys::KEY_V:
                        return GLFW_KEY_V;
                    case Umbrella::InputKeys::KEY_W:
                        return GLFW_KEY_W;
                    case Umbrella::InputKeys::KEY_X:
                        return GLFW_KEY_X;
                    case Umbrella::InputKeys::KEY_Y:
                        return GLFW_KEY_Y;
                    case Umbrella::InputKeys::KEY_Z:
                        return GLFW_KEY_Z;
                    case Umbrella::InputKeys::KEY_0:
                        return GLFW_KEY_0;
                    case Umbrella::InputKeys::KEY_1:
                        return GLFW_KEY_1;
                    case Umbrella::InputKeys::KEY_2:
                        return GLFW_KEY_2;
                    case Umbrella::InputKeys::KEY_3:
                        return GLFW_KEY_3;
                    case Umbrella::InputKeys::KEY_4:
                        return GLFW_KEY_4;
                    case Umbrella::InputKeys::KEY_5:
                        return GLFW_KEY_5;
                    case Umbrella::InputKeys::KEY_6:
                        return GLFW_KEY_6;
                    case Umbrella::InputKeys::KEY_7:
                        return GLFW_KEY_7;
                    case Umbrella::InputKeys::KEY_8:
                        return GLFW_KEY_8;
                    case Umbrella::InputKeys::KEY_9:
                        return GLFW_KEY_9;
                    case Umbrella::InputKeys::KEY_SHIFT_LEFT:
                        return GLFW_KEY_LEFT_SHIFT;
                    case Umbrella::InputKeys::KEY_SHIFT_RIGHT:
                        return GLFW_KEY_RIGHT_SHIFT;
                    case Umbrella::InputKeys::KEY_CRTL_LEFT:
                        return GLFW_KEY_LEFT_CONTROL;
                    case Umbrella::InputKeys::KEY_CRTL_RIGHT:
                        return GLFW_KEY_RIGHT_CONTROL;
                    case Umbrella::InputKeys::KEY_SPACE:
                        return GLFW_KEY_SPACE;
                    case Umbrella::InputKeys::KEY_ESC:
                        return GLFW_KEY_ESCAPE;
                    case Umbrella::InputKeys::KEY_ENTER:
                        return GLFW_KEY_ENTER;
                    case Umbrella::InputKeys::KEY_BACKSPACE:
                        return GLFW_KEY_BACKSPACE;
                    case Umbrella::InputKeys::KEY_ARROW_UP:
                        return GLFW_KEY_UP;
                    case Umbrella::InputKeys::KEY_ARROW_DOWN:
                        return GLFW_KEY_DOWN;
                    case Umbrella::InputKeys::KEY_ARROW_LEFT:
                        return GLFW_KEY_LEFT;
                    case Umbrella::InputKeys::KEY_ARROW_RIGHT:
                        return GLFW_KEY_RIGHT;
                    case Umbrella::InputKeys::KEY_F1:
                        return GLFW_KEY_F1;
                    case Umbrella::InputKeys::KEY_F2:
                        return GLFW_KEY_F2;
                    case Umbrella::InputKeys::KEY_F3:
                        return GLFW_KEY_F3;
                    case Umbrella::InputKeys::KEY_F4:
                        return GLFW_KEY_F4;
                    case Umbrella::InputKeys::KEY_F5:
                        return GLFW_KEY_F5;
                    case Umbrella::InputKeys::KEY_F6:
                        return GLFW_KEY_F6;
                    case Umbrella::InputKeys::KEY_F7:
                        return GLFW_KEY_F7;
                    case Umbrella::InputKeys::KEY_F8:
                        return GLFW_KEY_F8;
                    case Umbrella::InputKeys::KEY_F9:
                        return GLFW_KEY_F9;
                    case Umbrella::InputKeys::KEY_F10:
                        return GLFW_KEY_F10;
                    case Umbrella::InputKeys::KEY_F11:
                        return GLFW_KEY_F11;
                    case Umbrella::InputKeys::KEY_F12:
                        return GLFW_KEY_F12;
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
