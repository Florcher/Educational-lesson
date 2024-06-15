cmake_minimum_required(VERSION 3.29.3)
project(MyProject)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Project13)
add_subdirectory(Project13Console)
add_subdirectory(Project13Win32)
add_subdirectory(Project13Qt)
