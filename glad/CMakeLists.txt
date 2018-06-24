set(CMAKE_CXX_STANDARD 11)

include_directories(./include)


FILE(GLOB SRCS ${PROJECT_SOURCE_DIR}/glad/src/glad.c)

SET(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR}/bin)
add_library(glad SHARED ${SRCS})