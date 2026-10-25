#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>
#include "../core/debug/Log.h"

Umbrella::Texture2D::Texture2D()
{
    glGenTextures(1, &this->ID);
    _height = _width = 0;
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

    Bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Umbrella::Texture2D::Bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Umbrella::Texture2D::Load(std::string path)
{
    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    if (!data)
    {
        Log::MsgError("Failed to load texture: " + path);
        return;
    }

    Generate(width, height, data);
    stbi_image_free(data);
    Log::Msg("load image");
}

void Umbrella::Texture2D::Unload()
{
    _width = 0;
    _height = 0;
    glDeleteTextures(1, &ID);
}
