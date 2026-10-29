#include "SquareRenderComponent.h"
#include "../../scene/camera/Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

void Umbrella::SquareRenderComponent::OnStartUp()
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

    Umbrella::Mesh* mesh = new Umbrella::Mesh;
    Umbrella::Material* material = new Umbrella::Material;
    Umbrella::Shader* shader = new Umbrella::Shader;
    shader->Load(
        "#version 330 core\n"
        "layout (location = 0) in vec3 position;\n"
        "uniform mat4 model;\n"
        "uniform mat4 projection;\n"
        "uniform mat4 view;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = projection * view * model * vec4(position, 1.0);\n"
        "}\n",

        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 color;\n"
        "void main()\n"
        "{\n"
        "   FragColor = color;\n"
        "}\n");

    material->SetShader(shader);
    SetMaterial(material);
    material->SetVec4("color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    mesh->Load(square);
    SetMesh(mesh);
}

void Umbrella::SquareRenderComponent::OnUpdate(float deltaTime)
{
    if (!HasMaterial())
        return;
    if (!GetMaterial()->HasShader())
        return;
    if (!GetMaterial()->GetShader()->IsShaderReady())
        return;

    auto* camera = GetCamera();
    GetMaterial()->SetMatrix4("view", camera->GetCameraMatrix());
    GetMaterial()->SetMatrix4("projection", glm::ortho(0.0f, (float)camera->GetSize().x, (float)camera->GetSize().y, 0.0f, -1.0f, 1.0f));

    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 position = GetPosition() - glm::vec3(1, 1, 0);
    model = glm::translate(model, glm::vec3(position));
    model = glm::scale(model, glm::vec3(_size, 1.0f));

    GetMaterial()->SetMatrix4("model", model);
}

void Umbrella::SquareRenderComponent::SetSize(glm::vec2 size)
{
    _size = size;
}

glm::vec2 Umbrella::SquareRenderComponent::GetSize()
{
    return _size;
}
