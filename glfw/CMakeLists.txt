cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
include(../glfwConfig.cmake)

FILE(GLOB SRCS "*.cpp" "*.h")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_library(myglfw ${SRCS})