#include "engine/UmbrellaRoot.h"
#include "engine/render/component/SpriteRenderComponent.h"
#include "engine/render/component/SquareRenderComponent.h"
#include "engine/render/component/TextRenderComponent.h"
#include "engine/scene/Scene.h"
#include "render/component/TextRenderComponent.h"
#include "resources/FontResource.h"

int main()
{
    Umbrella::UmbrellaRoot umbrellaToolsKit = {};

    umbrellaToolsKit.StartUp();
    Umbrella::Scene* mainScene = umbrellaToolsKit.SceneManager->CreateScene();
    umbrellaToolsKit.SceneManager->LoadScene(mainScene);

    umbrellaToolsKit.RenderWindow->BackendIntegration->SetWindowName("Game made with UmbrellaToolsKit4");

    // exemples
    {
        GameObject* gameObject = mainScene->CreateGameObject();
        mainScene->AddGameObject(gameObject);
        GameObject* gameObject2 = mainScene->CreateGameObject();
        mainScene->AddGameObject(gameObject2);

        auto* sprite = new Umbrella::Sprite;
        sprite->Path = "Testing/Temporary/texture_test.png";
        auto* spriteRender = mainScene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);
        spriteRender->SetSprite(sprite);
        spriteRender->SetRotation2D(0.5f);

        GameObject* gameObject1 = mainScene->CreateGameObject();
        mainScene->AddGameObject(gameObject1);

        auto* squareRender = mainScene->AddComponent<Umbrella::SquareRenderComponent>(gameObject1);
        squareRender->SetSize({40, 40});
        auto* text = mainScene->AddComponent<Umbrella::TextRenderComponent>(gameObject2);
        text->SetText("Hello World 123!");
        text->SetFontSize(0.2f);
        text->SetFont(umbrellaToolsKit.ResourceManager->Load<Umbrella::FontResource>("Testing/Temporary/fontImportTest.ttf"));
    }

    umbrellaToolsKit.Run();
    umbrellaToolsKit.ShutDown();

    return 0;
}
