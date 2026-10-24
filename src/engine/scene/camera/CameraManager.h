#pragma once

#include "Camera.h"
#include <map>
#include <string>

namespace Umbrella
{
    class CameraManager
    {
        private:
            std::map<std::string, Camera*> _camerasByLayer;

        public:
            void StartUp();
            void ShutDown();

            void SetCamera(std::string layer, Camera* camera);
            Camera* GetCamera(std::string layer);
            Camera* CreateCamera();
    };
} // namespace Umbrella
