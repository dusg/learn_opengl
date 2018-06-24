cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
include(../glfwConfig.cmake)
include(../gladConfig.cmake)

FILE(GLOB SRCS "Application.cpp" "Application.h")

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_library(myglfw SHARED ${SRCS} Sigleton.h)