#include <catch2/catch_test_macros.hpp>
#include "../../../../../src/engine/core/platform/FileSystem.h"
#include <cstdlib>

TEST_CASE("check write and read string", "[write and read]")
{
	int randomNum = rand();

	Umbrella::FileSystem::Write("filesystem.txt", std::to_string(randomNum) + "teste1");
	Umbrella::FileSystem::Write("filesystem.txt", std::to_string(randomNum) + "teste2");
	Umbrella::FileSystem::Write("filesystem.txt", std::to_string(randomNum) + "teste3");

	std::string result = Umbrella::FileSystem::Read("filesystem.txt");

	REQUIRE(result == std::to_string(randomNum)+"teste3");
}

