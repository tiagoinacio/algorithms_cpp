
#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/sum-lists.h"

TEST(sumLists, with_empty_lists)
{
    datastructures::LinkedList<int> first;
    datastructures::LinkedList<int> second;
    datastructures::LinkedList<int> sum = utils::linkedList::sumLists(first, second);

    EXPECT_EQ(sum.size(), 0);
}