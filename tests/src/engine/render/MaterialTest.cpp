#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../src/engine/render/Material.h"
#include "../../../../src/engine/core/RenderWindow.h"
#include "../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"

TEST_CASE("check set bool", "[SetBool]")
{
    Umbrella::Material material = {};
    material.SetBool("test1", true);
    material.SetBool("test2", false);

    REQUIRE(material.GetBool("test1"));
    REQUIRE_FALSE(material.GetBool("test2"));

    material.SetBool("test1", false);
    material.SetBool("test2", true);

    REQUIRE_FALSE(material.GetBool("test1"));
    REQUIRE(material.GetBool("test2"));
}

TEST_CASE("check set int", "[SetInt]")
{
    Umbrella::Material material = {};
    material.SetInt("test1", 1);
    material.SetInt("test2", 2);

    REQUIRE(material.GetInt("test1") == 1);
    REQUIRE(material.GetInt("test2") == 2);

    material.SetInt("test1", 3);
    material.SetInt("test2", 4);

    REQUIRE(material.GetInt("test1") == 3);
    REQUIRE(material.GetInt("test2") == 4);
}

TEST_CASE("check set float", "[SetFloat]")
{
    Umbrella::Material material = {};
    material.SetFloat("test1", 1.0f);
    material.SetFloat("test2", 2.0f);

    REQUIRE(material.GetFloat("test1") == 1.0f);
    REQUIRE(material.GetFloat("test2") == 2.0f);

    material.SetFloat("test1", 3.0f);
    material.SetFloat("test2", 4.0f);

    REQUIRE(material.GetFloat("test1") == 3.0f);
    REQUIRE(material.GetFloat("test2") == 4.0f);
}

TEST_CASE("check set vec3", "[SetVec3]")
{
    Umbrella::Material material = {};
    material.SetVec3("test1", glm::vec3(1,1,1));
    material.SetVec3("test2", glm::vec3(2, 2, 2));

    REQUIRE(material.GetVec3("test1") == glm::vec3(1, 1, 1));
    REQUIRE(material.GetVec3("test2") == glm::vec3(2, 2, 2));

    material.SetVec3("test1", glm::vec3(3, 3, 3));
    material.SetVec3("test2", glm::vec3(4, 4, 4));

    REQUIRE(material.GetVec3("test1") == glm::vec3(3, 3, 3));
    REQUIRE(material.GetVec3("test2") == glm::vec3(4, 4, 4));
}

TEST_CASE("check set vec2", "[SetVec2]")
{
    Umbrella::Material material = {};
    material.SetVec2("test1", glm::vec2(1, 1));
    material.SetVec2("test2", glm::vec2(2, 2));

    REQUIRE(material.GetVec2("test1") == glm::vec2(1, 1));
    REQUIRE(material.GetVec2("test2") == glm::vec2(2, 2));

    material.SetVec2("test1", glm::vec2(3, 3));
    material.SetVec2("test2", glm::vec2(4, 4));

    REQUIRE(material.GetVec2("test1") == glm::vec2(3, 3));
    REQUIRE(material.GetVec2("test2") == glm::vec2(4, 4));
}

TEST_CASE("check set vec4", "[SetVec4]")
{
    Umbrella::Material material = {};
    material.SetVec4("test1", glm::vec4(1, 1, 1, 1));
    material.SetVec4("test2", glm::vec4(2, 2, 2, 2));

    REQUIRE(material.GetVec4("test1") == glm::vec4(1, 1, 1, 1));
    REQUIRE(material.GetVec4("test2") == glm::vec4(2, 2, 2, 2));

    material.SetVec4("test1", glm::vec4(3, 3, 3, 3));
    material.SetVec4("test2", glm::vec4(4, 4, 4, 4));

    REQUIRE(material.GetVec4("test1") == glm::vec4(3, 3, 3, 3));
    REQUIRE(material.GetVec4("test2") == glm::vec4(4, 4, 4, 4));
}

TEST_CASE("check set mat4", "[SetMatrix4]")
{
    Umbrella::Material material = {};
    material.SetMatrix4("test1", glm::mat4(1));
    material.SetMatrix4("test2", glm::mat4(2));

    REQUIRE(material.GetMatrix4("test1") == glm::mat4(1));
    REQUIRE(material.GetMatrix4("test2") == glm::mat4(2));

    material.SetMatrix4("test1", glm::mat4(3));
    material.SetMatrix4("test2", glm::mat4(4));

    REQUIRE(material.GetMatrix4("test1") == glm::mat4(3));
    REQUIRE(material.GetMatrix4("test2") == glm::mat4(4));
}
