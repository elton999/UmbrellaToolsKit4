#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/resources/ResourceManager.h"
#include "../../../../src/engine/resources/TextResource.h"
#include "../../../../src/engine/core/platform/FileSystem.h"
#include <string>

TEST_CASE("Check if the resource is loaded", "[HasContent][resource != null]")
{
	std::string path = "Testing/Temporary/loadResourceTest1.txt";
	Umbrella::FileSystem::Write(path, "content");

	Umbrella::ResourceManager resourceManager = {};
	resourceManager.Load<Umbrella::TextResource>(path);

	REQUIRE(resourceManager.HasContent(path));
}

TEST_CASE("Load Resource", "[Load][resource != null]")
{
	std::string path = "Testing/Temporary/loadResourceTest2.txt";
	std::string content = "content content";
	Umbrella::FileSystem::Write(path, content);

	Umbrella::ResourceManager resourceManager = {};
	Umbrella::TextResource *textResourse = resourceManager.Load<Umbrella::TextResource>(path);

	REQUIRE(textResourse);
}
