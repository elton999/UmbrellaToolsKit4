#pragma once

#include <iostream>
#include <sstream>

#include "core/debug/Log.h"
#include "core/render_window.h"
#include "core/platform/graphics_wrappers/integrations/glwf_backend_integration.h"

namespace Umbrella
{
	class UmbrellaRoot
	{

		public:
			Umbrella::RenderWindow *RenderWindow;
		
			void StartUp();
			void Run();
			void ShutDown();
	};
};
