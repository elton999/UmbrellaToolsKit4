#include <iostream>
#include <sstream>

#include "engine/core/debug/Log.h"
#include "engine/core/platform/graphics_wrappers/RenderManager.h"

RenderManager _renderManager;

int main()
{
	_renderManager.StartUp();

	while (_renderManager.IsRunning())
	{
		_renderManager.Run();
	}

	_renderManager.ShutDown();
	return 0;
}
