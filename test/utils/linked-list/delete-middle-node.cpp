#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/delete-middle-node.h"

TEST(deleteMiddleNode, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 0);
}

TEST(deleteMiddleNode, with_one_element)
{
    datastructures::LinkedList<int> list;

    list.append(2);
    EXPECT_EQ(list.size(), 1);

    utils::linkedList::deleteMiddleNode(list);
    EXPECT_EQ(list.size(), 0);
}

TEST(deleteMiddleNode, with_three_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);

    EXPECT_EQ(list.size(), 3);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    EXPECT_EQ(list.get(2), 2);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 2);
}

TEST(deleteMiddleNode, with_four_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.size(), 4);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    EXPECT_EQ(list.get(2), 2);
    EXPECT_EQ(list.get(3), 3);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 3);
}

TEST(deleteMiddleNode, with_nine_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);

    EXPECT_EQ(list.size(), 9);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    EXPECT_EQ(list.get(2), 2);
    EXPECT_EQ(list.get(3), 3);
    EXPECT_EQ(list.get(4), 4);
    EXPECT_EQ(list.get(5), 5);
    EXPECT_EQ(list.get(6), 6);
    EXPECT_EQ(list.get(7), 7);
    EXPECT_EQ(list.get(8), 8);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 8);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    EXPECT_EQ(list.get(2), 2);
    EXPECT_EQ(list.get(3), 3);
    EXPECT_EQ(list.get(4), 5);
    EXPECT_EQ(list.get(5), 6);
    EXPECT_EQ(list.get(6), 7);
    EXPECT_EQ(list.get(7), 8);
}

TEST(deleteMiddleNode, with_ten_elements)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);

    EXPECT_EQ(list.size(), 10);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    EXPECT_EQ(list.get(2), 2);
    EXPECT_EQ(list.get(3), 3);
    EXPECT_EQ(list.get(4), 4);
    EXPECT_EQ(list.get(5), 5);
    EXPECT_EQ(list.get(6), 6);
    EXPECT_EQ(list.get(7), 7);
    EXPECT_EQ(list.get(8), 8);
    EXPECT_EQ(list.get(9), 9);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 8);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    EXPECT_EQ(list.get(2), 2);
    EXPECT_EQ(list.get(3), 3);
    EXPECT_EQ(list.get(5), 6);
    EXPECT_EQ(list.get(6), 7);
    EXPECT_EQ(list.get(7), 8);
    EXPECT_EQ(list.get(8), 9);
}