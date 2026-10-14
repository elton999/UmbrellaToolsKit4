#include "SpriteRenderComponent.h"

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
        "out vec4 color;\n"
        "uniform sampler2D image;\n"
        "uniform vec3 spriteColor;\n"
        "// texOffset: (offsetX, offsetY) in normalized coords\n"
        "// texScale:  (scaleX, scaleY) in normalized coords\n"
        "uniform vec2 texOffset;\n"
        "uniform vec2 texScale;\n"
        "void main()\n"
        "{\n"
        "    vec2 uv = texOffset + texScale * TexCoords;\n"
        "    color = vec4(spriteColor, 1.0) * texture(image, uv);\n"
        "}\n";


    Umbrella::Mesh* mesh = new Umbrella::Mesh;
    Umbrella::Material* material = new Umbrella::Material;
    Umbrella::Shader* shader = new Umbrella::Shader;

    shader->Load(vertexCode, fragmentCode);

    material->SetShader(shader);
    SetMaterial(material);

    mesh->Load(square, colors, texCoords);
    SetMesh(mesh);

}

void Umbrella::SpriteRenderComponent::OnUpdate(float deltaTime)
{
}
