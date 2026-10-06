#pragma once

#include "../resources/ResourceContentIntegration.h"

#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Umbrella
{
    class Shader : public ResourceContentIntegration
    {
        private:
            void checkCompileErrors(unsigned int shader, std::string type);

        public:
            unsigned int ID;

            void Load(std::string path) override;
            void Load(const char* vertexCode, const char* fragmentCode);
            void Unload() override;

            void Use();

            void SetBool(std::string name, bool value);
            void SetInt(std::string name, int value) ;
            void SetFloat(std::string name, float value);
            void SetVec3(std::string name, glm::vec3 value);
            void SetVec2(std::string name, glm::vec2 value);
            void SetMatrix4(std::string name, glm::mat4 value);
    };
}
