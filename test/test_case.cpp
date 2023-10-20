#include "list/undirectional_linked_list.h"
#include "gtest/gtest.h"

namespace Test {
TEST(list, basic_func)
{
    std::vector<int> v{2, 3, 4, 6, 1};
    List::TailList<int> list{v};
    list.ToString();
}

TEST(list, more)
{
    std::cout << "hello" << std::endl;
}
}   // namespace Test
