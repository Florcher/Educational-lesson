list(APPEND SOURCE_FILES
Renderer.h 
Window.h
Renderer.cpp
main.cpp
)

add_executable(projectWin32 ${SOURCE_FILES})

target_link_libraries(projectWin32 kernel gdiplus.lib)