#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../../src/engine/UmbrellaRoot.h"
#include "../../../../../src/engine/render/IRenderComponent.h"
#include "../../../../../src/engine/render/Material.h"
#include "../../../../../src/engine/render/Mesh.h"
#include "../../../../../src/engine/render/component/SpriteRenderComponent.h"
#include "../../../../../src/engine/scene/Scene.h"

TEST_CASE("Check Scale methods", "[SetScale]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    REQUIRE(spriteComponent->GetScale() == glm::vec2(1.0f, 1.0f));

    spriteComponent->SetScale(1.5f);

    REQUIRE(spriteComponent->GetScale() == glm::vec2(1.5f, 1.5f));

    spriteComponent->SetScale(glm::vec2(2.0f, 2.0f));

    REQUIRE(spriteComponent->GetScale() == glm::vec2(2.0f, 2.0f));
}

TEST_CASE("Check transparence methods", "[SetTransparence]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    REQUIRE(spriteComponent->GetTransparence() == 1.0f);

    spriteComponent->SetTransparence(0.1f);

    REQUIRE(spriteComponent->GetTransparence() == 0.1f);
}

TEST_CASE("Check color methods", "[SetSpriteColor]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    REQUIRE(spriteComponent->GetSpriteColor() == glm::vec4(1, 1, 1, 1));

    spriteComponent->SetSpriteColor(glm::vec4(5.0f, 2.0f, 5.0f, 1.0f));

    REQUIRE(spriteComponent->GetSpriteColor() == glm::vec4(5.0f, 2.0f, 5.0f, 1.0f));
}

TEST_CASE("Check SetFillSpriteColor methods", "[SetFillSpriteColor]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    REQUIRE(spriteComponent->GetFillSpriteColor() == glm::vec4(1, 1, 1, 0));

    spriteComponent->SetFillSpriteColor(glm::vec4(5.0f, 2.0f, 5.0f, 1.0f));

    REQUIRE(spriteComponent->GetFillSpriteColor() == glm::vec4(5.0f, 2.0f, 5.0f, 1.0f));
}

TEST_CASE("Check SetRotation methods", "[SetRotation]")
{
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();
    Umbrella::Scene* scene = root.SceneManager->CreateScene();

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    REQUIRE(spriteComponent->GetRotation() == glm::vec3(0, 0, 0));
    REQUIRE(spriteComponent->GetRotation2D() == 0);

    spriteComponent->SetRotation2D(1.0f);

    REQUIRE(spriteComponent->GetRotation() == glm::vec3(0, 1.0f, 0));
    REQUIRE(spriteComponent->GetRotation2D() == 1.0f);

    spriteComponent->SetRotation(glm::vec3(2.0f, 2.0f, 2.0f));

    REQUIRE(spriteComponent->GetRotation() == glm::vec3(2.0f, 2.0f, 2.0f));
    REQUIRE(spriteComponent->GetRotation2D() == 2.0f);

    spriteComponent->SetRotation2D(3.0f);

    REQUIRE(spriteComponent->GetRotation() == glm::vec3(2.0f, 3.0f, 2.0f));
}

TEST_CASE("Check SetSprite methods", "[SetSprite]")
{
    Umbrella::UmbrellaRoot* root = new Umbrella::UmbrellaRoot;
    root->StartUp();
    Umbrella::Scene* scene = root->SceneManager->CreateScene();
    root->SceneManager->LoadScene(scene);

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    Umbrella::Sprite* sprite = new Umbrella::Sprite;
    sprite->Path = "Testing/Temporary/texture_test.png";

    REQUIRE_FALSE(spriteComponent->HasSprite());

    spriteComponent->SetSprite(sprite);

    REQUIRE(spriteComponent->HasSprite());

    REQUIRE(spriteComponent->GetSprite() == sprite);
}

TEST_CASE("Check Material on sprite render")
{
    Umbrella::UmbrellaRoot* root = new Umbrella::UmbrellaRoot;
    root->StartUp();
    Umbrella::Scene* scene = root->SceneManager->CreateScene();
    root->SceneManager->LoadScene(scene);

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::SpriteRenderComponent* spriteComponent = scene->AddComponent<Umbrella::SpriteRenderComponent>(gameObject);

    Umbrella::Sprite* sprite = new Umbrella::Sprite;

    spriteComponent->SetScale(1.5f);
    spriteComponent->SetRotation2D(1.0f);
    spriteComponent->SetTransparence(0.1f);
    spriteComponent->SetSpriteColor(glm::vec4(5.0f, 2.0f, 5.0f, 1.0f));
    spriteComponent->SetFillSpriteColor(glm::vec4(6.0f, 2.0f, 6.0f, 1.0f));

    spriteComponent->OnUpdate(0.0f);

    REQUIRE(spriteComponent->GetMaterial()->GetVec2("scale") == glm::vec2(1.5f, 1.5f));
    REQUIRE(spriteComponent->GetMaterial()->GetVec3("rotation") == glm::vec3(0.0f, 1.0f, 0.0f));
    REQUIRE(spriteComponent->GetMaterial()->GetFloat("transparence") == 0.1f);
    REQUIRE(spriteComponent->GetMaterial()->GetVec4("color") == glm::vec4(5.0f, 2.0f, 5.0f, 1.0f));
    REQUIRE(spriteComponent->GetMaterial()->GetVec4("fillColor") == glm::vec4(6.0f, 2.0f, 6.0f, 1.0f));
}
