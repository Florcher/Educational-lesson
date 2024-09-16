list(APPEND SOURCE_FILES
Renderer.h 
Window.h
Renderer.cpp
main.cpp
)

add_executable(Win32App ${SOURCE_FILES})

target_link_libraries(Win32App kernel gdiplus.lib)