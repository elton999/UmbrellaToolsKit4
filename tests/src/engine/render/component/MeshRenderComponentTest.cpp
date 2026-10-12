#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../../src/engine/render/Mesh.h"
#include "../../../../../src/engine/render/Material.h"
#include "../../../../../src/engine/render/component/MeshRenderComponent.h"
#include "../../../../../src/engine/core/RenderWindow.h"
#include "../../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
#include "../../../../../src/engine/scene/Scene.h"

TEST_CASE("set mesh on MeshRenderComponent", "[SetMesh(mesh)]")
{
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();


    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene.AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    Umbrella::Mesh mesh = {};


    REQUIRE_FALSE(meshRender->HasMesh());
 
    meshRender->SetMesh(&mesh);

    REQUIRE(meshRender->HasMesh());
}

TEST_CASE("set material on MeshRenderComponent", "[SetMaterial(material)]")
{
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    Umbrella::Material material = {};

    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    Umbrella::MeshRenderComponent* meshRender = scene.AddComponent<Umbrella::MeshRenderComponent>(gameObject);

    REQUIRE_FALSE(meshRender->HasMaterial());

    meshRender->SetMaterial(&material);

    REQUIRE(meshRender->HasMaterial());
}

