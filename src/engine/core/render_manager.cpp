#include "RenderManager.h"
#include "debug/Log.h"


void RenderManager::StartUp()
{
	if (BackendIntegration == nullptr) return;
	BackendIntegration->Init();
}

void RenderManager::Run()
{
	if (BackendIntegration == nullptr) return;
	BackendIntegration->Update();
}

void RenderManager::ShutDown()
{
	if (BackendIntegration == nullptr) return;
	BackendIntegration->Close();
}

bool RenderManager::IsRunning()
{
	if (BackendIntegration == nullptr) return false;
	return BackendIntegration->IsRunning();
}
