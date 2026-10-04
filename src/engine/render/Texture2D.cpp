#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>
#include "../core/debug/Log.h"

Umbrella::Texture2D::Texture2D() : Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
    glGenTextures(1, &ID);
    _width = 0;
    _height = 0;
}

int Umbrella::Texture2D::GetWidth()
{
    return _width;
}

int Umbrella::Texture2D::GetHight()
{
    return _height;
}

void Umbrella::Texture2D::Generate(unsigned int width, unsigned int height, unsigned char* data)
{
    _width = width;
    _height = height;

    glBindTexture(GL_TEXTURE_2D, ID);
    glTexImage2D(GL_TEXTURE_2D, 0, Internal_Format, width, height, 0, Image_Format, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Umbrella::Texture2D::Bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Umbrella::Texture2D::Load(std::string path)
{
    Internal_Format = GL_RGBA;
    Image_Format = GL_RGBA;

    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    if (!data)
    {
        Log::MsgError("Failed to load texture: " + path);
        return;
    }

    Generate(width, height, data);
    stbi_image_free(data);
}

void Umbrella::Texture2D::Unload()
{
    _width = 0;
    _height = 0;
    glDeleteTextures(1, &ID);
}
