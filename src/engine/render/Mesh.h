#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace Umbrella
{
    class Mesh
    {
        private:
            std::vector<glm::vec3>* _vertices;
            std::vector<glm::vec3>* _verticesColors;
            std::vector<glm::vec2>* _texCoords;

        protected:
            unsigned int mVBO, mVAO;
            unsigned int _vertexCount;

        public:
            void Load(std::vector<glm::vec3>& vertices);
            void Load(std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& colors, std::vector<glm::vec2>& texCoords);

            std::vector<glm::vec3>* GetVertices();
            std::vector<glm::vec3>* GetVerticesColors();
            std::vector<glm::vec2>* GetTexCoords();

            int GetVerticesCount();
            int GetVerticesColorsCount();
            int GetTexCoordsCount();

            int GetVBO();
            int GetVAO();
            void Bind();
    };
} // namespace Umbrella
