
include_directories(/usr/local/include)
include_directories(${PROJECT_SOURCE_DIR}/glad/include)
link_directories(/usr/local/lib)
find_library(lib libglfw.3.2.dylib)
#message(${lib})
link_libraries(libglfw.3.2.dylib)