
set(CMAKE_CXX_STANDARD 11)

include_directories(./)

include(../wxWidgetsCmakeConfig.cmake)
include(../boostCmakeConfig.cmake)
include(../openglConfig.cmake)
FILE(GLOB SRCS "*.cpp" "*.h" ${PROJECT_SOURCE_DIR}/glad/src/glad.c)

SET(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)
add_library(opengl SHARED ${SRCS} gl_shader.h ShaderStore.cpp ShaderStore.h gl_shader_program.h gl_vertex_array.h gl_object.h gl_context.h gl_clearner.h gl_enum.h)
