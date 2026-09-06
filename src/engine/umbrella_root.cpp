#include "umbrella_root.h"

void  Umbrella::UmbrellaRoot::StartUp()
{
	RenderWindow = new Umbrella::RenderWindow;
	RenderWindow->BackendIntegration = new Umbrella::GLWF_BackendIntegration();
	RenderWindow->StartUp();
}

void Umbrella::UmbrellaRoot::Run()
{
	while (RenderWindow->IsRunning())
	{
		RenderWindow->Run();
	}
}

void Umbrella::UmbrellaRoot::ShutDown()
{
	RenderWindow->ShutDown();
}
