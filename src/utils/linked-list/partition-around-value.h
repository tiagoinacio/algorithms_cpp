#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/partition-around-value.h"

TEST(partitionAroundValue, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);
}
