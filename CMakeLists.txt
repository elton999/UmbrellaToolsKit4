cmake_minimum_required (VERSION 3.10)

project (game VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory ("thirdparty/glm")
add_subdirectory ("thirdparty/glfw")
add_subdirectory ("thirdparty/glad")


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_subdirectory ("thirdparty/imgui_lib")
	add_subdirectory ("thirdparty/catch2")
endif()

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_executable (game "src/main.cpp"  "src/engine/core/debug/Log.h" "src/engine/core/debug/Log.cpp")
else()
	add_executable (game WIN32 "src/main.cpp" )
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_link_libraries(game PRIVATE glm glfw glad imgui Catch2::Catch2WithMain)
else()
	target_link_libraries(game PRIVATE glm glfw glad)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(game PRIVATE BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(game PRIVATE BUILD_RELEASE)
endif()

include(CTest)
include(Catch)