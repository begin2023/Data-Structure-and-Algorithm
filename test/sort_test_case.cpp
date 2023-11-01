#include "sort/sort.h"
#include "gtest/gtest.h"

namespace Test {
TEST(sort, bubble)
{
    int data[6U] = {3, 5, 7, 7, 9, 1};
    int exp[6U] = {1, 3, 5, 7, 7, 9};
    Sort::BubbleSort(data, std::size(data));
    EXPECT_TRUE(std::equal(data, data + std::size(data), exp));
}
}   // namespace Test