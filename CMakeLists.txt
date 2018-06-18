cmake_minimum_required(VERSION 3.10)
project(OpenGL)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(demo)
add_subdirectory(cube)
add_subdirectory(opengl)

add_dependencies(demo opengl)
