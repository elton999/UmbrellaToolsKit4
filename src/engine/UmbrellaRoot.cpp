#include "UmbrellaRoot.h"

void  Umbrella::UmbrellaRoot::StartUp()
{
	RenderWindow = new Umbrella::RenderWindow;
	RenderWindow->BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    ResourceManager = new Umbrella::ResourceManager;
	Timer = new Umbrella::Timer(RenderWindow->BackendIntegration);
    SceneManager = new Umbrella::SceneManager(this);
    RenderManager = new Umbrella::RenderManager(this);

	RenderWindow->StartUp();
    ResourceManager->StartUp();
	Timer->StartUp();
    SceneManager->StartUp();
    RenderManager->StartUp();
}

void Umbrella::UmbrellaRoot::Run()
{
	while (RenderWindow->IsRunning())
	{
		Timer->Run();
		RenderWindow->Run();
        SceneManager->Run();

        RenderManager->Run();
        RenderWindow->BackendIntegration->ClearScreen();
	}
}

void Umbrella::UmbrellaRoot::ShutDown()
{
	Timer->ShutDown();
    SceneManager->ShutDown();
    RenderManager->ShutDown();
    ResourceManager->ShutDown();
	RenderWindow->ShutDown();
}
