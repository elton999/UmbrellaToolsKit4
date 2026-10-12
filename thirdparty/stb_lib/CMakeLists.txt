cmake_minimum_required(VERSION 3.10)
project(stbi)

add_library(stbi INTERFACE)
target_sources(stbi PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/stb/stb_image.h")

target_include_directories(stbi INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/stb")

target_link_libraries(stbi)