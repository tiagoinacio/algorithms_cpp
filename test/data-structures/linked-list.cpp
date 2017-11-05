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

TEST(linked_list, reset)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_EQ(linkedList.size(), 0);

    linkedList.append(2);
    linkedList.append(5);
    ASSERT_EQ(linkedList.size(), 2);

    ASSERT_EQ(linkedList.get(0), 2);
    ASSERT_EQ(linkedList.get(1), 5);

    linkedList.reset();
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

TEST(linked_list, delete_element_at_middle_position)
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

    linkedList.deleteElementAtPosition(4);

    ASSERT_EQ(linkedList.size(), 8);
    ASSERT_EQ(linkedList.get(4), 5);
    ASSERT_EQ(linkedList.get(6), 7);
}

TEST(linked_list, delete_element_at_start_position)
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
    ASSERT_EQ(linkedList.get(0), 0);

    linkedList.deleteElementAtPosition(0);

    ASSERT_EQ(linkedList.size(), 8);
    ASSERT_EQ(linkedList.get(0), 1);
}

TEST(linked_list, delete_element_at_end_position)
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
    ASSERT_EQ(linkedList.get(0), 0);

    linkedList.deleteElementAtPosition(9);

    ASSERT_EQ(linkedList.size(), 8);
}

TEST(linked_list, insert_at_middle_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.append(0);
    linkedList.append(1);
    linkedList.append(2);

    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 1);
    ASSERT_EQ(linkedList.get(2), 2);
    ASSERT_ANY_THROW(linkedList.get(3));

    linkedList.insertAtPosition(1, 9);

    ASSERT_EQ(linkedList.size(), 4);
    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 9);
    ASSERT_EQ(linkedList.get(2), 1);
    ASSERT_EQ(linkedList.get(3), 2);
    ASSERT_ANY_THROW(linkedList.get(4));
}

TEST(linked_list, insert_at_tail_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.append(0);
    linkedList.append(1);

    ASSERT_EQ(linkedList.size(), 2);
    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 1);
    ASSERT_ANY_THROW(linkedList.get(2));

    linkedList.insertAtPosition(1, 2);

    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 2);
    ASSERT_EQ(linkedList.get(2), 1);
    ASSERT_ANY_THROW(linkedList.get(3));
}

TEST(linked_list, insert_at_head_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.append(0);
    linkedList.append(1);

    ASSERT_EQ(linkedList.size(), 2);
    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 1);
    ASSERT_ANY_THROW(linkedList.get(2));

    linkedList.insertAtPosition(0, 2);

    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.get(0), 2);
    ASSERT_EQ(linkedList.get(1), 0);
    ASSERT_EQ(linkedList.get(2), 1);
    ASSERT_ANY_THROW(linkedList.get(3));
}

TEST(linked_list, copy_constructor)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.append(0);
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);

    ASSERT_EQ(linkedList.size(), 5);

    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 1);
    ASSERT_EQ(linkedList.get(2), 2);
    ASSERT_EQ(linkedList.get(3), 3);
    ASSERT_EQ(linkedList.get(4), 4);

    datastructures::LinkedList<double> copiedLinkedList(linkedList);

    ASSERT_EQ(copiedLinkedList.size(), 5);

    ASSERT_EQ(copiedLinkedList.get(0), 0);
    ASSERT_EQ(copiedLinkedList.get(1), 1);
    ASSERT_EQ(copiedLinkedList.get(2), 2);
    ASSERT_EQ(copiedLinkedList.get(3), 3);
    ASSERT_EQ(copiedLinkedList.get(4), 4);
}

TEST(linked_list, assignment_operator)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.append(0);
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);

    ASSERT_EQ(linkedList.size(), 5);

    ASSERT_EQ(linkedList.get(0), 0);
    ASSERT_EQ(linkedList.get(1), 1);
    ASSERT_EQ(linkedList.get(2), 2);
    ASSERT_EQ(linkedList.get(3), 3);
    ASSERT_EQ(linkedList.get(4), 4);

    datastructures::LinkedList<double> copiedLinkedList;

    ASSERT_EQ(copiedLinkedList.size(), 0);

    copiedLinkedList = linkedList;

    ASSERT_EQ(copiedLinkedList.size(), 5);

    ASSERT_EQ(copiedLinkedList.get(0), 0);
    ASSERT_EQ(copiedLinkedList.get(1), 1);
    ASSERT_EQ(copiedLinkedList.get(2), 2);
    ASSERT_EQ(copiedLinkedList.get(3), 3);
    ASSERT_EQ(copiedLinkedList.get(4), 4);
}