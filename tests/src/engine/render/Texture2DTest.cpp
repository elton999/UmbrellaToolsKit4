#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/render/Texture2D.h"
#include "../../../../src/engine/core/RenderWindow.h"
#include "../../../../src/engine/core/platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
#include <string>


TEST_CASE("Check if the texture is loaded", "[Load]")
{
    Umbrella::RenderWindow renderWindow = {};
    renderWindow.BackendIntegration = new Umbrella::GLWF_BackendIntegration;
    renderWindow.StartUp();

    std::string path = "Testing/Temporary/texture_test.png";
    Umbrella::Texture2D texture = {};

    REQUIRE(texture.GetWidth() == 0);
    REQUIRE(texture.GetHight() == 0);

    texture.Load(path);

    REQUIRE(texture.GetWidth() == 50);
    REQUIRE(texture.GetHight() == 50);

    texture.Unload();

    REQUIRE(texture.GetWidth() == 0);
    REQUIRE(texture.GetHight() == 0);
}
