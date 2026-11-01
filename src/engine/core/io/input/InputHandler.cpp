#include "InputHandler.h"

Umbrella::InputHandler::InputHandler(Umbrella::IInputIntegration* integration)
{
    _inputIntegration = integration;
}

bool Umbrella::InputHandler::HasKeyProxy(Umbrella::InputKeys key)
{
    for (auto item : _keyDownProxy)
    {
        if (item.first == key)
        {
            return true;
        }
    }
    return false;
}

void Umbrella::InputHandler::AddKeyProxy(Umbrella::InputKeys key)
{
    if (HasKeyProxy(key))
        return;
    _keyDownProxy.insert({key, _inputIntegration->IsKeyDown(key)});
    _keyUpProxy.insert({key, _inputIntegration->IsKeyDown(key)});
}

void Umbrella::InputHandler::StartUp()
{
    _inputBind = {};
    _keyPressed = {};
    _keyDownProxy = {};
    _keyUpProxy = {};
}

void Umbrella::InputHandler::Run()
{
    _inputIntegration->Run();

    for (auto key : _keyDownProxy)
    {
        bool keyDownState = _inputIntegration->IsKeyDown(key.first);
        _keyDownProxy[key.first] = keyDownState;

        if (keyDownState)
        {
            _keyPressed.push_back(key.first);
        }
    }

    for (auto key : _keyUpProxy)
    {
        bool keyUpState = _inputIntegration->IsKeyUp(key.first);
        _keyUpProxy[key.first] = keyUpState;
        if (keyUpState)
        {
            _keyPressed.remove(key.first);
        }
    }
}

void Umbrella::InputHandler::ShutDown()
{
    _inputBind.clear();
    _keyPressed.clear();
    _keyDownProxy.clear();
    _keyUpProxy.clear();
}

bool Umbrella::InputHandler::KeyPressed(std::string nameKey)
{
    if (!HasKey(nameKey))
    {
        return false;
    }
    for (auto key : _inputBind[nameKey])
    {
        if (KeyPressed(key))
        {
            return true;
        }
    }
    return false;
}

bool Umbrella::InputHandler::KeyDown(std::string nameKey)
{
    if (!HasKey(nameKey))
    {
        return false;
    }
    for (auto key : _inputBind[nameKey])
    {
        if (KeyDown(key))
        {
            return true;
        }
    }
    return false;
}

bool Umbrella::InputHandler::KeyUp(std::string nameKey)
{
    if (!HasKey(nameKey))
    {
        return false;
    }
    for (auto key : _inputBind[nameKey])
    {
        if (KeyUp(key))
        {
            return true;
        }
    }
    return false;
}

bool Umbrella::InputHandler::KeyPressed(Umbrella::InputKeys key)
{
    AddKeyProxy(key);
    for (auto keyPressed : _keyPressed)
    {
        if (keyPressed == key)
            return true;
    }
    return KeyDown(key);
}

bool Umbrella::InputHandler::KeyDown(Umbrella::InputKeys key)
{
    AddKeyProxy(key);
    if (_keyDownProxy[key])
    {
        _keyPressed.push_back(key);
        return true;
    }
    return false;
}

bool Umbrella::InputHandler::KeyUp(Umbrella::InputKeys key)
{
    AddKeyProxy(key);
    if (_keyUpProxy[key])
    {
        _keyPressed.remove(key);
        return true;
    }
    return false;
}

void Umbrella::InputHandler::AddInput(std::string nameKey, Umbrella::InputKeys key)
{
    if (!HasKey(nameKey))
    {
        _inputBind.insert({nameKey, {key}});
        return;
    }
    _inputBind[nameKey].push_back(key);
}

bool Umbrella::InputHandler::HasKey(std::string nameKey)
{
    for (auto item : _inputBind)
    {
        if (nameKey == item.first)
        {
            return true;
        }
    }
    return false;
}

glm::vec2 Umbrella::InputHandler::GetVector2(std::string nameKey)
{
    if (!HasKey(nameKey))
    {
        return glm::vec2(0, 0);
    }
    for (auto key : _inputBind[nameKey])
    {
        if (GetVector2(key) != glm::vec2(0, 0))
        {
            return GetVector2(key);
        }
    }

    return glm::vec2(0, 0);
}

float Umbrella::InputHandler::GetFloat(std::string)
{
    return 0;
}

glm::vec2 Umbrella::InputHandler::GetVector2(Umbrella::InputKeys key)
{
    if (key == Umbrella::InputKeys::MOUSE_POSITION)
    {
        return _inputIntegration->GetVector2(key);
    }

    return glm::vec2(0, 0);
}

float Umbrella::InputHandler::GetFloat(Umbrella::InputKeys key)
{
    return 0;
}
