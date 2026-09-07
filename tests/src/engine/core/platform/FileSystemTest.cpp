#include <catch2/catch_test_macros.hpp>
#include "../../../../../src/engine/core/platform/FileSystem.h"
#include <cstdlib>

TEST_CASE("check write and read string", "[write and read]")
{
	srand(time(0));
	int randomNum = rand();
	std::string path = "Testing/Temporary/filesystem.txt";

	Umbrella::FileSystem::Write(path, std::to_string(randomNum) + "teste3");

	std::string result = Umbrella::FileSystem::Read(path);

	REQUIRE(result == std::to_string(randomNum)+"teste3");
}

