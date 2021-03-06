#include "gtest/gtest.h"
#include "data-structures/stack/dynamic-multi-stack.h"

TEST(dynamic_multi_stack, push_peek)
{
    datastructures::DynamicMultiStack<double> stack {};

    stack.push_back(2);
    ASSERT_EQ(stack.peek(), 2);

    stack.push_back(4);
    ASSERT_EQ(stack.peek(), 4);

    stack.push_back(7);
    ASSERT_EQ(stack.peek(), 7);
}

TEST(dynamic_multi_stack, push_pop)
{
    datastructures::DynamicMultiStack<double> stack {};

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

    stack.push_back(0);
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);
    stack.push_back(4);
    stack.push_back(5);
    stack.push_back(6);
    stack.push_back(7);
    ASSERT_EQ(stack.pop(), 7);
    ASSERT_EQ(stack.pop(), 6);
    ASSERT_EQ(stack.pop(), 5);
    ASSERT_EQ(stack.pop(), 4);
    ASSERT_EQ(stack.pop(), 3);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
    ASSERT_EQ(stack.pop(), 0);

    ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST(dynamic_multi_stack, isEmpty)
{
    datastructures::DynamicMultiStack<double> stack {};

    ASSERT_EQ(stack.isEmpty(), true);
    stack.push_back(2);
    ASSERT_EQ(stack.isEmpty(), false);
    stack.pop();
    ASSERT_EQ(stack.isEmpty(), true);
}

TEST(dynamic_multi_stack, popAtStack)
{
    datastructures::DynamicMultiStack<double> stack {};

    stack.push_back(2);
    ASSERT_EQ(stack.popAtStack(0), 2);

    stack.push_back(0);
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(4);
    ASSERT_EQ(stack.popAtStack(0), 4);
    ASSERT_EQ(stack.popAtStack(0), 2);
    ASSERT_EQ(stack.popAtStack(0), 1);
    ASSERT_EQ(stack.popAtStack(0), 0);

    stack.push_back(0);
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);
    stack.push_back(4);
    stack.push_back(5);
    stack.push_back(6);
    stack.push_back(7);
    ASSERT_EQ(stack.popAtStack(0), 4);
    ASSERT_EQ(stack.popAtStack(0), 3);
    ASSERT_EQ(stack.popAtStack(1), 7);
    ASSERT_EQ(stack.popAtStack(1), 6);
    ASSERT_EQ(stack.popAtStack(1), 5);
    ASSERT_EQ(stack.popAtStack(0), 2);
    ASSERT_EQ(stack.popAtStack(0), 1);
    ASSERT_EQ(stack.popAtStack(0), 0);

    ASSERT_THROW(stack.popAtStack(20), std::out_of_range);
}