cmake_minimum_required (VERSION 3.10)

project (game VERSION 0.1.0 LANGUAGES CXX)

add_executable (game "src/main.cpp" )

add_subdirectory ("thirdparty/glfw")
add_subdirectory ("thirdparty/glad")


target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glfw glad)