#include "RenderWindow.h"
#include "debug/Log.h"


void Umbrella::RenderWindow::StartUp()
{
	if (BackendIntegration == nullptr) return;
	BackendIntegration->Init();
}

void Umbrella::RenderWindow::Run()
{
	if (BackendIntegration == nullptr) return;
	BackendIntegration->Update();
}

void Umbrella::RenderWindow::ShutDown()
{
	if (BackendIntegration == nullptr) return;
	BackendIntegration->Close();
}

bool Umbrella::RenderWindow::IsRunning()
{
	if (BackendIntegration == nullptr) return false;
	return BackendIntegration->IsRunning();
}
