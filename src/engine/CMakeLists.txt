cmake_minimum_required(VERSION 3.10)
project(umbrella)

add_subdirectory("core")

add_library(umbrella)
target_sources(umbrella PRIVATE
 "UmbrellaRoot.h"
 "UmbrellaRoot.cpp"
 "resources/ResourceContentIntegration.h"
 "resources/ResourceManager.h"
 "resources/ResourceManager.cpp"
 "resources/TextResource.h"
 "resources/TextResource.cpp"
 "scene/Scene.h"
 "scene/Scene.cpp"
 "scene/SceneManager.h"
 "scene/SceneManager.cpp"
 "scene/GameObject.h"
 "scene/IComponent.h")

target_include_directories(umbrella PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

target_link_libraries(umbrella PUBLIC core glm glfw glad imgui)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(umbrella PRIVATE BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  target_compile_definitions(umbrella PRIVATE BUILD_RELEASE)
endif()
