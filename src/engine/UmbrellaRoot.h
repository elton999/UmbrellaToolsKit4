#pragma once

#include "core/RenderWindow.h"
#include "core/Timer.h"
#include "core/debug/Log.h"
#include "core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
#include "render/RenderManager.h"
#include "resources/ResourceManager.h"
#include "scene/SceneManager.h"
#include "scene/camera/CameraManager.h"

namespace Umbrella
{
    class UmbrellaRoot
    {
        public:
            Umbrella::RenderWindow* RenderWindow;
            Umbrella::ResourceManager* ResourceManager;
            Umbrella::Timer* Timer;
            Umbrella::SceneManager* SceneManager;
            Umbrella::RenderManager* RenderManager;
            Umbrella::CameraManager* CameraManager;

            void StartUp();
            void Run();
            void ShutDown();
    };
}; // namespace Umbrella
