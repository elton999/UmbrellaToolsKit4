#include <catch2/catch_test_macros.hpp>
#include "../../../../../src/engine/core/platform/FileSystem.h"
#include <cstdlib>

TEST_CASE("check write and read string", "[write and read][sting == null]")
{
	int randomNum = rand() % 101;

	Umbrella::FileSystem::Write("filesystem.txt", std::to_string(randomNum));
	Umbrella::FileSystem::Write("filesystem.txt", std::to_string(randomNum));
	Umbrella::FileSystem::Write("filesystem.txt", std::to_string(randomNum));

	std::string result = Umbrella::FileSystem::Read("filesystem.txt");

	REQUIRE(result == std::to_string(randomNum));
}

