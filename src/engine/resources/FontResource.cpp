#include "FontResource.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../core/debug/Log.h"
#include <glad/glad.h>

void Umbrella::FontResource::Load(std::string path)
{
    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        Log::MsgError("FREETYPE: Could not init FreeType Library");
        return;
    }

    FT_Face face;
    if (FT_New_Face(ft, path.c_str(), 0, &face))
    {
        Log::MsgError("FREETYPE: Failed to load font");
        return;
    }

    _characters = {};

    FT_Set_Pixel_Sizes(face, 0, 48);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
    {
        Log::MsgError("FREETYTPE: Failed to load Glyph");
        return;
    }

    for (unsigned char c = 0; c < 128; c++)
    {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            Log::MsgError("Failed to load Glyph");
            continue;
        }

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        Umbrella::Character character =
            {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                glm::ivec1(face->glyph->advance.x).x};

        _characters.insert(std::pair<char, Umbrella::Character>(c, character));
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    _hasLoaded = true;
}

void Umbrella::FontResource::Unload()
{
    if (!HasLoaded())
        return;

    _hasLoaded = false;
    _characters.clear();
}

bool Umbrella::FontResource::HasLoaded()
{
    return _hasLoaded;
}

Umbrella::Character Umbrella::FontResource::GetCharacter(char c)
{
    for (auto chars : _characters)
    {
        if (chars.first == c)
        {
            return chars.second;
        }
    }

    return _characters['@'];
}
