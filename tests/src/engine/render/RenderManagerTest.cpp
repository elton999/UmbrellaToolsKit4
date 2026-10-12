#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../src/engine/render/Mesh.h"
#include "../../../../src/engine/render/Material.h"
#include "../../../../src/engine/render/IRenderComponent.h"
#include "../../../../src/engine/render/RenderManager.h"
#include "../../../../src/engine/render/component/MeshRenderComponent.h"
#include "../../../../src/engine/core/RenderWindow.h"
#include "../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
#include "../../../../src/engine/scene/Scene.h"
#include "../../../../src/engine/UmbrellaRoot.h"

class RenderComponentTest : public Umbrella::IRenderComponent
{
    public:
        int DrawCount = 0;

        RenderComponentTest(std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : Umbrella::IRenderComponent(gameObjectId, scene, componentId)
        {}

        void Draw() override
        {
            DrawCount++;
        }
};

TEST_CASE("add render component", "[AddRenderComponent(mesh)]")
{
    Umbrella::UmbrellaRoot* root = new Umbrella::UmbrellaRoot;
    root->StartUp();

    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene.AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    Umbrella::RenderManager renderManager = { root };

    renderManager.StartUp();

    REQUIRE_FALSE(renderManager.HasComponent(meshRender));

    renderManager.AddRenderComponent(meshRender);

    REQUIRE(renderManager.HasLayer("default"));
    REQUIRE(renderManager.HasComponent(meshRender));

    renderManager.RemoveRenderComponet(meshRender);

    REQUIRE_FALSE(renderManager.HasComponent(meshRender));
}

TEST_CASE("add render component with layer", "[AddRenderComponent(mesh, layer)]")
{
    Umbrella::UmbrellaRoot* root = new Umbrella::UmbrellaRoot;
    root->StartUp();

    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene.AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    Umbrella::RenderManager renderManager = { root };
    renderManager.StartUp();

    REQUIRE_FALSE(renderManager.HasComponent(meshRender));

    renderManager.AddRenderComponent(meshRender, "layer1");

    REQUIRE(renderManager.GetComponentLayer(meshRender) == "layer1");
    REQUIRE(renderManager.HasComponent(meshRender));

    renderManager.AddRenderComponent(meshRender);

    REQUIRE(renderManager.GetComponentLayer(meshRender) == "layer1");
}

TEST_CASE("add and remove render componet", "[destroy render component]")
{
    Umbrella::UmbrellaRoot* root = new Umbrella::UmbrellaRoot;
    root->StartUp();

    Umbrella::Scene* scene = root->SceneManager->CreateScene();
    root->SceneManager->LoadScene(scene);

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene->AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    Umbrella::RenderManager* renderManager = root->RenderManager;

    REQUIRE(renderManager->HasComponent(meshRender));

    scene->DestroyGameObject(gameObject);

    REQUIRE_FALSE(renderManager->HasComponent(meshRender));
}

TEST_CASE("Draw render component behaviour", "[Run]")
{
    Umbrella::UmbrellaRoot* root = new Umbrella::UmbrellaRoot;
    root->StartUp();

    Umbrella::Scene* scene = root->SceneManager->CreateScene();
    root->SceneManager->LoadScene(scene);

    GameObject* gameObject = scene->CreateGameObject();
    scene->AddGameObject(gameObject);
    scene->SetActive(gameObject, false);

    RenderComponentTest* renderComponent = scene->AddComponent<RenderComponentTest>(gameObject);

    REQUIRE(renderComponent->DrawCount == 0);

    root->SceneManager->Run();
    root->RenderManager->Run();

    REQUIRE(renderComponent->DrawCount == 0);

    scene->SetActive(gameObject, true);
    root->SceneManager->Run();
    root->RenderManager->Run();

    REQUIRE(renderComponent->DrawCount == 1);
}
