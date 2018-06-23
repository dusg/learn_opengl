#include_directories(/usr/local/include)
include_directories(/usr/local/Cellar/glfw/3.2.1/include/)
find_library(lib libglfw.3.2.dylib)
link_libraries(libglfw.3.2.dylib)