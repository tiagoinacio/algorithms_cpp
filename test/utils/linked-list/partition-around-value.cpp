
#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/partition-around-value.h"

TEST(partitionAroundValue, with_empty_list)
{
    datastructures::LinkedList<int> list;

    ASSERT_ANY_THROW(utils::linkedList::partitionAroundValue(list, 5));
}

TEST(partitionAroundValue, out_of_range)
{
    datastructures::LinkedList<int> list;

    list.append(2);

    // do nothing
    utils::linkedList::partitionAroundValue(list, 5);

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), 2);
}

TEST(partitionAroundValue, partition_around_5)
{
    datastructures::LinkedList<int> list;

    list.append(3);
    list.append(5);
    list.append(8);
    list.append(5);
    list.append(10);
    list.append(2);
    list.append(1);

    EXPECT_EQ(list.size(), 7);

    // do nothing
    utils::linkedList::partitionAroundValue(list, 5);
    EXPECT_EQ(list.size(), 7);
    EXPECT_EQ(list.get(0), 3);
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(0), 2);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(0), 5);
    EXPECT_EQ(list.get(0), 5);
    EXPECT_EQ(list.get(0), 8);
}