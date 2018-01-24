#include "gtest/gtest.h"
#include "data-structures/stack/stack-array.h"

TEST(stack_array, push_peek)
{
    datastructures::StackArray<double> stack;

    stack.push_back(2);
    ASSERT_EQ(stack.peek(), 2);

    stack.push_back(4);
    ASSERT_EQ(stack.peek(), 4);

    stack.push_back(7);
    ASSERT_EQ(stack.peek(), 7);
}

TEST(stack_array, push_pop)
{
    datastructures::StackArray<double> stack;

    stack.push_back(2);
    ASSERT_EQ(stack.pop(), 2);

    stack.push_back(0);
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(4);
    ASSERT_EQ(stack.pop(), 4);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
    ASSERT_EQ(stack.pop(), 0);

    ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST(stack_array, isEmpty)
{
    datastructures::StackArray<double> stack;

    ASSERT_EQ(stack.isEmpty(), true);
    stack.push_back(2);
    ASSERT_EQ(stack.isEmpty(), false);
    stack.pop();
    ASSERT_EQ(stack.isEmpty(), true);
}
