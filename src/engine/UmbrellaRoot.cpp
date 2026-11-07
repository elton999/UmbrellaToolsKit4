#include "UmbrellaRoot.h"
#include "core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
#include "core/platform/input/GlfwInputIntegration.h"
#include "io/input/InputHandler.h"
#include "scene/camera/CameraManager.h"

void Umbrella::UmbrellaRoot::StartUp()
{
    RenderWindow = new Umbrella::RenderWindow;
    auto* glfwBackend = new Umbrella::GLWF_BackendIntegration;
    RenderWindow->BackendIntegration = glfwBackend;
    ResourceManager = new Umbrella::ResourceManager;
    RenderWindow->StartUp();
    Timer = new Umbrella::Timer(RenderWindow->BackendIntegration);
    SceneManager = new Umbrella::SceneManager(this);
    RenderManager = new Umbrella::RenderManager(this);
    CameraManager = new Umbrella::CameraManager;
    auto* glfwInput = new Umbrella::GlfwInputIntegration(glfwBackend->GetWindow());
    InputHandler = new Umbrella::InputHandler(glfwInput);

    ResourceManager->StartUp();
    Timer->StartUp();
    SceneManager->StartUp();
    RenderManager->StartUp();
    CameraManager->StartUp();
    InputHandler->StartUp();
}

void Umbrella::UmbrellaRoot::Run()
{
    while (RenderWindow->IsRunning())
    {
        Timer->Run();
        RenderWindow->Run();
        InputHandler->Run();
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
    CameraManager->ShutDown();
    InputHandler->ShutDown();
}
