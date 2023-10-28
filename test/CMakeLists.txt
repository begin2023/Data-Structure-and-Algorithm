# 设置 gtest 框架库的路径
set(GTEST_ROOT /usr/src/gtest)

# 查找 gtest 框架库并链接
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
link_libraries(${GTEST_LIBRARIES} pthread)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} cases)

add_executable(test_exe ${cases})

include_directories(${CMAKE_SOURCE_DIR}/src)

set_target_properties(test_exe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

link_libraries(test_exe gtest)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
