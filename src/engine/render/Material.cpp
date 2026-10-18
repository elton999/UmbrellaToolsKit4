#include "Material.h"
#include "Shader.h"
#include "Texture2D.h"

void Umbrella::Material::SetShader(Shader* shader)
{
    _shader = shader;
}

Umbrella::Shader* Umbrella::Material::GetShader()
{
    if (HasShader())
        return _shader;
    return nullptr;
}

bool Umbrella::Material::HasShader()
{
    if (_shader == nullptr)
        return false;
    return true;
}

void Umbrella::Material::SetTexture(Umbrella::Texture2D* texture)
{
    _texture = texture;
}

Umbrella::Texture2D* Umbrella::Material::GetTexture()
{
    if (HasTexture())
        return _texture;
    return nullptr;
}

bool Umbrella::Material::HasTexture()
{
    if (_texture == nullptr)
        return false;
    return true;
}

void Umbrella::Material::SetBool(std::string name, bool value)
{
    if (_booleanValues.find(name) == _booleanValues.end())
        _booleanValues.insert({ name, value });
    else
        _booleanValues[name] = value;
}

void Umbrella::Material::SetInt(std::string name, int value)
{
    if (_intValues.find(name) == _intValues.end())
        _intValues.insert({ name, value });
    else
        _intValues[name] = value;
}

void Umbrella::Material::SetFloat(std::string name, float value)
{
    if (_floatValues.find(name) == _floatValues.end())
        _floatValues.insert({ name, value });
    else
        _floatValues[name] = value;
}

void Umbrella::Material::SetVec3(std::string name, glm::vec3 value)
{
    if (_vec3Values.find(name) == _vec3Values.end())
        _vec3Values.insert({ name, value });
    else
        _vec3Values[name] = value;
}

void Umbrella::Material::SetVec4(std::string name, glm::vec4 value)
{
    if (_vec4Values.find(name) == _vec4Values.end())
        _vec4Values.insert({ name, value });
    else
        _vec4Values[name] = value;
}

void Umbrella::Material::SetVec2(std::string name, glm::vec2 value)
{
    if (_vec2Values.find(name) == _vec2Values.end())
        _vec2Values.insert({ name, value });
    else
        _vec2Values[name] = value;
}

void Umbrella::Material::SetMatrix4(std::string name, glm::mat4 value)
{
    if (_matrix4Values.find(name) == _matrix4Values.end())
        _matrix4Values.insert({ name, value });
    else
        _matrix4Values[name] = value;
}

bool Umbrella::Material::GetBool(std::string name)
{
    if (_booleanValues.find(name) == _booleanValues.end())
        return false;
    else
        return _booleanValues[name];
}

int Umbrella::Material::GetInt(std::string name)
{
    if (_intValues.find(name) == _intValues.end())
        return 0;
    else
        return _intValues[name];
}

float Umbrella::Material::GetFloat(std::string name)
{
    if (_floatValues.find(name) == _floatValues.end())
        return 0.0;
    else
        return _floatValues[name];
}

glm::vec2 Umbrella::Material::GetVec2(std::string name)
{
    if (_vec2Values.find(name) == _vec2Values.end())
        return glm::vec2(0, 0);
    else
        return _vec2Values[name];
}

glm::vec3 Umbrella::Material::GetVec3(std::string name)
{
    if (_vec3Values.find(name) == _vec3Values.end())
        return glm::vec3(0, 0, 0);
    else
        return _vec3Values[name];
}

glm::vec4 Umbrella::Material::GetVec4(std::string name)
{
    if (_vec4Values.find(name) == _vec4Values.end())
        return glm::vec4(0, 0, 0, 0);
    else
        return _vec4Values[name];
}

glm::mat4 Umbrella::Material::GetMatrix4(std::string name)
{
    if (_matrix4Values.find(name) == _matrix4Values.end())
        return glm::mat4();
    else
        return _matrix4Values[name];
}

void Umbrella::Material::Use()
{
    if (!HasShader()) return;

    GetShader()->Use();

    for (auto value : _booleanValues)
        GetShader()->SetBool(value.first, value.second);

    for (auto value : _intValues)
        GetShader()->SetInt(value.first, value.second);

    for (auto value : _floatValues)
        GetShader()->SetFloat(value.first, value.second);

    for (auto value : _vec2Values)
        GetShader()->SetVec2(value.first, value.second);

    for (auto value : _vec3Values)
        GetShader()->SetVec3(value.first, value.second);

    for (auto value : _vec4Values)
        GetShader()->SetVec4(value.first, value.second);

    for (auto value : _matrix4Values)
        GetShader()->SetMatrix4(value.first, value.second);

    if (HasTexture())
        GetShader()->SetTexture(GetTexture());
}
