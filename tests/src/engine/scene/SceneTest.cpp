#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/scene/Scene.h"
#include "../../../../src/engine/scene/GameObject.h"
#include <string>

class ComponentTest : public Umbrella::IComponent
{
    public:
        bool StartUp = false;
        bool Init = false;
        bool IsEnable = false;

        float TotalUpdateTime = 0;
        float TotalUpdateDataTime = 0;

        void OnStartUp() override
        {
            StartUp = true;
        }

        void OnInit() override
        {
            Init = true;
        }

        void OnEnable() override
        {
            IsEnable = true;
        }

        void OnDisable() override
        {
            IsEnable = false;
        }

        void OnDestroy() override
        {

        }

        void OnUpdate(float deltaTime) override
        {
            TotalUpdateTime += deltaTime;
        }

        void OnUpdateData(float deltaTime) override
        {
            TotalUpdateDataTime += deltaTime;
        }
};

TEST_CASE("Check Create GameObject", "[CreateGameObject]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();

    REQUIRE_FALSE(gameObject == nullptr);
}

TEST_CASE("check add remove GameObject", "[HasGameObject]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject1 = scene.CreateGameObject();
    GameObject* gameObject2 = scene.CreateGameObject();

    REQUIRE_FALSE(scene.HasGameObject(gameObject1));

    scene.AddGameObject(gameObject1);

    REQUIRE_FALSE(scene.HasGameObject(gameObject2));
    REQUIRE(scene.HasGameObject(gameObject1));

    scene.AddGameObject(gameObject2);
    scene.RemoveGameObject(gameObject1);

    REQUIRE_FALSE(scene.HasGameObject(gameObject1));
    REQUIRE(scene.HasGameObject(gameObject2));
}

TEST_CASE("check add component", "[AddComponent][HasComponent() == true]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    ComponentTest* componentTeste1 = scene.AddComponent<ComponentTest>(gameObject);
    ComponentTest* componentTeste2 = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE(scene.HasComponent(gameObject, componentTeste1));
    REQUIRE(scene.HasComponent(gameObject, componentTeste2));

    scene.RemoveComponent(gameObject, componentTeste1);

    REQUIRE_FALSE(scene.HasComponent(gameObject, componentTeste1));
    REQUIRE(scene.HasComponent(gameObject, componentTeste2));

    scene.RemoveComponent(gameObject, componentTeste2);

    REQUIRE_FALSE(scene.HasComponent(gameObject, componentTeste1));
    REQUIRE_FALSE(scene.HasComponent(gameObject, componentTeste2));
}

TEST_CASE("check component flow methods", "[StartUp][Init][Enable]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    ComponentTest* componentTeste = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE_FALSE(componentTeste == nullptr);

    REQUIRE(componentTeste->StartUp);
    REQUIRE_FALSE(componentTeste->Init);
    REQUIRE_FALSE(componentTeste->IsEnable);
    REQUIRE(componentTeste->TotalUpdateTime == 0);
    REQUIRE(componentTeste->TotalUpdateDataTime == 0);

    scene.Update(1);
    scene.Update(2);

    REQUIRE(componentTeste->StartUp);
    REQUIRE(componentTeste->Init);
    REQUIRE(componentTeste->IsEnable);

    REQUIRE(componentTeste->TotalUpdateTime == 1);
    REQUIRE(componentTeste->TotalUpdateDataTime == 2);

    scene.Update(1);
    scene.Update(2);

    REQUIRE(componentTeste->TotalUpdateTime == 2);
    REQUIRE(componentTeste->TotalUpdateDataTime == 4);
}
