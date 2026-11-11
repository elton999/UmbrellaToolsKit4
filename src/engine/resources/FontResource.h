#pragma once
#include "ResourceContentIntegration.h"
#include <glm/glm.hpp>
#include <map>

namespace Umbrella
{
    struct Character
    {
            unsigned int TextureID;
            glm::ivec2 Size;
            glm::ivec2 Bearing;
            unsigned int Advanced;
    };

    class FontResource : public ResourceContentIntegration
    {
        private:
            std::map<char, Character> _characters;

        public:
            void Load(std::string path) override;
            void Unload() override;
            bool HasLoaded();
    };
} // namespace Umbrella
