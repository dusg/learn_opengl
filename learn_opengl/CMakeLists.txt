cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
include(../boostCmakeConfig.cmake)
#include(../openglConfig.cmake)
include(../oglplusConfig.cmake)
include(../myGlfwConfig.cmake)
include(../gladConfig.cmake)
include_directories(./)

link_directories(${PROJECT_BINARY_DIR}/bin)



#link_libraries(IOKit Carbon Cocoa AudioToolbox System OpenGL -lwx_osx_cocoau_xrc-3.0)
FILE(GLOB SRCS "*.cpp" "*.h")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(learn_opengl ${SRCS} OpenGLApp.cpp OpenGLApp.h rectangle/Rectangle.cpp rectangle/Rectangle.h)