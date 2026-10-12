#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../src/engine/render/Mesh.h"
#include "../../../../src/engine/render/Material.h"
#include "../../../../src/engine/render/RenderManager.h"
#include "../../../../src/engine/render/component/MeshRenderComponent.h"
#include "../../../../src/engine/core/RenderWindow.h"
#include "../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
#include "../../../../src/engine/scene/Scene.h"

TEST_CASE("add render component", "[AddRenderComponent(mesh)]")
{
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene.AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    Umbrella::RenderManager renderManager = {};

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
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene.AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    Umbrella::RenderManager renderManager = {};
    renderManager.StartUp();

    REQUIRE_FALSE(renderManager.HasComponent(meshRender));

    renderManager.AddRenderComponent(meshRender, "layer1");

    REQUIRE(renderManager.GetComponentLayer(meshRender) == "layer1");
    REQUIRE(renderManager.HasComponent(meshRender));

    renderManager.AddRenderComponent(meshRender);

    REQUIRE(renderManager.GetComponentLayer(meshRender) == "layer1");
}
