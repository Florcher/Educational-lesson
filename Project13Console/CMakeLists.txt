set(HEADER AddOperationFactory.h
DataBaseOperations.h
ObjectAddOperation.h
ObjectOpreations.h
OperationFactory.h
OperationFactorys.h)

set(SOURCE AddOperationFactory.cpp
DataBaseOperations.cpp
ObjectAddOperation.cpp
ObjectOperations.cpp
OperationFactory.cpp
main.cpp)

list(APPEND SOURCE_FILES
${SOURCE}
${HEADER}
)

add_executable(consoleProject ${SOURCE_FILES})

target_link_libraries(consoleProject kernel)


