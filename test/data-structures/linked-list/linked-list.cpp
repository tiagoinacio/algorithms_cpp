#include "gtest/gtest.h"
#include "data-structures/linked-list/linked-list.h"

TEST(linked_list, one_value)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(2);

    ASSERT_EQ(linkedList.value_at(0), 2);
}

TEST(linked_list, empty)
{
    datastructures::LinkedList<double> linkedList;

    ASSERT_EQ(linkedList.empty(), true);

    linkedList.push_back(0);
    ASSERT_EQ(linkedList.empty(), false);
}

TEST(linked_list, push_back)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(2);
    linkedList.push_back(5);
    linkedList.push_back(7);
    linkedList.push_back(15);
    linkedList.push_back(20);
    linkedList.push_back(25);

    ASSERT_EQ(linkedList.value_at(0), 2);
    ASSERT_EQ(linkedList.value_at(1), 5);
    ASSERT_EQ(linkedList.value_at(2), 7);
    ASSERT_EQ(linkedList.value_at(3), 15);
    ASSERT_EQ(linkedList.value_at(4), 20);
    ASSERT_EQ(linkedList.value_at(5), 25);
}

TEST(linked_list, pop_front)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(2);
    ASSERT_EQ(linkedList.value_at(0), 2);

    ASSERT_EQ(linkedList.pop_front(), 2);
    ASSERT_THROW(linkedList.pop_front(), std::out_of_range);
}

TEST(linked_list, pop_back)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    ASSERT_EQ(linkedList.pop_back(), 3);
    ASSERT_EQ(linkedList.pop_back(), 2);
    ASSERT_EQ(linkedList.pop_back(), 1);
    ASSERT_THROW(linkedList.pop_front(), std::out_of_range);
}

TEST(linked_list, back)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    ASSERT_EQ(linkedList.back(), 3);

    linkedList.push_back(4);
    ASSERT_EQ(linkedList.back(), 4);

    linkedList.push_back(5);
    ASSERT_EQ(linkedList.back(), 5);

    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();
    ASSERT_THROW(linkedList.back(), std::out_of_range);
}

TEST(linked_list, front)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(1);
    ASSERT_EQ(linkedList.front(), 1);

    linkedList.push_back(4);
    ASSERT_EQ(linkedList.front(), 1);

    linkedList.push_back(5);
    ASSERT_EQ(linkedList.front(), 1);

    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();
    ASSERT_THROW(linkedList.front(), std::out_of_range);
}

TEST(linked_list, push_front)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_EQ(linkedList.size(), 0);

    linkedList.push_back(2);
    linkedList.push_back(5);

    ASSERT_EQ(linkedList.size(), 2);
    ASSERT_EQ(linkedList.value_at(0), 2);
    ASSERT_EQ(linkedList.value_at(1), 5);

    linkedList.push_front(7);
    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.value_at(0), 7);
    ASSERT_EQ(linkedList.value_at(1), 2);
    ASSERT_EQ(linkedList.value_at(2), 5);
}

TEST(linked_list, get)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_ANY_THROW(linkedList.value_at(1));
}

TEST(linked_list, delete_element_at_middle_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);
    linkedList.push_back(5);
    linkedList.push_back(6);
    linkedList.push_back(7);
    linkedList.push_back(8);

    ASSERT_EQ(linkedList.size(), 9);
    ASSERT_EQ(linkedList.value_at(4), 4);

    linkedList.erase(4);

    ASSERT_EQ(linkedList.size(), 8);
    ASSERT_EQ(linkedList.value_at(4), 5);
    ASSERT_EQ(linkedList.value_at(6), 7);
}

TEST(linked_list, delete_element_at_start_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);
    linkedList.push_back(5);
    linkedList.push_back(6);
    linkedList.push_back(7);
    linkedList.push_back(8);

    ASSERT_EQ(linkedList.size(), 9);
    ASSERT_EQ(linkedList.value_at(0), 0);

    linkedList.erase(0);

    ASSERT_EQ(linkedList.size(), 8);
    ASSERT_EQ(linkedList.value_at(0), 1);
}

TEST(linked_list, delete_element_at_end_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);
    linkedList.push_back(5);
    linkedList.push_back(6);
    linkedList.push_back(7);
    linkedList.push_back(8);

    ASSERT_EQ(linkedList.size(), 9);
    ASSERT_EQ(linkedList.value_at(0), 0);

    linkedList.erase(9);

    ASSERT_EQ(linkedList.size(), 8);
}

TEST(linked_list, reverse)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);
    linkedList.push_back(5);

    EXPECT_EQ(linkedList.value_at(0), 0);
    EXPECT_EQ(linkedList.value_at(1), 1);
    EXPECT_EQ(linkedList.value_at(2), 2);
    EXPECT_EQ(linkedList.value_at(3), 3);
    EXPECT_EQ(linkedList.value_at(4), 4);
    EXPECT_EQ(linkedList.value_at(5), 5);

    linkedList.reverse();

    EXPECT_EQ(linkedList.value_at(0), 5);
    EXPECT_EQ(linkedList.value_at(1), 4);
    EXPECT_EQ(linkedList.value_at(2), 3);
    EXPECT_EQ(linkedList.value_at(3), 2);
    EXPECT_EQ(linkedList.value_at(4), 1);
    EXPECT_EQ(linkedList.value_at(5), 0);
}

