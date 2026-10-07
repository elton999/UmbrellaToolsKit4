#include "Mesh.h"
#include <glad/glad.h>

void Umbrella::Mesh::Load(std::vector<glm::vec3>& vertices)
{
    _vertices = &vertices;
    _vertexCount = vertices.size();
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Umbrella::Mesh::Load(std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& colors, std::vector<glm::vec2>& texCoords)
{
    _vertices = &vertices;
    _verticesColors = &colors;
    _texCoords = &texCoords;

    _vertexCount = vertices.size();

    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);

    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);

    size_t verticesSize = vertices.size() * sizeof(glm::vec3);
    size_t colorsSize = colors.size() * sizeof(glm::vec3);
    size_t texCoordsSize = texCoords.size() * sizeof(glm::vec2);

    glBufferData(GL_ARRAY_BUFFER, verticesSize + colorsSize + texCoordsSize, nullptr, GL_STATIC_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER, 0, verticesSize, vertices.data());
    glBufferSubData(GL_ARRAY_BUFFER, verticesSize, colorsSize, colors.data());
    glBufferSubData(GL_ARRAY_BUFFER, verticesSize + colorsSize, texCoordsSize, texCoords.data());

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)verticesSize);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)(verticesSize + colorsSize));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

std::vector<glm::vec3>* Umbrella::Mesh::GetVertices()
{
    return nullptr;
}

std::vector<glm::vec3>* Umbrella::Mesh::GetVerticesColors()
{
    return nullptr;
}

std::vector<glm::vec2>* Umbrella::Mesh::GetTexCoords()
{
    return nullptr;
}

int Umbrella::Mesh::GetVerticesCount()
{
    return 0;
}

int Umbrella::Mesh::GetVerticesColorsCount()
{
    return 0;
}

int Umbrella::Mesh::GetTexCoordsCount()
{
    return 0;
}
