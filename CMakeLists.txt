cmake_minimum_required (VERSION 3.10)

project (game VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory ("thirdparty/glm")
add_subdirectory ("thirdparty/glfw")
add_subdirectory ("thirdparty/glad")
add_subdirectory ("thirdparty/imgui_lib")

add_executable (game "src/main.cpp" )


target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glm glfw glad imgui)
