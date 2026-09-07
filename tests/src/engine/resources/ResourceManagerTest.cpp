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
	REQUIRE(textResourse->GetContent()->compare(content) == 0);
}

TEST_CASE("Load only once", "[Load][lenght == 1]")
{
	std::string path = "Testing/Temporary/loadResourceTest3.txt";
	std::string content = "content content";
	Umbrella::FileSystem::Write(path, content);

	Umbrella::ResourceManager resourceManager = {};
	resourceManager.Load<Umbrella::TextResource>(path);
	resourceManager.Load<Umbrella::TextResource>(path);

	REQUIRE(resourceManager.Lenght() == 1);
}

TEST_CASE("Unload resource teste", "[Load][lenght == 0]")
{
	std::string path1 = "Testing/Temporary/loadResourceTest4.txt";
	std::string path2 = "Testing/Temporary/loadResourceTest5.txt";
	std::string content = "content content";
	Umbrella::FileSystem::Write(path1, content);
	Umbrella::FileSystem::Write(path2, content);

	Umbrella::ResourceManager resourceManager = {};
	resourceManager.Load<Umbrella::TextResource>(path1);
	resourceManager.Load<Umbrella::TextResource>(path2);

	REQUIRE(resourceManager.Lenght() == 2);

	resourceManager.Unload(path1);

	REQUIRE_FALSE(resourceManager.HasContent(path1));
	REQUIRE(resourceManager.Lenght() == 1);

	resourceManager.Load<Umbrella::TextResource>(path1);

	REQUIRE(resourceManager.Lenght() == 2);

	resourceManager.ShutDown();

	REQUIRE_FALSE(resourceManager.HasContent(path1));
	REQUIRE(resourceManager.Lenght() == 0);
}
