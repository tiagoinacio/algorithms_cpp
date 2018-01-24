#include "gtest/gtest.h"
#include "data-structures/linked-list/linked-list.h"
#include "utils/linked-list/remove-duplicates.h"

TEST(removeDuplicates, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    utils::linkedList::removeDuplicates(list);

    EXPECT_EQ(list.size(), 0);
}

TEST(removeDuplicates, with_duplicates)
{
    datastructures::LinkedList<int> list;

    list.push_back(1);
    list.push_back(4);
    list.push_back(4);
    list.push_back(5);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    EXPECT_EQ(list.size(), 7);

    EXPECT_EQ(list.value_at(0), 1);
    EXPECT_EQ(list.value_at(1), 4);
    EXPECT_EQ(list.value_at(2), 4);
    EXPECT_EQ(list.value_at(3), 5);
    EXPECT_EQ(list.value_at(4), 5);
    EXPECT_EQ(list.value_at(5), 6);
    EXPECT_EQ(list.value_at(6), 7);

    utils::linkedList::removeDuplicates(list);

    EXPECT_EQ(list.size(), 5);

    EXPECT_EQ(list.value_at(0), 1);
    EXPECT_EQ(list.value_at(1), 4);
    EXPECT_EQ(list.value_at(2), 5);
    EXPECT_EQ(list.value_at(3), 6);
    EXPECT_EQ(list.value_at(4), 7);
}
