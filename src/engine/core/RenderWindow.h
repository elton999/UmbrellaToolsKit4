#pragma once

#include <string>
#include "platform/graphics_wrappers/GraphicBackend.h"
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
