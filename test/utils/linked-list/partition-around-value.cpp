
#include "gtest/gtest.h"
#include "data-structures/linked-list/linked-list.h"
#include "utils/linked-list/partition-around-value.h"

TEST(partitionAroundValue, with_empty_list)
{
    datastructures::LinkedList<int> list;

    ASSERT_ANY_THROW(utils::linkedList::partitionAroundValue(list.head(), 5));
}

TEST(partitionAroundValue, out_of_range)
{
    datastructures::LinkedList<int> list;

    list.push_back(2);

    utils::linkedList::partitionAroundValue(list.head(), 5);

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.value_at(0), 2);
}

TEST(partitionAroundValue, partition_around_5)
{
    datastructures::LinkedList<int> list;

    list.push_back(3);
    list.push_back(5);
    list.push_back(8);
    list.push_back(5);
    list.push_back(10);
    list.push_back(2);
    list.push_back(1);

    EXPECT_EQ(list.size(), 7);

    datastructures::LinkedList<int> expectedList = utils::linkedList::partitionAroundValue(list.head(), 5);

    EXPECT_EQ(expectedList.size(), 7);
    EXPECT_EQ(expectedList.value_at(0), 1);
    EXPECT_EQ(expectedList.value_at(1), 2);
    EXPECT_EQ(expectedList.value_at(2), 3);
    EXPECT_EQ(expectedList.value_at(3), 5);
    EXPECT_EQ(expectedList.value_at(4), 8);
    EXPECT_EQ(expectedList.value_at(5), 5);
    EXPECT_EQ(expectedList.value_at(6), 10);
}

TEST(partition, with_empty_list)
{
    datastructures::LinkedList<int> list;

    ASSERT_ANY_THROW(utils::linkedList::partition(list.head(), 5));
}

TEST(partition, out_of_range)
{
    datastructures::LinkedList<int> list;

    list.push_back(2);

    utils::linkedList::partition(list.head(), 5);

    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.value_at(0), 2);
}

TEST(partition, partition_around_5)
{
    datastructures::LinkedList<int> list;

    list.push_back(3);
    list.push_back(5);
    list.push_back(8);
    list.push_back(5);
    list.push_back(10);
    list.push_back(2);
    list.push_back(1);

    EXPECT_EQ(list.size(), 7);

    datastructures::Node<int> *expectedList = utils::linkedList::partition(list.head(), 5);

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
//
//     list.push_back(3);
//     list.push_back(5);
//     list.push_back(8);
//     list.push_back(5);
//     list.push_back(10);
//     list.push_back(2);
//     list.push_back(1);
//     list.push_back(11);
//     list.push_back(7);
//
//     EXPECT_EQ(list.size(), 9);
//
//     datastructures::Node<int> *expectedList = utils::linkedList::partition(list.head(), 6);
//
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
