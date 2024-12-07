set(HEADER ComparisonTests.h
DataBaseTests.h
FilerTests.h
InputTests.h
Myassert.h
ObjectsTests.h
Tests.h
WasException.h)

set(SOURCE ComparisonTests.cpp
DataBaseTests.cpp
FilerTests.cpp
InputTests.cpp
main.cpp
ObjectsTests.cpp
Tests.cpp)

list(APPEND SOURCE_FILES
${SOURCE}
${HEADER}
)

add_executable(tests ${SOURCE_FILES})

target_link_libraries(tests kernel)