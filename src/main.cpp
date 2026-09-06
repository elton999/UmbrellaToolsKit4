#include <iostream>
#include <sstream>

#include "engine/core/debug/Log.h"
#include "engine/core/render_manager.h"
#include "engine/core/platform/graphics_wrappers/integrations/glwf_backend_integration.h"


RenderManager renderManager;


int main()
{
	renderManager = {};
	renderManager.BackendIntegration = new GLWF_BackendIntegration;
	renderManager.StartUp();

	while (renderManager.IsRunning())
	{
		renderManager.Run();
	}

	renderManager.ShutDown();
	return 0;
}