TEST(linked_list, removeValue)
{
    datastructures::LinkedList<double> linkedList;

    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(2);
    linkedList.push_back(5);

    EXPECT_EQ(linkedList.value_at(0), 0);
    EXPECT_EQ(linkedList.value_at(1), 1);
    EXPECT_EQ(linkedList.value_at(2), 1);
    EXPECT_EQ(linkedList.value_at(3), 2);
    EXPECT_EQ(linkedList.value_at(4), 2);
    EXPECT_EQ(linkedList.value_at(5), 5);

    linkedList.removeValue(1);

    EXPECT_EQ(linkedList.value_at(0), 0);
    EXPECT_EQ(linkedList.value_at(1), 1);
    EXPECT_EQ(linkedList.value_at(2), 2);
    EXPECT_EQ(linkedList.value_at(3), 2);
    EXPECT_EQ(linkedList.value_at(4), 5);

    linkedList.removeValue(1);

    EXPECT_EQ(linkedList.value_at(0), 0);
    EXPECT_EQ(linkedList.value_at(1), 2);
    EXPECT_EQ(linkedList.value_at(2), 2);
    EXPECT_EQ(linkedList.value_at(3), 5);

    linkedList.removeValue(0);
    // there are two nodes with value 2 but we are only remove one
    linkedList.removeValue(2);
    linkedList.removeValue(5);
    // this value does not exist in the list
    linkedList.removeValue(3);

    EXPECT_EQ(linkedList.size(), 1);
    EXPECT_EQ(linkedList.value_at(0), 2);
}

TEST(linked_list, insert_out_of_range)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_THROW(linkedList.insert(90, 90), std::out_of_range);
}

TEST(linked_list, pop_back_out_of_range)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_THROW(linkedList.pop_back(), std::out_of_range);
}

TEST(linked_list, erase_out_of_range)
{
    datastructures::LinkedList<double> linkedList;
    ASSERT_THROW(linkedList.erase(40), std::out_of_range);
}

TEST(linked_list, insert_at_middle_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);

    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 1);
    ASSERT_EQ(linkedList.value_at(2), 2);
    ASSERT_ANY_THROW(linkedList.value_at(3));

    linkedList.insert(1, 9);

    ASSERT_EQ(linkedList.size(), 4);
    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 9);
    ASSERT_EQ(linkedList.value_at(2), 1);
    ASSERT_EQ(linkedList.value_at(3), 2);
    ASSERT_ANY_THROW(linkedList.value_at(4));
}

TEST(linked_list, insert_at_tail_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);

    ASSERT_EQ(linkedList.size(), 2);
    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 1);
    ASSERT_ANY_THROW(linkedList.value_at(2));

    linkedList.insert(1, 2);

    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 2);
    ASSERT_EQ(linkedList.value_at(2), 1);
    ASSERT_ANY_THROW(linkedList.value_at(3));
}

TEST(linked_list, insert_at_head_position)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);

    ASSERT_EQ(linkedList.size(), 2);
    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 1);
    ASSERT_ANY_THROW(linkedList.value_at(2));

    linkedList.insert(0, 2);

    ASSERT_EQ(linkedList.size(), 3);
    ASSERT_EQ(linkedList.value_at(0), 2);
    ASSERT_EQ(linkedList.value_at(1), 0);
    ASSERT_EQ(linkedList.value_at(2), 1);
    ASSERT_ANY_THROW(linkedList.value_at(3));
}

TEST(linked_list, copy_constructor)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);

    ASSERT_EQ(linkedList.size(), 5);

    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 1);
    ASSERT_EQ(linkedList.value_at(2), 2);
    ASSERT_EQ(linkedList.value_at(3), 3);
    ASSERT_EQ(linkedList.value_at(4), 4);

    datastructures::LinkedList<double> copiedLinkedList(linkedList);

    ASSERT_EQ(copiedLinkedList.size(), 5);

    ASSERT_EQ(copiedLinkedList.value_at(0), 0);
    ASSERT_EQ(copiedLinkedList.value_at(1), 1);
    ASSERT_EQ(copiedLinkedList.value_at(2), 2);
    ASSERT_EQ(copiedLinkedList.value_at(3), 3);
    ASSERT_EQ(copiedLinkedList.value_at(4), 4);
}

TEST(linked_list, assignment_operator)
{
    datastructures::LinkedList<double> linkedList;
    linkedList.push_back(0);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);

    ASSERT_EQ(linkedList.size(), 5);

    ASSERT_EQ(linkedList.value_at(0), 0);
    ASSERT_EQ(linkedList.value_at(1), 1);
    ASSERT_EQ(linkedList.value_at(2), 2);
    ASSERT_EQ(linkedList.value_at(3), 3);
    ASSERT_EQ(linkedList.value_at(4), 4);

    datastructures::LinkedList<double> copiedLinkedList;

    ASSERT_EQ(copiedLinkedList.size(), 0);

    copiedLinkedList = linkedList;

    ASSERT_EQ(copiedLinkedList.size(), 5);

    ASSERT_EQ(copiedLinkedList.value_at(0), 0);
    ASSERT_EQ(copiedLinkedList.value_at(1), 1);
    ASSERT_EQ(copiedLinkedList.value_at(2), 2);
    ASSERT_EQ(copiedLinkedList.value_at(3), 3);
    ASSERT_EQ(copiedLinkedList.value_at(4), 4);
}
