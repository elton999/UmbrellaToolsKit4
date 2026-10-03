#pragma once

#include <vector>
#include <glm/glm.hpp>

namespace Umbrella
{
    class Mesh
    {
        private:
            std::vector<glm::vec3>* _mVertices;
            std::vector<glm::vec3>* _mVerticesColors;
            std::vector<glm::vec2>* _mTexCoords;

            bool _mHasShader = false;

        protected:
            unsigned int mVBO, mVAO;
            unsigned int _mVertexCount;

        public:
            void Load(std::vector<glm::vec3>& vertices);
            void Load(std::vector<glm::vec3>& vertices, std::vector<glm::vec3>& colors, std::vector<glm::vec2>& texCoords);

            std::vector<glm::vec3>* GetVertices();
            std::vector<glm::vec3>* GetVerticesColors();
            std::vector<glm::vec2>* GetTexCoords();
    };
}
