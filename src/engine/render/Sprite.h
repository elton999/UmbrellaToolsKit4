#pragma once
#include "Texture2D.h"

namespace Umbrella
{
    class Sprite
    {
        public:
            std::string Path;

            unsigned int Width = 0;
            unsigned int Height = 0;

            int X = 0;
            int Y = 0;
    };
}
