
set(CMAKE_CXX_STANDARD 11)

include_directories(./)

include(../wxWidgetsCmakeConfig.txt)
include(../boostCmakeConfig.txt)

FILE(GLOB SRCS "*.cpp" "*.h")

add_library(opengl ${SRCS} gl_shader.h ShaderStore.cpp ShaderStore.h gl_shader_program.h)
