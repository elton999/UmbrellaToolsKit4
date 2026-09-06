#include "UmbrellaRoot.h"

void  Umbrella::UmbrellaRoot::StartUp()
{
	RenderWindow = new Umbrella::RenderWindow;
	RenderWindow->BackendIntegration = new Umbrella::GLWF_BackendIntegration;
	Timer = new Umbrella::Timer(RenderWindow->BackendIntegration);

	RenderWindow->StartUp();
	Timer->StartUp();
}

void Umbrella::UmbrellaRoot::Run()
{
	while (RenderWindow->IsRunning())
	{
		Timer->Run();
		RenderWindow->Run();
	}
}

void Umbrella::UmbrellaRoot::ShutDown()
{
	RenderWindow->ShutDown();
	Timer->ShutDown();
}
