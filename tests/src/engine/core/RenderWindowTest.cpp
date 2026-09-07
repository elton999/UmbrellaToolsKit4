#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/core/RenderWindow.h"

TEST_CASE("init without any integration")
{
	Umbrella::RenderWindow renderWindow = {};
	renderWindow.StartUp();
	REQUIRE(renderWindow.BackendIntegration == NULL);
}

TEST_CASE("Is runnig without any integration")
{
	Umbrella::RenderWindow renderWindow = {};
	renderWindow.StartUp();
	REQUIRE_FALSE(renderWindow.IsRunning());
}
