#include "TextRenderComponent.h"
#include "../Mesh.h"
#include "resources/FontResource.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../Material.h"
#include "../Shader.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

void Umbrella::TextRenderComponent::SetFont(Umbrella::FontResource* font)
{
    if (font == nullptr)
        return;
    if (!font->HasLoaded())
        return;

    _font = font;
    if (HasMaterial())
        return;

    std::vector<glm::vec3> square =
        {
            glm::vec3{0.0f, 1.0f, 0.0f},
            glm::vec3{1.0f, 1.0f, 0.0f},
            glm::vec3{0.0f, 0.0f, 0.0f},

            glm::vec3{1.0f, 1.0f, 0.0f},
            glm::vec3{1.0f, 0.0f, 0.0f},
            glm::vec3{0.0f, 0.0f, 0.0f},
        };

    std::vector<glm::vec2> texCoords =
        {
            glm::vec2{0.0f, 1.0f},
            glm::vec2{1.0f, 1.0f},
            glm::vec2{0.0f, 0.0f},

            glm::vec2{1.0f, 1.0f},
            glm::vec2{1.0f, 0.0f},
            glm::vec2{0.0f, 0.0f},
        };

    std::vector<glm::vec3> colors =
        {
            glm::vec3{1.0f, 0.0f, 0.0f},
            glm::vec3{0.0f, 1.0f, 0.0f},
            glm::vec3{0.0f, 0.0f, 1.0f},

            glm::vec3{1.0f, 1.0f, 0.0f},
            glm::vec3{0.0f, 1.0f, 1.0f},
            glm::vec3{1.0f, 0.0f, 1.0f},
        };

    Umbrella::Mesh* mesh = new Umbrella::Mesh;

    Umbrella::Material* material = new Umbrella::Material;
    Umbrella::Shader* shader = new Umbrella::Shader;

    mesh->Load(square, colors, texCoords);

    shader->Load(
        "#version 330 core\n"
        "layout (location = 0) in vec4 vertex;\n"
        "out vec2 TextCoords;\n"
        "uniform mat4 projection;\n"
        "void main()\n"
        "{\n"
        "gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n"
        "TextCoords = vertex.zw;\n"
        "}\n",

        "#version 330 core\n"
        "in vec2 TexCoords;\n"
        "out vec4 color;\n"
        "uniform sampler2D text;\n"
        "uniform vec3 textColor;\n"
        "void main()\n"
        "{\n"
        "vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
        "color = vec4(textColor, 1.0) * sampled;"
        "}\n");

    SetMaterial(material);
    GetMaterial()->SetShader(shader);
    SetMesh(mesh);
}

bool Umbrella::TextRenderComponent::HasFont()
{
    return _font != nullptr;
}

void Umbrella::TextRenderComponent::SetFontSize(float fontSize)
{
    _fontSize = fontSize;
}

float Umbrella::TextRenderComponent::GetFontSize()
{
    return _fontSize;
}

void Umbrella::TextRenderComponent::SetText(std::string text)
{
    _text = text;
}

std::string Umbrella::TextRenderComponent::GetText()
{
    if (_text.empty() == 0)
    {
        return "";
    }

    return _text;
}

Umbrella::FontResource* Umbrella::TextRenderComponent::GetFont()
{
    return _font;
}

void Umbrella::TextRenderComponent::Draw()
{
    if (!HasMaterial())
        return;
    if (!GetMaterial()->HasShader())
        return;
    if (!GetMaterial()->GetShader()->IsShaderReady())
        return;
    if (!HasFont())
        return;

    if (GetText().empty() == 0)
        return;

    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);

    GetMaterial()->SetMatrix4("projection", projection);
    GetMaterial()->Use();

    std::string::const_iterator c;
    std::string text = GetText();
    for (c = text.begin(); c != text.end(); c++)
    {
        Umbrella::Character ch = GetFont()->GetCharacter(*c);
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        GetMesh()->Bind();
    }
}
