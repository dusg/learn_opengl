cmake_minimum_required(VERSION 3.10)
project(OpenGL)

set(CMAKE_CXX_STANDARD 11)

set(src_dir ${PROJECT_SOURCE_DIR})
message(${src_dir})

add_subdirectory(demo)
add_subdirectory(cube)
add_subdirectory(opengl)
add_subdirectory(glfw_demo)
add_subdirectory(glfw)
add_dependencies(demo opengl)
