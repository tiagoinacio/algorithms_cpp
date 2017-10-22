#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
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

    list.append(1);
    list.append(4);
    list.append(4);
    list.append(5);
    list.append(5);
    list.append(6);
    list.append(7);

    EXPECT_EQ(list.size(), 7);

    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 4);
    EXPECT_EQ(list.get(2), 4);
    EXPECT_EQ(list.get(3), 5);
    EXPECT_EQ(list.get(4), 5);
    EXPECT_EQ(list.get(5), 6);
    EXPECT_EQ(list.get(6), 7);

    utils::linkedList::removeDuplicates(list);

    EXPECT_EQ(list.size(), 5);

    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(1), 4);
    EXPECT_EQ(list.get(2), 5);
    EXPECT_EQ(list.get(3), 6);
    EXPECT_EQ(list.get(4), 7);
}
