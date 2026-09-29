#pragma once

namespace Umbrella
{
    class Shader;

    class Material
    {
        private:
            Shader* _shader;

        public:

            void SetShader(Shader* shader);
            Shader* GetShader();
            bool HasShader();
    };
}
