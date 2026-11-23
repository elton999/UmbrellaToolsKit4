#include <catch2/catch_test_macros.hpp>

#include "../../../../../src/engine/UmbrellaRoot.h"
#include "../../../../../src/engine/render/component/TextRenderComponent.h"
#include "../../../../../src/engine/resources/FontResource.h"
#include "../../../../../src/engine/scene/Scene.h"

TEST_CASE("Check size methods", "[SetFontSize]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    auto* textComponent = scene->AddComponent<Umbrella::TextRenderComponent>(gameObject);

    REQUIRE(textComponent->GetFontSize() == 1.0);

    textComponent->SetFontSize(2.0);

    REQUIRE(textComponent->GetFontSize() == 2.0);
}

TEST_CASE("Check set font resource ", "[SetResource]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);

    std::string path = "Testing/Temporary/fontImportTest.ttf";
    auto* textComponent = scene->AddComponent<Umbrella::TextRenderComponent>(gameObject);
    auto* font = root.ResourceManager->Load<Umbrella::FontResource>(path);

    REQUIRE_FALSE(textComponent->HasFont());

    textComponent->SetFont(font);

    REQUIRE(textComponent->HasFont());

    REQUIRE_FALSE(textComponent->HasText());

    textComponent->SetText("hello world");

    REQUIRE(textComponent->HasText());
}
