#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/partition.h"

TEST(partition, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    utils::linkedList::partition(list, 0);

    EXPECT_EQ(list.size(), 0);
}
