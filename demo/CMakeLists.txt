cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
include(../wxWidgetsCmakeConfig.cmake)
include(../boostCmakeConfig.cmake)
include(../openglConfig.cmake)
include_directories(./)
link_directories(${PROJECT_BINARY_DIR}/bin)
message(${PROJECT_BINARY_DIR}/bin)


#link_libraries(IOKit Carbon Cocoa AudioToolbox System OpenGL -lwx_osx_cocoau_xrc-3.0)
FILE(GLOB SRCS "*.cpp" "*.h")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

link_libraries(opengl)
add_executable(demo ${SRCS})
