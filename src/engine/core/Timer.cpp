#include "Timer.h"
#include "debug/Log.h"
#include <string>

void Umbrella::Timer::StartUp()
{
	_currentTime = _graphicBackend->GetTime();
}

void Umbrella::Timer::Run()
{
	_currentTime = _graphicBackend->GetTime();
	_detalTime = _currentTime - _lastTime;
	_lastTime = _currentTime;
}

void Umbrella::Timer::ShutDown()
{

}

float Umbrella::Timer::GetDelta()
{
	return _detalTime;
}

float Umbrella::Timer::GetDataDelta()
{
	return _detalTime;
}
