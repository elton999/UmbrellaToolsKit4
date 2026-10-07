#include <catch2/catch_test_macros.hpp>
#include <string>

#include "../../../../src/engine/render/Mesh.h"
#include "../../../../src/engine/core/RenderWindow.h"
#include "../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"

TEST_CASE("Check if the Mesh is loaded", "[Load(vertices)]")
{
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    std::vector<glm::vec3> square =
    {
        glm::vec3{0.0f, 1.0f, 0.0f},
        glm::vec3{1.0f, 1.0f, 0.0f},
        glm::vec3{0.0f, 0.0f, 0.0f},

        glm::vec3{1.0f, 1.0f, 0.0f},
        glm::vec3{1.0f, 0.0f, 0.0f},
        glm::vec3{0.0f, 0.0f, 0.0f},
    };

    Umbrella::Mesh mesh = {};

    REQUIRE(mesh.GetVerticesCount() == 0);
    REQUIRE(mesh.GetVerticesColorsCount() == 0);
    REQUIRE(mesh.GetTexCoordsCount() == 0);

    mesh.Load(square);

    REQUIRE(mesh.GetVerticesCount() == 6);
    REQUIRE(mesh.GetVerticesColorsCount() == 0);
    REQUIRE(mesh.GetTexCoordsCount() == 0);
}


TEST_CASE("Check if the Mesh is loaded", "[Load(vertices, vertices colors, tex coord)]")
{
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    std::vector<glm::vec3> square =
    {
        glm::vec3{0.0f, 1.0f, 0.0f},
        glm::vec3{1.0f, 1.0f, 0.0f},
        glm::vec3{0.0f, 0.0f, 0.0f},

        glm::vec3{1.0f, 1.0f, 0.0f},
        glm::vec3{1.0f, 0.0f, 0.0f},
        glm::vec3{0.0f, 0.0f, 0.0f},
    };

    std::vector<glm::vec2> texCoords =
    {
        glm::vec2{0.0f, 1.0f},
        glm::vec2{1.0f, 1.0f},
        glm::vec2{0.0f, 0.0f},

        glm::vec2{1.0f, 1.0f},
        glm::vec2{1.0f, 0.0f},
        glm::vec2{0.0f, 0.0f},
    };

    std::vector<glm::vec3> colors =
    {
        glm::vec3{1.0f, 0.0f, 0.0f},
        glm::vec3{0.0f, 1.0f, 0.0f},
        glm::vec3{0.0f, 0.0f, 1.0f},

        glm::vec3{1.0f, 1.0f, 0.0f},
        glm::vec3{0.0f, 1.0f, 1.0f},
        glm::vec3{1.0f, 0.0f, 1.0f},
    };

    Umbrella::Mesh mesh = {};

    REQUIRE(mesh.GetVerticesCount() == 0);
    REQUIRE(mesh.GetVerticesColorsCount() == 0);
    REQUIRE(mesh.GetTexCoordsCount() == 0);

    mesh.Load(square);

    REQUIRE(mesh.GetVerticesCount() == 6);
    REQUIRE(mesh.GetVerticesColorsCount() == 6);
    REQUIRE(mesh.GetTexCoordsCount() == 6);
}
