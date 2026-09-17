#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/scene/Scene.h"
#include <string>

class ComponentTest : public Umbrella::IComponent
{
    public:

        ComponentTest (std::string gameObjectId, Umbrella::Scene* scene, std::string componentId) : IComponent(gameObjectId, scene, componentId)
        { }
        
        bool StartUp = false;
        bool Init = false;
        bool IsEnable = false;
        bool IsDestroyed = false;

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
            IsDestroyed = true;
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
    scene.AddGameObject(gameObject);
    ComponentTest* componentTeste1 = scene.AddComponent<ComponentTest>(gameObject);
    ComponentTest* componentTeste2 = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE(scene.HasComponent(componentTeste1));
    REQUIRE(scene.HasComponent(componentTeste2));

    scene.RemoveComponent(componentTeste1);

    REQUIRE_FALSE(scene.HasComponent(componentTeste1));
    REQUIRE(scene.HasComponent(componentTeste2));

    scene.RemoveComponent(componentTeste2);

    REQUIRE_FALSE(scene.HasComponent(componentTeste1));
    REQUIRE_FALSE(scene.HasComponent(componentTeste2));
}

TEST_CASE("check component flow methods", "[StartUp][Init][Enable]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();

    REQUIRE_FALSE(gameObject == nullptr);

    scene.AddGameObject(gameObject);

    ComponentTest* componentTeste = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE_FALSE(componentTeste == nullptr);

    REQUIRE(componentTeste->StartUp);
    REQUIRE_FALSE(componentTeste->Init);
    REQUIRE_FALSE(componentTeste->IsEnable);
    REQUIRE(componentTeste->TotalUpdateTime == 0);
    REQUIRE(componentTeste->TotalUpdateDataTime == 0);

    scene.Update(1);
    scene.UpdateData(2);

    REQUIRE(componentTeste->StartUp);
    REQUIRE(componentTeste->Init);
    REQUIRE(componentTeste->IsEnable);

    REQUIRE(componentTeste->TotalUpdateTime == 1);
    REQUIRE(componentTeste->TotalUpdateDataTime == 2);

    scene.Update(1);
    scene.UpdateData(2);

    REQUIRE(componentTeste->TotalUpdateTime == 2);
    REQUIRE(componentTeste->TotalUpdateDataTime == 4);
}

TEST_CASE("check add a component in a gameobject that isn't in the scene", "[addcomponent]")
{
    Umbrella::Scene scene = {};
    Umbrella::Scene scene2 = {};

    GameObject* gameObject = scene.CreateGameObject();
    ComponentTest* componentTeste = scene2.AddComponent<ComponentTest>(gameObject);

    REQUIRE(componentTeste == nullptr);
}

TEST_CASE("check remove component", "[RemoveComponent]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    ComponentTest* componentTeste = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE_FALSE(componentTeste == nullptr);

    REQUIRE(componentTeste->StartUp);
    REQUIRE_FALSE(componentTeste->IsEnable);
    REQUIRE_FALSE(componentTeste->IsDestroyed);

    scene.Update(1);
    scene.UpdateData(2);
    scene.RemoveComponent(componentTeste);

    REQUIRE_FALSE(componentTeste->IsEnable);
    REQUIRE(componentTeste->IsDestroyed);
}


TEST_CASE("Start disable gameobject", "[AddComponent]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);
    scene.SetActive(gameObject, false);
    ComponentTest* componentTeste = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE_FALSE(componentTeste == nullptr);


    REQUIRE_FALSE(componentTeste->StartUp);
    REQUIRE_FALSE(componentTeste->Init);
    REQUIRE_FALSE(componentTeste->IsEnable);

    scene.SetActive(gameObject, true);

    scene.Update(1);
    scene.UpdateData(2);

    REQUIRE(componentTeste->StartUp);
    REQUIRE(componentTeste->Init);
    REQUIRE(componentTeste->IsEnable);
}

TEST_CASE("check if the scene has gameobject and component", "[UnloadScene]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);

    ComponentTest* componentTeste1 = scene.AddComponent<ComponentTest>(gameObject);
    ComponentTest* componentTeste2 = scene.AddComponent<ComponentTest>(gameObject);

    REQUIRE_FALSE(componentTeste1 == nullptr);
    REQUIRE_FALSE(componentTeste2 == nullptr);

    scene.UnloadScene();

    REQUIRE_FALSE(scene.HasComponent(componentTeste1));
    REQUIRE_FALSE(scene.HasComponent(componentTeste2));

    REQUIRE_FALSE(scene.HasGameObject(gameObject));
}

TEST_CASE("deactive scene", "[SetAction]")
{
    Umbrella::Scene scene = {};

    GameObject* gameObject = scene.CreateGameObject();
    scene.AddGameObject(gameObject);

    ComponentTest* componentTeste = scene.AddComponent<ComponentTest>(gameObject);

    scene.SetActiveScene(false);
    scene.Update(1);

    REQUIRE(componentTeste->TotalUpdateTime == 0);

    scene.SetActiveScene(true);
    scene.Update(1);

    REQUIRE(componentTeste->TotalUpdateTime == 1);
}
