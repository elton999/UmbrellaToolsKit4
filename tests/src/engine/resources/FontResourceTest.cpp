
#include "../../../../src/engine/resources/FontResource.h"
#include "../../../../src/engine/UmbrellaRoot.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Check font load", "[HasContent][resource != null]")
{
    std::string path = "Testing/Temporary/fontImportTest";
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();

    Umbrella::FontResource* font = root.ResourceManager->Load<Umbrella::FontResource>(path);

    REQUIRE(font->HasLoaded());
    REQUIRE(root.ResourceManager->HasContent(path));

    root.ResourceManager->Unload(path);

    REQUIRE_FALSE(font->HasLoaded());
}

TEST_CASE("Try to load a invalid font")
{
    std::string path = "Testing/Temporary/fakeFontImport";
    Umbrella::UmbrellaRoot root = {};
    root.StartUp();

    Umbrella::FontResource* font = root.ResourceManager->Load<Umbrella::FontResource>(path);

    REQUIRE_FALSE(font->HasLoaded());
}
