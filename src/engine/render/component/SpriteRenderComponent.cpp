#include "SpriteRenderComponent.h"
#include <glm/gtc/matrix_transform.hpp>

void Umbrella::SpriteRenderComponent::OnStartUp()
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

    const char* vertexCode =
        "#version 330 core\n"
        "layout(location = 0) in vec3 position;\n"
        "layout(location = 1) in vec3 vertexColor;\n"
        "layout(location = 2) in vec2 texCoords;\n"
        "out vec2 TexCoords;\n"
        "uniform mat4 model;\n"
        "uniform mat4 projection;\n"
        "void main() {\n"
        "    TexCoords = texCoords;\n"
        "    gl_Position = projection * model * vec4(position, 1.0);\n"
        "}\n";

    const char* fragmentCode =
        "#version 330 core\n"
        "in vec2 TexCoords;\n"
        "out vec4 colorOut;\n"
        "uniform sampler2D image;\n"
        "uniform vec4 color;\n"
        "uniform float transparence;\n"
        "// texOffset: (offsetX, offsetY) in normalized coords\n"
        "// texScale:  (scaleX, scaleY) in normalized coords\n"
        "uniform vec2 texOffset;\n"
        "uniform vec2 texScale;\n"
        "void main()\n"
        "{\n"
        "    vec2 uv = texOffset + texScale * TexCoords;\n"
        "    colorOut = color * texture(image, uv);\n"
        "    float transpareceOut = max(0.0, colorOut.w - transparence);\n"
        "    colorOut = vec4(colorOut.x, colorOut.y, colorOut.z, transpareceOut);\n"
        "}\n";


    Umbrella::Mesh* mesh = new Umbrella::Mesh;
    Umbrella::Material* material = new Umbrella::Material;
    Umbrella::Shader* shader = new Umbrella::Shader;

    mesh->Load(square, colors, texCoords);
    shader->Load(vertexCode, fragmentCode);

    material->SetShader(shader);
    shader->SetInt("image", 0);
    SetMaterial(material);

    SetMesh(mesh);
}

void Umbrella::SpriteRenderComponent::OnUpdate(float deltaTime)
{
    if (!HasMaterial()) return;
    if (!GetMaterial()->HasShader()) return;
    if (!GetMaterial()->GetShader()->IsShaderReady()) return;

    GetMaterial()->SetMatrix4("projection", glm::ortho(0.0f, 1280.0f, 720.0f, 0.0f, -1.0f, 1.0f));
    GetMaterial()->SetVec2("scale", GetScale());
    GetMaterial()->SetFloat("transparence", 1.0f - GetTransparence());
    GetMaterial()->SetVec4("color", GetSpriteColor());
    GetMaterial()->SetVec4("fillColor", GetFillSpriteColor());

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(GetPosition()));

    int width = 0;
    int height = 0;

    if (HasSprite())
    {
        if (_sprite->Width == 0 || _sprite->Height == 0)
        {
            width = _texture->GetWidth();
            height = _texture->GetHight();
        }
        else
        {
            width = _sprite->Width;
            height = _sprite->Height;
        }
    }

    glm::vec2 baseSize = glm::vec2((float)width, (float)height);
    glm::vec2 finalSize = baseSize * _scale;

    model = glm::translate(model, glm::vec3(0.5f * finalSize.x, 0.5f * finalSize.y, 0.0f));
    model = glm::rotate(model, GetRotation2D(), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * finalSize.x, -0.5f * finalSize.y, 0.0f));

    model = glm::scale(model, glm::vec3(finalSize, 1.0f));

    GetMaterial()->SetMatrix4("model", model);

    if (HasSprite())
    {
        float texY = 1.0f - (_sprite->Y + height) / (float)_texture->GetHight();
        glm::vec2 texOffset = glm::vec2(_sprite->X / (float)_texture->GetWidth(), texY);
        glm::vec2 texScale = glm::vec2( width / (float)_texture->GetWidth(), height / (float)_texture->GetHight());

        GetMaterial()->SetVec2("texOffset", texOffset);
        GetMaterial()->SetVec2("texScale", texScale);
        GetMaterial()->SetTexture(_texture);
    }
}

void Umbrella::SpriteRenderComponent::SetScale(float scale)
{
    _scale = glm::vec2(scale, scale);
}

void Umbrella::SpriteRenderComponent::SetScale(glm::vec2 scale)
{
    _scale = scale;
}

glm::vec2 Umbrella::SpriteRenderComponent::GetScale()
{
    return _scale;
}

void Umbrella::SpriteRenderComponent::SetTransparence(float transparence)
{
    _transparence = transparence;
}

float Umbrella::SpriteRenderComponent::GetTransparence()
{
    return _transparence;
}

void Umbrella::SpriteRenderComponent::SetSpriteColor(glm::vec4 color)
{
    _spriteColor = color;
}

glm::vec4 Umbrella::SpriteRenderComponent::GetSpriteColor()
{
    return _spriteColor;
}

void Umbrella::SpriteRenderComponent::SetFillSpriteColor(glm::vec4 color)
{
    _fillSpriteColor = color;
}

glm::vec4 Umbrella::SpriteRenderComponent::GetFillSpriteColor()
{
    return _fillSpriteColor;
}

void Umbrella::SpriteRenderComponent::SetRotation2D(float rotation)
{
    glm::vec3 rotationValue = GetRotation();
    SetRotation(glm::vec3(rotationValue.x, rotation, rotationValue.z));
}

float Umbrella::SpriteRenderComponent::GetRotation2D()
{
    return GetRotation().y;
}

void Umbrella::SpriteRenderComponent::SetSprite(Sprite* sprite)
{
    _sprite = sprite;
    _texture = GetScene()->GetSceneManager()->GetUmbrellaRoot()->ResourceManager->Load<Texture2D>(sprite->Path);
}

Umbrella::Sprite* Umbrella::SpriteRenderComponent::GetSprite()
{
    if (HasSprite())
        return _sprite;
    return nullptr;
}

bool Umbrella::SpriteRenderComponent::HasSprite()
{
    return _sprite != nullptr;
}
