#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../../src/engine/UmbrellaRoot.h"
#include "../../../../../src/engine/render/Mesh.h"
#include "../../../../../src/engine/render/Material.h"
#include "../../../../../src/engine/render/IRenderComponent.h" 
#include "../../../../../src/engine/render/component/SquareRenderComponent.h"
#include "../../../../../src/engine/scene/Scene.h"


TEST_CASE("Check size methods", "[SetSize]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    gameObject->IsEnable = false;
    scene->AddGameObject(gameObject);
    Umbrella::SquareRenderComponent* square = scene->AddComponent<Umbrella::SquareRenderComponent>(gameObject);

    REQUIRE(square->GetSize() == glm::vec2(10, 10));

    square->SetSize({ 1.5f, 1.5f });

    REQUIRE(square->GetSize() == glm::vec2(1.5f, 1.5f));

    square->SetSize(glm::vec2(2.0f, 2.0f));

    REQUIRE(square->GetSize() == glm::vec2(2.0f, 2.0f));
}
