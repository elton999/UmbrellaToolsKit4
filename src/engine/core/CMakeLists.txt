cmake_minimum_required(VERSION 3.10)
project(core)

add_library(core)
target_sources(core PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/debug/log.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/debug/log.h")


target_include_directories(core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_link_libraries(core PRIVATE glm glfw glad imgui Catch2::Catch2WithMain)
else()
	target_link_libraries(core PRIVATE glm glfw glad)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(core PRIVATE BUILD_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(core PRIVATE BUILD_RELEASE)
endif()