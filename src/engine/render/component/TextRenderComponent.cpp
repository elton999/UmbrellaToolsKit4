#include "TextRenderComponent.h"
#include "../Mesh.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "resources/FontResource.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include "../../core/debug/Log.h"
#include "../Material.h"
#include "../Shader.h"
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

void Umbrella::TextRenderComponent::OnStartUp()
{
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
        "layout(location = 0) in vec3 position;\n"
        "layout(location = 1) in vec3 vertexcolor;\n"
        "layout(location = 2) in vec2 texcoords;\n"
        "out vec2 TexCoords;\n"
        "uniform mat4 projection;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = projection * vec4(position, 1.0);\n"
        "   TexCoords = texcoords;\n"
        "}\n",

        "#version 330 core\n"
        "in vec2 TexCoords;\n"
        "out vec4 color;\n"
        "uniform sampler2D text;\n"
        "uniform vec3 textColor;\n"
        "void main()\n"
        "{\n"
        "   float alpha = texture(text, TexCoords).r;\n"
        "   color = vec4(textColor, alpha);\n"
        "}\n");

    SetMaterial(material);
    GetMaterial()->SetShader(shader);
    SetMesh(mesh);
}

void Umbrella::TextRenderComponent::SetFont(Umbrella::FontResource* font)
{
    if (font == nullptr)
        return;
    if (!font->HasLoaded())
        return;

    _font = font;
    if (HasMaterial())
        return;
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
    if (!HasText())
    {
        return "";
    }

    return _text;
}

bool Umbrella::TextRenderComponent::HasText()
{
    return !_text.empty();
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

    auto* camera = GetCamera();
    glm::mat4 projection = glm::ortho(0.0f, (float)camera->GetSize().x, (float)camera->GetSize().y, 0.0f, -1.0f, 1.0f);

    glm::vec3 position = GetPosition();

    std::string::const_iterator c;
    std::string text = GetText();
    for (c = text.begin(); c != text.end(); c++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        Umbrella::Character ch = GetFont()->GetCharacter(*c);
        int height = ch.Size.y;
        int width = ch.Size.x;

        glm::vec2 scale = {1, 1};

        float xpos = ch.Bearing.x * scale.x;
        float ypos = (ch.Size.y - ch.Bearing.y) * scale.y;

        float w = ch.Size.x * scale.x;
        float h = ch.Size.y * scale.y;

        model = glm::translate(model, glm::vec3(position));
        glm::vec2 baseSize = {ch.Size.x, ch.Size.y};
        glm::vec2 finalSize = baseSize * scale;

        model = glm::scale(model, glm::vec3(finalSize, 1.0));

        float texY = 1.0f - (float)height / ch.Size.y;
        glm::vec2 texOffset = glm::vec2(ch.Size.x / (float)ch.Size.x, texY);
        glm::vec2 texScale = glm::vec2(width / ch.Size.x, height / ch.Size.y);

        GetMaterial()->SetMatrix4("projection", projection * camera->GetCameraMatrix() * model);
        GetMaterial()->SetVec3("textColor", {1, 1, 1});

        GetMaterial()->Use();
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        GetMesh()->Bind();
    }
}
