#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/find-element-from-tail.h"

TEST(getNthValueFromTail, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    ASSERT_ANY_THROW(utils::linkedList::getNthValueFromTail(list, 0));
}

TEST(getNthValueFromTail_class, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    ASSERT_ANY_THROW(list.getNthValueFromTail(0));
}


TEST(getNthValueFromTail_class, last_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 4);

    EXPECT_EQ(list.getNthValueFromTail(0), 3);
}

TEST(getNthValueFromTail, last_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 4);

    EXPECT_EQ(utils::linkedList::getNthValueFromTail(list, 0), 3);
}

TEST(findNthElementFromTail, last_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(utils::linkedList::findNthElementFromTail(list, 0), 3);
}

TEST(findNthElementFromTail, middle_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(utils::linkedList::findNthElementFromTail(list, 2), 1);
}

TEST(findNthElementFromTail, first_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(utils::linkedList::findNthElementFromTail(list, 3), 0);
}

TEST(findNthElementFromTail, out_of_range)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    ASSERT_ANY_THROW(utils::linkedList::findNthElementFromTail(list, 10));
}
