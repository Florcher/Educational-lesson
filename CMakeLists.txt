cmake_minimum_required(VERSION 3.2)
project(MyProject)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Kernel)
add_subdirectory(ConsoleApp)
add_subdirectory(Win32App)
add_subdirectory(QtApp)
