cmake_minimum_required(VERSION 3.10)

project(demo)

set(CMAKE_CXX_STANDARD 11)

include_directories(./)

include(../wxWidgetsCmakeConfig.txt)

#link_libraries(IOKit Carbon Cocoa AudioToolbox System OpenGL -lwx_osx_cocoau_xrc-3.0)
FILE(GLOB SRCS "*.cpp" "*.h")


add_executable(demo ${SRCS})
