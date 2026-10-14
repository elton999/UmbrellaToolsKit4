#pragma once

#include "MeshRenderComponent.h"
#include "../Mesh.h"
#include "../Material.h"
#include "../Shader.h"
#include <vector>
#include <glm/glm.hpp>

namespace Umbrella
{
    class SquareRenderComponent : public MeshRenderComponent
    {
        public:
            SquareRenderComponent(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : MeshRenderComponent(gameObjectId, scene, componentId)
            {}

            void OnStartUp() override
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
                    "void main()\n"
                    "{\n"
                    "   gl_Position = vec4(position, 1.0);\n"
                    "}\n",

                    "#version 330 core\n"
                    "out vec4 FragColor;\n"
                    "uniform vec4 color;\n"
                    "void main()\n"
                    "{\n"
                    "   FragColor = color;\n"
                    "}\n"
                    );

                material->SetShader(shader);
                SetMaterial(material);
                material->SetVec4("color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

                mesh->Load(square);
                SetMesh(mesh);
            }

            void OnUpdate(float deltaTime) override
            {
            }
    };
}
