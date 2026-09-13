cmake_minimum_required(VERSION 3.10)
project(core)

set(THIRDPARTY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../thirdparty")

add_subdirectory("${THIRDPARTY_DIR}/glm" "${CMAKE_CURRENT_BINARY_DIR}/glm")
add_subdirectory("${THIRDPARTY_DIR}/glfw" "${CMAKE_CURRENT_BINARY_DIR}/glfw")
add_subdirectory("${THIRDPARTY_DIR}/glad" "${CMAKE_CURRENT_BINARY_DIR}/glad")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_subdirectory("${THIRDPARTY_DIR}/imgui_lib" "${CMAKE_CURRENT_BINARY_DIR}/imgui_lib")
endif()

add_library(core)
target_sources(core PRIVATE
"${CMAKE_CURRENT_SOURCE_DIR}/debug/log.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/debug/log.h"
"RenderWindow.h"
"RenderWindow.cpp"
"platform/graphics_wrappers/GraphicBackend.h"
"platform/graphics_wrappers/integrations/GlwfBackendIntegration.h"
"platform/graphics_wrappers/integrations/GlwfBackendIntegration.cpp"
"Timer.h"
"Timer.cpp"
"platform/FileSystem.h"
"platform/FileSystem.cpp"
 "UniqueId.h" "UniqueId.cpp")

target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

target_link_libraries(core PUBLIC glm glfw glad imgui)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(core PRIVATE BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  target_compile_definitions(core PRIVATE BUILD_RELEASE)
endif()
