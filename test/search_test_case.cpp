#include "list/undirectional_linked_list.h"
#include "search/bsearch.h"
#include "gtest/gtest.h"

namespace Test {
TEST(search, binary)
{
    int arr[6] = {-1, 1, 2, 4, 7, 8};
    EXPECT_EQ(Search::Bsearch(arr, 0, 8), -1);
    EXPECT_EQ(Search::Bsearch(arr, 4, 8), -1);
    EXPECT_EQ(Search::Bsearch(arr, 6, 8), 5);
    EXPECT_EQ(Search::Bsearch(arr, 6, 4), 3);
}
}   // namespace Test
