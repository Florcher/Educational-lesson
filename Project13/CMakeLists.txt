set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(public_headers Comparison.h
ContextIO.h
DataBase.h
DrawData.h
Drawer.h
Factorys.h
FileType.h
Input.h
InputFiler.h
LineSegment2D.h
ObjectFactory.h
Objects.h
Output.h
OutputFiler.h
TypeNamespace.h
Vector2D.h
Vectoriser.h)

list(APPEND SOURCE_FILES
${public_headers}
ContextIO.cpp
DataBase.cpp
DrawData.cpp
Drawer.cpp
Input.cpp
InputFiler.cpp
ObjectFactory.cpp
Objects.cpp
Output.cpp
OutputFiler.cpp
Vector2D.cpp
Vectoriser.cpp)

include(GenerateExportHeader)

add_library(kernel ${SOURCE_FILES})

target_include_directories(kernel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

generate_export_header(kernel)
