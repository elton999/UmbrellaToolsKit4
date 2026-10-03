#include "Shader.h"


Umbrella::Shader::Shader(const char* vertexCode, const char* fragmentCode)
{
}

void Umbrella::Shader::Use()
{
}

void Umbrella::Shader::SetBool(std::string name, bool value)
{
}

void Umbrella::Shader::SetInt(std::string name, int value)
{
}

void Umbrella::Shader::SetFloat(std::string name, float value)
{
}

void Umbrella::Shader::SetVec3(std::string name, glm::vec3 value)
{
}

void Umbrella::Shader::SetVec2(std::string name, glm::vec2 value)
{
}

void Umbrella::Shader::SetMatrix4(std::string name, glm::mat4 value)
{
}

bool Umbrella::Shader::GetBool(std::string name)
{
    return false;
}

int Umbrella::Shader::GetInt(std::string name)
{
    return 0;
}

float Umbrella::Shader::GetFloat(std::string name)
{
    return 0.0;
}

glm::vec3 Umbrella::Shader::GetVec3(std::string name)
{
    return glm::vec3(0,0,0);
}

glm::vec2 Umbrella::Shader::GetVec2(std::string name)
{
    return glm::vec2(0, 0);
}

glm::mat4 Umbrella::Shader::GetMatrix4(std::string name)
{
    return glm::mat4();
}
