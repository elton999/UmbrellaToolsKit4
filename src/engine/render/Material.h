#pragma once

#include <glm/glm.hpp>
#include <string>

namespace Umbrella
{
    class Shader;
    class Texture2D;

    class Material
    {
        private:
            Shader* _shader;
            Texture2D* _texture;

        public:

            void SetShader(Shader* shader);
            Shader* GetShader();
            bool HasShader();

            void SetTexture(Texture2D* texture);
            Texture2D* GetTexture();
            bool HasTexture();

            void SetBool(std::string name, bool value);
            void SetInt(std::string name, int value);
            void SetFloat(std::string name, float value);
            void SetVec3(std::string name, glm::vec3 value);
            void SetVec2(std::string name, glm::vec2 value);
            void SetMatrix4(std::string name, glm::mat4 value);

            bool GetBool(std::string name);
            int GetInt(std::string name);
            float GetFloat(std::string name);
            glm::vec3 GetVec3(std::string name);
            glm::vec2 GetVec2(std::string name);
            glm::mat4 GetMatrix4(std::string name);
    };
}
