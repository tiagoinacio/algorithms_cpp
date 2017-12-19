#include "gtest/gtest.h"
#include "data-structures/fixed-multi-stack.h"

TEST(fixed_multi_stack, push_peek)
{
    datastructures::FixedMultiStack<double> stack;

    stack.push_back(0, 2);
    ASSERT_EQ(stack.peek(0), 2);

    stack.push_back(0, 4);
    ASSERT_EQ(stack.peek(0), 4);

    stack.push_back(1, 7);
    ASSERT_EQ(stack.peek(1), 7);
}

TEST(fixed_multi_stack, push_pop)
{
    datastructures::FixedMultiStack<double> stack;

    stack.push_back(0, 2);
    ASSERT_EQ(stack.pop(0), 2);

    stack.push_back(1, 0);
    stack.push_back(1, 1);
    stack.push_back(1, 2);
    stack.push_back(1, 4);
    ASSERT_EQ(stack.pop(1), 4);
    ASSERT_EQ(stack.pop(1), 2);
    ASSERT_EQ(stack.pop(1), 1);
    ASSERT_EQ(stack.pop(1), 0);

    ASSERT_THROW(stack.pop(1), std::out_of_range);
}

TEST(fixed_multi_stack, isEmpty)
{
    datastructures::FixedMultiStack<double> stack;

    ASSERT_EQ(stack.isEmpty(0), true);
    stack.push_back(0, 2);
    ASSERT_EQ(stack.isEmpty(0), false);
    stack.pop(0);
    ASSERT_EQ(stack.isEmpty(0), true);
}
