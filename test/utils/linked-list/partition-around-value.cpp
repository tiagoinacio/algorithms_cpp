
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

    datastructures::LinkedList<int> expectedList = utils::linkedList::partitionAroundValue(list, 5);

    EXPECT_EQ(expectedList.size(), 7);
    EXPECT_EQ(expectedList.get(0), 1);
    EXPECT_EQ(expectedList.get(1), 2);
    EXPECT_EQ(expectedList.get(2), 3);
    EXPECT_EQ(expectedList.get(3), 5);
    EXPECT_EQ(expectedList.get(4), 8);
    EXPECT_EQ(expectedList.get(5), 5);
    EXPECT_EQ(expectedList.get(6), 10);
}

TEST(partition, with_empty_list)
{
    datastructures::LinkedList<int> list;

    ASSERT_ANY_THROW(utils::linkedList::partition(list.getHead(), 5));
}

TEST(partition, out_of_range)
{
    datastructures::LinkedList<int> list;

    list.append(2);

    utils::linkedList::partition(list.getHead(), 5);

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), 2);
}

TEST(partition, partition_around_5)
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

    datastructures::Node<int> *expectedList = utils::linkedList::partition(list.getHead(), 5);

    EXPECT_EQ(expectedList->value, 3);
    EXPECT_EQ(expectedList->next->value, 2);
    EXPECT_EQ(expectedList->next->next->value, 1);
    EXPECT_EQ(expectedList->next->next->next->value, 5);
    EXPECT_EQ(expectedList->next->next->next->next->value, 8);
    EXPECT_EQ(expectedList->next->next->next->next->next->value, 5);
    EXPECT_EQ(expectedList->next->next->next->next->next->next->value, 10);
    EXPECT_EQ(expectedList->next->next->next->next->next->next->next, nullptr);
}

// TEST(partition, partition_around_6)
// {
//     datastructures::LinkedList<int> list;

//     list.append(3);
//     list.append(5);
//     list.append(8);
//     list.append(5);
//     list.append(10);
//     list.append(2);
//     list.append(1);
//     list.append(11);
//     list.append(7);

//     EXPECT_EQ(list.size(), 9);

//     datastructures::Node<int> *expectedList = utils::linkedList::partition(list.getHead(), 6);

//     EXPECT_EQ(expectedList->value, 3);
//     EXPECT_EQ(expectedList->next->value, 5);
//     EXPECT_EQ(expectedList->next->next->value, 5);
//     EXPECT_EQ(expectedList->next->next->next->value, 2);
//     EXPECT_EQ(expectedList->next->next->next->next->value, 1);
//     EXPECT_EQ(expectedList->next->next->next->next->next->value, 8);
//     EXPECT_EQ(expectedList->next->next->next->next->next->next->value, 10);
//     EXPECT_EQ(expectedList->next->next->next->next->next->next->next->value, 11);
//     EXPECT_EQ(expectedList->next->next->next->next->next->next->next->next->value, 7);
//     EXPECT_EQ(expectedList->next->next->next->next->next->next->next->next->next, nullptr);
// }
