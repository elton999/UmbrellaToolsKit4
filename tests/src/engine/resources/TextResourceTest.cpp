#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/resources/TextResource.h"
#include "../../../../src/engine/core/platform/FileSystem.h"
#include <string>

TEST_CASE("Check if the text resource is loaded", "[Load][content != null]")
{
	std::string path = "Testing/Temporary/ResoucerTextTest1.txt";
	std::string content = "content";
	Umbrella::FileSystem::Write(path, content);

	Umbrella::TextResource text = {};
	text.Load(path);

	REQUIRE(text.GetContent()->compare(content) == 0);
}

TEST_CASE("Check if the text resource is null", "[Unload][content == null]")
{
	std::string path = "Testing/Temporary/ResoucerTextTest2.txt";
	std::string content = "content";
	Umbrella::FileSystem::Write(path, content);

	Umbrella::TextResource text = {};
	text.Load(path);
	text.Unload();

	if (text.GetContent())
		REQUIRE(false);
	else
		REQUIRE(true);
}
