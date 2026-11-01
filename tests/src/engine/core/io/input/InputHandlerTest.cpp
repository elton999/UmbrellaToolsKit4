
#include "../../../../../../src/engine/core/io/input/InputHandler.h"
#include "../../../../../../src/engine/core/io/input/IInputIntegration.h"
#include <catch2/catch_test_macros.hpp>
#include <list>

class InputIntegrationTest : public Umbrella::IInputIntegration
{
    private:
        std::list<Umbrella::InputKeys> _keysPressed = {};
        glm::vec2 _position = {0, 0};
        float _scrollValue;

    public:
        bool IsKeyDown(Umbrella::InputKeys key) override
        {
            for (auto keyInList : _keysPressed)
            {
                if (key == keyInList)
                {
                    return true;
                }
            }
            return false;
        }

        bool IsKeyUp(Umbrella::InputKeys key) override
        {
            for (auto keyInList : _keysPressed)
            {
                if (key == keyInList)
                {
                    return false;
                }
            }

            return true;
        }

        void Run() override
        {
        }

        float GetFloat(Umbrella::InputKeys key) override
        {
            return 0;
        }

        glm::vec2 GetVector2(Umbrella::InputKeys key) override
        {
            return _position;
        }

        void PressKey(Umbrella::InputKeys key)
        {
            for (auto keyInList : _keysPressed)
            {
                if (key == keyInList)
                {
                    return;
                }
            }

            _keysPressed.push_back(key);
        }

        void ReleaseKey(Umbrella::InputKeys key)
        {
            _keysPressed.remove(key);
        }

        void SetMousePosition(glm::vec2 position)
        {
            _position = position;
        }

        void SetSrollValue(float value)
        {
            _scrollValue = value;
        }
};

TEST_CASE("Test input click simple")
{
    auto* inputBackEnd = new InputIntegrationTest;
    Umbrella::InputHandler* inputHandler = new Umbrella::InputHandler(inputBackEnd);
    inputHandler->StartUp();
    inputHandler->Run();

    REQUIRE_FALSE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyDown(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));
    REQUIRE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));

    inputBackEnd->PressKey(Umbrella::InputKeys::MOUSE_BUTTON_LEFT);
    inputHandler->Run();

    REQUIRE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE(inputHandler->KeyDown(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));
    REQUIRE_FALSE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));

    inputHandler->Run();

    REQUIRE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyDown(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));
    REQUIRE_FALSE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));

    inputBackEnd->ReleaseKey(Umbrella::InputKeys::MOUSE_BUTTON_LEFT);
    inputBackEnd->Run();

    REQUIRE_FALSE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyDown(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE_FALSE(inputHandler->KeyPressed(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));
    REQUIRE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_LEFT));
    REQUIRE(inputHandler->KeyUp(Umbrella::InputKeys::MOUSE_BUTTON_RIGHT));
}

TEST_CASE("Test input bind")
{
    auto* inputBackEnd = new InputIntegrationTest;
    Umbrella::InputHandler* inputHandler = new Umbrella::InputHandler(inputBackEnd);

    std::string mouse_left = "mouse left";
    std::string mouse_right = "mouse right";

    inputHandler->StartUp();

    inputHandler->AddInput(mouse_left, Umbrella::InputKeys::MOUSE_BUTTON_LEFT);
    inputHandler->AddInput(mouse_right, Umbrella::InputKeys::MOUSE_BUTTON_RIGHT);

    inputHandler->Run();

    REQUIRE_FALSE(inputHandler->KeyPressed(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyDown(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyPressed(mouse_right));
    REQUIRE(inputHandler->KeyUp(mouse_left));
    REQUIRE(inputHandler->KeyUp(mouse_right));

    inputBackEnd->PressKey(Umbrella::InputKeys::MOUSE_BUTTON_LEFT);
    inputHandler->Run();

    REQUIRE(inputHandler->KeyPressed(mouse_left));
    REQUIRE(inputHandler->KeyDown(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyPressed(mouse_right));
    REQUIRE_FALSE(inputHandler->KeyUp(mouse_left));
    REQUIRE(inputHandler->KeyUp(mouse_left));

    inputHandler->Run();

    REQUIRE(inputHandler->KeyPressed(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyDown(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyPressed(mouse_right));
    REQUIRE_FALSE(inputHandler->KeyUp(mouse_left));
    REQUIRE(inputHandler->KeyUp(mouse_right));

    inputBackEnd->ReleaseKey(Umbrella::InputKeys::MOUSE_BUTTON_LEFT);
    inputBackEnd->Run();

    REQUIRE_FALSE(inputHandler->KeyPressed(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyDown(mouse_left));
    REQUIRE_FALSE(inputHandler->KeyPressed(mouse_right));
    REQUIRE(inputHandler->KeyUp(mouse_left));
    REQUIRE(inputHandler->KeyUp(mouse_right));
}

TEST_CASE("Test mouse position")
{
    auto* inputBackEnd = new InputIntegrationTest;
    Umbrella::InputHandler* inputHandler = new Umbrella::InputHandler(inputBackEnd);

    inputHandler->StartUp();

    inputHandler->Run();

    REQUIRE(inputHandler->GetVector2(Umbrella::InputKeys::MOUSE_POSITION) == glm::vec2(0, 0));

    inputBackEnd->SetMousePosition({1, 1});
    inputHandler->Run();

    REQUIRE(inputHandler->GetVector2(Umbrella::InputKeys::MOUSE_POSITION) == glm::vec2(1, 1));
}

TEST_CASE("Test mouse position by bind")
{
    auto* inputBackEnd = new InputIntegrationTest;
    Umbrella::InputHandler* inputHandler = new Umbrella::InputHandler(inputBackEnd);

    inputHandler->StartUp();
    inputHandler->AddInput("mouse position", Umbrella::InputKeys::MOUSE_POSITION);

    inputHandler->Run();

    REQUIRE(inputHandler->GetVector2("mouse position") == glm::vec2(0, 0));

    inputBackEnd->SetMousePosition({1, 1});
    inputHandler->Run();

    REQUIRE(inputHandler->GetVector2("mouse position") == glm::vec2(1, 1));
}
