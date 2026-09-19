#pragma once

#include "../UmbrellaRoot.h"

namespace Umbrella
{
    class RenderManager
    {

        public:
            RenderManager(UmbrellaRoot* root);

            void StartUp();
            void Run();
            void ShutDown();
    };
}
