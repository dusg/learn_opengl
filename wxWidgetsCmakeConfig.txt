include_directories(/usr/local/lib/wx/include/osx_cocoa-unicode-3.0)
include_directories(/usr/local/include/wx-3.0)
link_directories(/usr/local/lib)

add_definitions(-D_FILE_OFFSET_BITS=64 -DwxDEBUG_LEVEL=0 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__)
#FIND_LIBRARY(COCOA_LIBRARY Cocoa IOKit Carbon AudioToolbox System OpenGL wx_baseu-3.0 wx_baseu_net-3.0 wx_baseu_xml-3.0 wx_osx_cocoau_core-3.0 wx_osx_cocoau_adv-3.0 wx_osx_cocoau_qa-3.0 wx_osx_cocoau_xrc-3.0 wx_osx_cocoau_webview-3.0 wx_osx_cocoau_html-3.0)
find_library(COCOA_LIBRARY1 Cocoa)
link_libraries(${COCOA_LIBRARY1})

find_library(COCOA_LIBRARY2 IOKit)
link_libraries(${COCOA_LIBRARY2})

find_library(COCOA_LIBRARY3 Carbon)
link_libraries(${COCOA_LIBRARY3})

find_library(COCOA_LIBRARY4 AudioToolbox)
link_libraries(${COCOA_LIBRARY4})

find_library(COCOA_LIBRARY5 System)
link_libraries(${COCOA_LIBRARY5})

find_library(COCOA_LIBRARY6 OpenGL)
link_libraries(${COCOA_LIBRARY6})

find_library(wxlib1 wx_osx_cocoau_xrc-3.0 )
link_libraries(${wxlib1})

find_library(wxlib2 wx_osx_cocoau_webview-3.0 )
link_libraries(${wxlib2})

find_library(wxlib3 wx_osx_cocoau_html-3.0 )
link_libraries(${wxlib3})

find_library(wxlib4 wx_osx_cocoau_qa-3.0 )
link_libraries(${wxlib4})

find_library(wxlib5 wx_osx_cocoau_adv-3.0 )
link_libraries(${wxlib5})

find_library(wxlib6 wx_osx_cocoau_core-3.0 )
link_libraries(${wxlib6})

find_library(wxlib7 wx_baseu_xml-3.0 )
link_libraries(${wxlib7})

link_libraries(libwx_baseu_net-3.0.dylib)

link_libraries(libwx_osx_cocoau_gl-3.0.dylib)

message(${wxlib9})

find_library(wxlib10 wx_baseu-3.0)
link_libraries(${wxlib10})