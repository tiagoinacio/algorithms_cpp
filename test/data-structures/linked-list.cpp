#include "gtest/gtest.h"
#include "data-structures/linked-list.h"

TEST(linked_list, one_value)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.append(2);

    ASSERT_EQ(linkedList.get(0), 2);
}

TEST(linked_list, append_get)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.append(2);
    linkedList.append(5);
    linkedList.append(7);
    linkedList.append(15);
    linkedList.append(20);
    linkedList.append(25);

    ASSERT_EQ(linkedList.get(0), 2);
    ASSERT_EQ(linkedList.get(1), 5);
    ASSERT_EQ(linkedList.get(2), 7);
    ASSERT_EQ(linkedList.get(3), 15);
    ASSERT_EQ(linkedList.get(4), 20);
    ASSERT_EQ(linkedList.get(5), 25);
}

TEST(linked_list, clear)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_EQ(linkedList.size(), 0);

    linkedList.append(2);
    linkedList.append(5);
    ASSERT_EQ(linkedList.size(), 2);

    ASSERT_EQ(linkedList.get(0), 2);
    ASSERT_EQ(linkedList.get(1), 5);

    linkedList.clear();
    ASSERT_EQ(linkedList.size(), 0);

    linkedList.append(50);
    ASSERT_EQ(linkedList.size(), 1);
    ASSERT_EQ(linkedList.get(0), 50);
}

TEST(linked_list, preppend)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_EQ(linkedList.size(), 0);

    linkedList.append(2);
    linkedList.append(5);

    ASSERT_EQ(linkedList.size(), 2);
    ASSERT_EQ(linkedList.get(0), 2);
    ASSERT_EQ(linkedList.get(1), 5);

    linkedList.preppend(7);
    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.get(0), 7);
    ASSERT_EQ(linkedList.get(1), 2);
    ASSERT_EQ(linkedList.get(2), 5);
}

TEST(linked_list, get)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_ANY_THROW(linkedList.get(1));
}

TEST(linked_list, delete_element)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.append(0);
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);
    linkedList.append(5);
    linkedList.append(6);
    linkedList.append(7);
    linkedList.append(8);

    ASSERT_EQ(linkedList.size(), 9);
    ASSERT_EQ(linkedList.get(4), 4);

    linkedList.deleteElement(4);

    ASSERT_EQ(linkedList.size(), 8);
    ASSERT_EQ(linkedList.get(4), 5);
    ASSERT_EQ(linkedList.get(6), 7);
}