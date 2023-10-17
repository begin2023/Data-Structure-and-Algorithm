cmake_minimum_required(VERSION 3.22)

project(code-test)

set(CMAKE_CXX_STANDARD  23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

include_directories(${CMAKE_SOURCE_DIR}/src)


add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(third_party)