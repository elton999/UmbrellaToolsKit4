#pragma once

namespace Umbrella
{
	class Timer
	{
		private:
			float _currentTime;
			float _detalTime;
			float _lastTime;

		public:
			void StartUp();
			void Run();
			void ShutDown();

			float GetDelta();
			float GetDataDelta();
	};
};
