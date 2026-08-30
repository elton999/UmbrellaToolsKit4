cmake_minimum_required (VERSION 3.10)

project (game VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory ("src/engine/core")

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_executable (game "src/main.cpp")
else()
	add_executable (game WIN32 "src/main.cpp" )
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
