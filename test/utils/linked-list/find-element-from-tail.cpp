#include "gtest/gtest.h"
#include "data-structures/linked-list.h"
#include "utils/linked-list/find-element-from-tail.h"

TEST(findElementFromTail, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    ASSERT_ANY_THROW(utils::linkedList::findElementFromTail(list, 0));
}

TEST(findElementFromTail_class, with_empty_list)
{
    datastructures::LinkedList<int> list;

    EXPECT_EQ(list.size(), 0);

    ASSERT_ANY_THROW(list.findElementFromTail(0));
}


TEST(findElementFromTail_class, last_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.size(), 4);

    EXPECT_EQ(list.findElementFromTail(0), 3);
}

TEST(findElementFromTail, last_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.size(), 4);

    EXPECT_EQ(utils::linkedList::findElementFromTail(list, 0), 3);
}

TEST(findNthElementFromTail, last_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(utils::linkedList::findNthElementFromTail(list, 0), 3);
}

TEST(findNthElementFromTail, middle_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(utils::linkedList::findNthElementFromTail(list, 2), 1);
}

TEST(findNthElementFromTail, first_element)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    EXPECT_EQ(utils::linkedList::findNthElementFromTail(list, 3), 0);
}

TEST(findNthElementFromTail, out_of_range)
{
    datastructures::LinkedList<int> list;

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    ASSERT_ANY_THROW(utils::linkedList::findNthElementFromTail(list, 10));
}