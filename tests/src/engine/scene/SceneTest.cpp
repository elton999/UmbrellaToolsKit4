#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/scene/Scene.h"
#include "../../../../src/engine/scene/GameObject.h"
#include <string>

TEST_CASE("Check Create GameObject", "[CreateGameObject]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();

    REQUIRE(gameObject != nullptr);
}

TEST_CASE("check add remove GameObject", "[HasGameObject]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject1 = scene.CreateGameObject();
    GameObject* gameObject2 = scene.CreateGameObject();

    REQUIRE_FALSE(scene.HasGameObject(gameObject1));

    scene.AddGameObject(gameObject1);

    REQUIRE(scene.HasGameObject(gameObject1));
    REQUIRE_FALSE(scene.HasGameObject(gameObject2));

    scene.RemoveGameObject(gameObject1);

    REQUIRE_FALSE(scene.HasGameObject(gameObject1));
    REQUIRE(scene.HasGameObject(gameObject2));
}
