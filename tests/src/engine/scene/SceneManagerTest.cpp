#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/scene/SceneManager.h"
#include "../../../../src/engine/scene/Scene.h"
#include <string>

TEST_CASE("Check if create a scene", "[CreateScene][Scene != null]")
{
    Umbrella::SceneManager sceneManager = {};
    sceneManager.StartUp();

    REQUIRE(sceneManager.CreateScene() != nullptr);
}

TEST_CASE("Load Scene Check", "[LoadScene][IsSceneLoaded == true]")
{
    Umbrella::SceneManager sceneManager = {};
    sceneManager.StartUp();
    Umbrella::Scene* scene = sceneManager.CreateScene();

    REQUIRE_FALSE(sceneManager.IsSceneLoaded(scene));

    sceneManager.LoadScene(scene);

    REQUIRE(sceneManager.IsSceneLoaded(scene));
}

TEST_CASE("unLoad Scene Check", "[UnloadScene][IsSceneLoaded == false]")
{
    Umbrella::SceneManager sceneManager = {};
    sceneManager.StartUp();
    Umbrella::Scene* scene1 = sceneManager.CreateScene();
    Umbrella::Scene* scene2 = sceneManager.CreateScene();

    sceneManager.LoadScene(scene1);
    sceneManager.LoadScene(scene2);

    REQUIRE(sceneManager.IsSceneLoaded(scene1));

    sceneManager.UnloadScene(scene1);

    REQUIRE_FALSE(sceneManager.IsSceneLoaded(scene1));
    REQUIRE(sceneManager.IsSceneLoaded(scene2));

    sceneManager.ShutDown();

    REQUIRE_FALSE(sceneManager.IsSceneLoaded(scene2));
}


