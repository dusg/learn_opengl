
include_directories(~/work/oglplus/include)
include_directories(~/work/oglplus/implement/)
include_directories(~/work/oglplus/example/)

#add_definitions(-DOGLPLUS_NO_GL)
add_definitions(-DOGLPLUS_NO_SITE_CONFIG)
add_definitions(-DOGLPLUS_USE_GL3_H=1)
add_definitions(-DOGLPLUS_USE_GLCOREARB_H=0)