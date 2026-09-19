#pragma once

#include "core/debug/Log.h"
#include "core/RenderWindow.h"
#include "core/Timer.h"
#include "scene/SceneManager.h"
#include "resources/ResourceManager.h"
#include "core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"

namespace Umbrella
{
	class UmbrellaRoot
	{

		public:
			Umbrella::RenderWindow* RenderWindow;
            Umbrella::ResourceManager* ResourceManager;
			Umbrella::Timer* Timer;
            Umbrella::SceneManager* SceneManager;
		
			void StartUp();
			void Run();
			void ShutDown();
	};
};
