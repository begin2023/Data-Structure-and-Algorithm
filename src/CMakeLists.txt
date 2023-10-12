# 添加可执行文件
add_executable(data-struct-algorithm main.cpp)

# 添加依赖
add_dependencies(data-struct-algorithm gtest)

# 链接gtest库
target_include_directories(data-struct-algorithm PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/gtest-install/include)
target_link_libraries(data-struct-algorithm PRIVATE gtest gtest_main)
