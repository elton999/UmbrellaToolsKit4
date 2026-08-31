#include <catch2/catch_test_macros.hpp>
#include "../../../../src/engine/core/RenderManager.h"

TEST_CASE("init without any integration", "[StartUp][backend == null]")
{
	RenderManager renderManager = {};
	renderManager.StartUp();
	REQUIRE(renderManager.BackendIntegration == NULL);
}

TEST_CASE("Is runnig without any integration", "[IsRunnig][backend == null]")
{
	RenderManager renderManager = {};
	renderManager.StartUp();
	REQUIRE_FALSE(renderManager.IsRunning());
}
