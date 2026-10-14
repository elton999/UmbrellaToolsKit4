#pragma once

#include "../resources/ResourceContentIntegration.h"
#include "../render/Texture2D.h"

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
            bool _isReady;

            bool CheckCompileErrors(unsigned int shader, std::string type);

        public:
            unsigned int ID;

            void Load(std::string path) override;
            void Load(const char* vertexCode, const char* fragmentCode);
            void Unload() override;
            bool IsShaderReady();

            void Use();

            void SetBool(const std::string &name, const bool &value) const;
            void SetInt(const std::string &name, const int &value) const;
            void SetFloat(const std::string &name, const float &value) const;
            void SetVec2(const std::string &name, const glm::vec2 &value) const;
            void SetVec3(const std::string &name, const glm::vec3 &value) const;
            void SetVec4(const std::string &name, const glm::vec4 &value) const;
            void SetMatrix4(const std::string &name, const glm::mat4 &value) const;
            void SetTexture(Texture2D* texture);
    };
}
