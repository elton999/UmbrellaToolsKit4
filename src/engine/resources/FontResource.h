#pragma once
#include "ResourceContentIntegration.h"

namespace Umbrella
{
    class FontResource : public ResourceContentIntegration
    {
        public:
            void Load(std::string path) override;
            void Unload() override;
            bool HasLoaded();
    };
} // namespace Umbrella
