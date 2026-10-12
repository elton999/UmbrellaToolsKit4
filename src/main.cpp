#include "engine/UmbrellaRoot.h"
#include "engine/scene/Scene.h"
#include "engine/render/component/SquareRenderComponent.h"


int main()
{
	Umbrella::UmbrellaRoot umbrellaToolsKit = {};

	umbrellaToolsKit.StartUp();
    Umbrella::Scene* mainScene = umbrellaToolsKit.SceneManager->CreateScene();

	umbrellaToolsKit.RenderWindow->BackendIntegration->SetWindowName("Game made with UmbrellaToolsKit4");

    GameObject* gameObject = mainScene->CreateGameObject();
    mainScene->AddGameObject(gameObject);
    mainScene->AddComponent<Umbrella::SquareRenderComponent>(gameObject);

	umbrellaToolsKit.Run();

	umbrellaToolsKit.ShutDown();

	return 0;
}
