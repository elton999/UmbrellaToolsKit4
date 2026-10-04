#pragma once

#include "../resources/ResourceContentIntegration.h"

namespace Umbrella
{
    class Texture2D : public ResourceContentIntegration
    {
        private:
            unsigned int _mHeight, _mWidth;

        public:
            Texture2D();
            unsigned int ID;
            unsigned int Internal_Format;
            unsigned int Image_Format;
            unsigned int Wrap_S;
            unsigned int Wrap_T;
            unsigned int Filter_Min; // filtering mode if texture pixels < screen pixels
            unsigned int Filter_Max; // filtering mode if texture pixels > screen pixels

            void Load(std::string path) override;
            void Unload() override;

            int GetWidth();
            int GetHight();

            void Generate(unsigned int width, unsigned int height, unsigned char* data);
            void Bind();
    };
}
