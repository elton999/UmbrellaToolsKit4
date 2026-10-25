
#include "../../../../../src/engine/scene/camera/CameraManager.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check main camera")
{
    Umbrella::CameraManager cameraManager = {};
    cameraManager.StartUp();

    REQUIRE(cameraManager.GetCamera("default") != nullptr);
}

TEST_CASE("check ShutDown")
{
    Umbrella::CameraManager cameraManager = {};
    cameraManager.StartUp();
    cameraManager.ShutDown();

    REQUIRE(cameraManager.GetCamera("default") == nullptr);
}

TEST_CASE("set camera in diferent layer")
{
    Umbrella::CameraManager cameraManager = {};
    cameraManager.StartUp();

    REQUIRE(cameraManager.GetCamera("fake layer") != nullptr);
    REQUIRE(cameraManager.GetCamera("fake layer") == cameraManager.GetCamera("default"));

    Umbrella::Camera* newCamera = cameraManager.CreateCamera();
    cameraManager.SetCamera("new layer", newCamera);

    REQUIRE(cameraManager.GetCamera("new layer") != nullptr);
    REQUIRE(cameraManager.GetCamera("new layer") == newCamera);
    REQUIRE(cameraManager.GetCamera("new layer") != cameraManager.GetCamera("default"));

    cameraManager.SetCamera("default", newCamera);

    REQUIRE(cameraManager.GetCamera("default") == newCamera);
};
