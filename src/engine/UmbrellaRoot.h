#pragma once

#include <iostream>
#include <sstream>

#include "core/debug/Log.h"
#include "core/RenderWindow.h"
#include "core/Timer.h";
#include "core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"

namespace Umbrella
{
	class UmbrellaRoot
	{

		public:
			Umbrella::RenderWindow *RenderWindow;
			Umbrella::Timer *Timer;
		
			void StartUp();
			void Run();
			void ShutDown();
	};
};
