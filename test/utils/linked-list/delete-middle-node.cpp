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

    list.push_back(2);
    EXPECT_EQ(list.size(), 1);

    utils::linkedList::deleteMiddleNode(list);
    EXPECT_EQ(list.size(), 0);
}

TEST(deleteMiddleNode, with_three_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);

    EXPECT_EQ(list.size(), 3);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 1);
    EXPECT_EQ(list.value_at(2), 2);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 2);
}

TEST(deleteMiddleNode, with_four_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 4);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 1);
    EXPECT_EQ(list.value_at(2), 2);
    EXPECT_EQ(list.value_at(3), 3);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 2);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 3);
}

TEST(deleteMiddleNode, with_nine_element)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    EXPECT_EQ(list.size(), 9);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 1);
    EXPECT_EQ(list.value_at(2), 2);
    EXPECT_EQ(list.value_at(3), 3);
    EXPECT_EQ(list.value_at(4), 4);
    EXPECT_EQ(list.value_at(5), 5);
    EXPECT_EQ(list.value_at(6), 6);
    EXPECT_EQ(list.value_at(7), 7);
    EXPECT_EQ(list.value_at(8), 8);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 8);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 1);
    EXPECT_EQ(list.value_at(2), 2);
    EXPECT_EQ(list.value_at(3), 3);
    EXPECT_EQ(list.value_at(4), 5);
    EXPECT_EQ(list.value_at(5), 6);
    EXPECT_EQ(list.value_at(6), 7);
    EXPECT_EQ(list.value_at(7), 8);
}

TEST(deleteMiddleNode, with_ten_elements)
{
    datastructures::LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);

    EXPECT_EQ(list.size(), 10);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 1);
    EXPECT_EQ(list.value_at(2), 2);
    EXPECT_EQ(list.value_at(3), 3);
    EXPECT_EQ(list.value_at(4), 4);
    EXPECT_EQ(list.value_at(5), 5);
    EXPECT_EQ(list.value_at(6), 6);
    EXPECT_EQ(list.value_at(7), 7);
    EXPECT_EQ(list.value_at(8), 8);
    EXPECT_EQ(list.value_at(9), 9);

    utils::linkedList::deleteMiddleNode(list);

    EXPECT_EQ(list.size(), 8);

    EXPECT_EQ(list.value_at(0), 0);
    EXPECT_EQ(list.value_at(1), 1);
    EXPECT_EQ(list.value_at(2), 2);
    EXPECT_EQ(list.value_at(3), 3);
    EXPECT_EQ(list.value_at(4), 6);
    EXPECT_EQ(list.value_at(5), 7);
    EXPECT_EQ(list.value_at(6), 8);
    EXPECT_EQ(list.value_at(7), 9);
}

TEST(deleteNode, with_one_element)
{
    datastructures::LinkedList<int> list;
    list.push_back(2);

    EXPECT_EQ(list.value_at(0), 2);

    gsl::not_null<datastructures::Node<int> *> ptrNode = list.head();

    ASSERT_ANY_THROW(utils::linkedList::deleteNode(ptrNode));
}

TEST(deleteNode, with_two_elements)
{
    datastructures::LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);

    EXPECT_EQ(list.value_at(0), 1);
    EXPECT_EQ(list.value_at(1), 2);

    gsl::not_null<datastructures::Node<int> *> ptrNode = list.head();
    utils::linkedList::deleteNode(ptrNode);

    EXPECT_EQ(list.value_at(0), 2);
    ASSERT_ANY_THROW(list.value_at(1));
}

TEST(deleteNode, delete_second_elem)
{
    datastructures::LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.value_at(0), 1);
    EXPECT_EQ(list.value_at(1), 2);
    EXPECT_EQ(list.value_at(2), 3);

    gsl::not_null<datastructures::Node<int> *> ptrNode = list.head();
    ptrNode = ptrNode->next;
    utils::linkedList::deleteNode(ptrNode);

    EXPECT_EQ(list.value_at(0), 1);
    EXPECT_EQ(list.value_at(1), 3);
    ASSERT_ANY_THROW(list.value_at(2));
}

TEST(deleteNode, delete_third_elem)
{
    datastructures::LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.value_at(0), 1);
    EXPECT_EQ(list.value_at(1), 2);
    EXPECT_EQ(list.value_at(2), 3);

    gsl::not_null<datastructures::Node<int> *> ptrNode = list.head();
    ptrNode = ptrNode->next->next;
    ASSERT_ANY_THROW(utils::linkedList::deleteNode(ptrNode));
}