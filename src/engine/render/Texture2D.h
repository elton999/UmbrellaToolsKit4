#pragma once

namespace Umbrella
{
    class Texture2D
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

            int GetWidth();
            int GetHight();

            void Generate(unsigned int width, unsigned int height, unsigned char* data);
            void Bind();
    };
}
