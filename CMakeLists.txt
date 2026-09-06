cmake_minimum_required (VERSION 3.10)

project (game VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory ("src/engine/core")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_subdirectory ("thirdparty/catch2")
endif()


if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_executable (game "src/main.cpp" "src/engine/UmbrellaRoot.h" "src/engine/UmbrellaRoot.cpp" )
else()
	add_executable (game WIN32 "src/main.cpp" "src/engine/UmbrellaRoot.h" "src/engine/UmbrellaRoot.cpp")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_link_libraries(game PRIVATE core)
else()
	target_link_libraries(game PRIVATE core)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(game PRIVATE BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(game PRIVATE BUILD_RELEASE)
endif()

enable_testing()
include(CTest)
include(Catch)

add_executable(unit_tests "tests/src/engine/core/RenderWindowTest.cpp" "tests/src/engine/core/platform/FileSystemTest.cpp")
target_link_libraries(unit_tests PRIVATE core Catch2::Catch2WithMain)

catch_discover_tests(unit_tests)
