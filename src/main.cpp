#include "engine/UmbrellaRoot.h"
#include "engine/scene/Scene.h"
#include "engine/render/component/SpriteRenderComponent.h"
#include "engine/render/component/SquareRenderComponent.h"

int main()
{
	Umbrella::UmbrellaRoot umbrellaToolsKit = {};

	umbrellaToolsKit.StartUp();
    Umbrella::Scene* mainScene = umbrellaToolsKit.SceneManager->CreateScene();
    umbrellaToolsKit.SceneManager->LoadScene(mainScene);

	umbrellaToolsKit.RenderWindow->BackendIntegration->SetWindowName("Game made with UmbrellaToolsKit4");

    GameObject* gameObject = mainScene->CreateGameObject();
    mainScene->AddGameObject(gameObject);

    auto* spriteRender = mainScene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);
    auto* sprite = new Umbrella::Sprite;
    sprite->Path = "Testing/Temporary/texture_test.png";
    sprite->X = 0;
    sprite->Y = 0;
    spriteRender->SetSprite(sprite);
    spriteRender->SetRotation2D(0.1f);
    spriteRender->SetTransparence(0.5f);

    auto* squareRender = mainScene->AddComponent<Umbrella::SquareRenderComponent>(gameObject);
    squareRender->SetPosition({ 10, 10, 1 });

	umbrellaToolsKit.Run();

	umbrellaToolsKit.ShutDown();

	return 0;
}
