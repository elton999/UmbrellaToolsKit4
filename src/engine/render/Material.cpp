#include "Material.h"
#include "Shader.h"
#include "Texture2D.h"

void Umbrella::Material::SetShader(Shader* shader)
{

}

Umbrella::Shader* Umbrella::Material::GetShader()
{

}

bool Umbrella::Material::HasShader()
{
    return false;
}

void Umbrella::Material::SetTexture(Umbrella::Texture2D* texute)
{
}

Umbrella::Texture2D* Umbrella::Material::GetTexture()
{
    return nullptr;
}

bool Umbrella::Material::HasTexture()
{
    return false;
}

void Umbrella::Material::SetBool(std::string name, bool value)
{
}

void Umbrella::Material::SetInt(std::string name, int value)
{
}

void Umbrella::Material::SetFloat(std::string name, float value)
{
}

void Umbrella::Material::SetVec3(std::string name, glm::vec3 value)
{
}

void Umbrella::Material::SetVec2(std::string name, glm::vec2 value)
{
}

void Umbrella::Material::SetMatrix4(std::string name, glm::mat4 value)
{
}

bool Umbrella::Material::GetBool(std::string name)
{
    return false;
}

int Umbrella::Material::GetInt(std::string name)
{
    return 0;
}

float Umbrella::Material::GetFloat(std::string name)
{
    return 0.0;
}

glm::vec3 Umbrella::Material::GetVec3(std::string name)
{
    return glm::vec3(0, 0, 0);
}

glm::vec2 Umbrella::Material::GetVec2(std::string name)
{
    return glm::vec2(0, 0);
}

glm::mat4 Umbrella::Material::GetMatrix4(std::string name)
{
    return glm::mat4();
}
