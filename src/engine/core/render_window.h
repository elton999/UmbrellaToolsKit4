#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "platform/graphics_wrappers/graphic_backend.h"
#include <memory>


namespace Umbrella{
	class RenderWindow
	{
		public:
			GraphicBackend* BackendIntegration;

			void StartUp();
			void Run();
			void ShutDown();

			bool IsRunning();
	};
};
