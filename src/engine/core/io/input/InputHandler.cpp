#include "InputHandler.h"

void Umbrella::InputHandler::StartUp()
{
}

void Umbrella::InputHandler::Run()
{
}

void Umbrella::InputHandler::ShutDown()
{
}

bool Umbrella::InputHandler::KeyPressed(std::string nameKey)
{
    return false;
}

bool Umbrella::InputHandler::KeyDown(std::string nameKey)
{
    return false;
}

bool Umbrella::InputHandler::KeyUp(std::string nameKey)
{
    return false;
}

bool Umbrella::InputHandler::KeyPressed(Umbrella::InputKeys key)
{
    return false;
}

bool Umbrella::InputHandler::KeyDown(Umbrella::InputKeys key)
{
    return false;
}

bool Umbrella::InputHandler::KeyUp(Umbrella::InputKeys key)
{
    return false;
}

void Umbrella::InputHandler::AddInput(std::string nameKey, Umbrella::InputKeys key)
{
}

bool Umbrella::InputHandler::HasKey(std::string nameKey)
{
    return false;
}

glm::vec2 Umbrella::InputHandler::GetVector2(std::string nameKey)
{
    return glm::vec2(0, 0);
}

float Umbrella::InputHandler::GetFloat(std::string)
{
    return 0;
}

glm::vec2 Umbrella::InputHandler::GetVector2(Umbrella::InputKeys key)
{
    return glm::vec2(0, 0);
}

float Umbrella::InputHandler::GetFloat(Umbrella::InputKeys key)
{
    return 0;
}
