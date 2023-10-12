cmake_minimum_required(VERSION 3.27.7)
project(data-struct-algorithm)

# 设置C++标准
set(CMAKE_CXX_STANDARD 23)

# 添加ExternalProject模块
include(ExternalProject)

# 定义gtest的下载和构建过程
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/gtest-install
)

# 添加可执行文件的子目录
add_subdirectory(src)
add_subdirectory(test)

# 链接gtest库
link_directories(${CMAKE_CURRENT_BINARY_DIR}/gtest-install/lib)
