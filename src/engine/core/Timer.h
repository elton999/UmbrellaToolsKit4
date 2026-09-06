#pragma once
#include "platform/graphics_wrappers/GraphicBackend.h"

namespace Umbrella
{
	class Timer
	{
		private:
			float _currentTime;
			float _detalTime;
			float _lastTime;
			GraphicBackend* _graphicBackend;

		public:
			Timer(GraphicBackend* graphicBackend)
			{
				_graphicBackend = graphicBackend;
			}

			void StartUp();
			void Run();
			void ShutDown();

			float GetDelta();
			float GetDataDelta();
	};
};
