#include "Shader.h"
#include "../core/debug/Log.h"
#include "../core/platform/FileSystem.h"

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void Umbrella::Shader::Load(std::string path)
{
    std::string vertexCode = FileSystem::Read(path + ".vert");
    std::string fragmentCode = FileSystem::Read(path + ".frag");

    if (!vertexCode.empty() && !fragmentCode.empty())
    {
        Load(vertexCode.c_str(), fragmentCode.c_str());
    }
    else
    {
        Log::MsgError("Shader not found: " + path);
    }
}

void Umbrella::Shader::Load(const char* vertexCode, const char* fragmentCode)
{
    unsigned int vertex, fragment;
    _isReady = true;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);
    if (!CheckCompileErrors(vertex, "VERTEX"))
    {
        _isReady = false;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, NULL);
    glCompileShader(fragment);
    if (!CheckCompileErrors(fragment, "FRAGMENT"))
    {
        _isReady = false;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    if (!CheckCompileErrors(ID, "PROGRAM"))
    {
        _isReady = false;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

void Umbrella::Shader::Unload()
{
    glDeleteProgram(ID);
    _isReady = false;
}

void Umbrella::Shader::Use()
{
    glUseProgram(ID);
}

void Umbrella::Shader::SetBool(std::string name, bool value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (GLint)value);
}

void Umbrella::Shader::SetInt(std::string name, int value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Umbrella::Shader::SetFloat(std::string name, float value)
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Umbrella::Shader::SetVec3(std::string name, glm::vec3 value)
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Umbrella::Shader::SetVec2(std::string name, glm::vec2 value)
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Umbrella::Shader::SetMatrix4(std::string name, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

bool Umbrella::Shader::CheckCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            Log::MsgError("SHADER_COMPILATION_ERROR of type: " + type + "\n"+
            infoLog + "\n ------------------------------------------------------- ");
            return false;
        }

        return true;
    }

    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader, 1024, NULL, infoLog);
        Log::MsgError("SHADER_COMPILATION_ERROR of type: " + type + "\n" +
        infoLog + "\n ------------------------------------------------------- ");
        return false;
    }

    return true;
}

bool Umbrella::Shader::IsShaderReady()
{
    return _isReady;
}
