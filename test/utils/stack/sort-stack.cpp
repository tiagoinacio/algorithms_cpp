#include "gtest/gtest.h"
#include "data-structures/stack/stack-array.h"
#include "utils/stack/sort-stack.h"

TEST(sortStack, with_empty_stack)
{
    datastructures::StackArray<int> stack;

    EXPECT_EQ(stack.isEmpty(), true);

    // do not throw
    utils::stack::sort(stack);

    EXPECT_EQ(stack.isEmpty(), true);
}

TEST(sortStack, with_sorted_stack)
{
    datastructures::StackArray<int> stack;

    stack.push_back(4);
    stack.push_back(3);
    stack.push_back(2);
    stack.push_back(1);
    stack.push_back(0);

    utils::stack::sort(stack);

    EXPECT_EQ(stack.pop(), 0);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 4);
}

TEST(sortStack, with_unsorted_stack)
{
    datastructures::StackArray<int> stack;

    stack.push_back(1);
    stack.push_back(0);
    stack.push_back(3);
    stack.push_back(2);
    stack.push_back(4);
    stack.push_back(1);

    utils::stack::sort(stack);

    EXPECT_EQ(stack.pop(), 0);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 4);
}