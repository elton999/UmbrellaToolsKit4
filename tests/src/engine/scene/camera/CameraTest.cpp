#include "../../../../../src/engine/scene/camera/Camera.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check position")
{
    Umbrella::Camera camera = {};

    REQUIRE(camera.GetPosition() == glm::vec3(1, 1, 1));

    camera.SetPosition({1, 1, 1});

    REQUIRE(camera.GetPosition() == glm::vec3(1, 1, 1));
}

TEST_CASE("Check Rotation")
{
    Umbrella::Camera camera = {};

    REQUIRE(camera.GetRotation() == glm::vec3(0, 0, 0));

    camera.SetRotation({1, 1, 1});

    REQUIRE(camera.GetRotation() == glm::vec3(1, 1, 1));
}

TEST_CASE("Check Scale")
{
    Umbrella::Camera camera = {};

    REQUIRE(camera.GetScale() == glm::vec3(1, 1, 1));

    camera.SetScale({2, 2, 2});

    REQUIRE(camera.GetScale() == glm::vec3(2, 2, 2));
}

TEST_CASE("Check Size")
{
    Umbrella::Camera camera = {};

    REQUIRE(camera.GetSize() == glm::ivec2(224, 135));

    camera.SetSize({2, 2});

    REQUIRE(camera.GetSize() == glm::ivec2(2, 2));
}
