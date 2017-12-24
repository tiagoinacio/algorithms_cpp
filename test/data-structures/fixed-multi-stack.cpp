#include "gtest/gtest.h"
#include "data-structures/fixed-multi-stack.h"

TEST(fixed_multi_stack_default, push_peek)
{
    datastructures::FixedMultiStack<double> stack;

    stack.push_back(0, 2);
    ASSERT_EQ(stack.peek(0), 2);

    stack.push_back(0, 4);
    ASSERT_EQ(stack.peek(0), 4);

    stack.push_back(1, 7);
    ASSERT_EQ(stack.peek(1), 7);
}

TEST(fixed_multi_stack_default, push_pop)
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

TEST(fixed_multi_stack_default, isEmpty)
{
    datastructures::FixedMultiStack<double> stack;

    ASSERT_EQ(stack.isEmpty(0), true);
    stack.push_back(0, 2);
    ASSERT_EQ(stack.isEmpty(0), false);
    stack.pop(0);
    ASSERT_EQ(stack.isEmpty(0), true);
}

TEST(fixed_multi_stack_with_5_stacks, push_peek)
{
    const int numberOfStacks = 5;
    datastructures::FixedMultiStack<double> stack(numberOfStacks);

    stack.push_back(0, 2);
    ASSERT_EQ(stack.peek(0), 2);

    stack.push_back(0, 4);
    ASSERT_EQ(stack.peek(0), 4);

    stack.push_back(1, 7);
    ASSERT_EQ(stack.peek(1), 7);

    stack.push_back(2, 7);
    ASSERT_EQ(stack.peek(2), 7);

    stack.push_back(3, 7);
    ASSERT_EQ(stack.peek(3), 7);

    stack.push_back(4, 7);
    ASSERT_EQ(stack.peek(4), 7);

    ASSERT_THROW(stack.push_back(5, 7), std::out_of_range);
}

TEST(fixed_multi_stack_with_5_stacks, push_pop)
{
    const int numberOfStacks = 5;
    datastructures::FixedMultiStack<double> stack(numberOfStacks);

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

    stack.push_back(2, 2);
    ASSERT_EQ(stack.pop(2), 2);

    stack.push_back(3, 0);
    stack.push_back(3, 1);
    stack.push_back(3, 2);
    stack.push_back(3, 4);
    ASSERT_EQ(stack.pop(3), 4);
    ASSERT_EQ(stack.pop(3), 2);
    ASSERT_EQ(stack.pop(3), 1);
    ASSERT_EQ(stack.pop(3), 0);

    stack.push_back(4, 2);
    ASSERT_EQ(stack.pop(4), 2);

    ASSERT_THROW(stack.pop(5), std::out_of_range);
}

TEST(fixed_multi_stack_with_5_stacks, isEmpty)
{
    const int numberOfStacks = 5;
    datastructures::FixedMultiStack<double> stack(numberOfStacks);

    ASSERT_EQ(stack.isEmpty(0), true);

    stack.push_back(0, 2);
    ASSERT_EQ(stack.isEmpty(0), false);

    stack.pop(0);
    ASSERT_EQ(stack.isEmpty(0), true);

    ASSERT_EQ(stack.isEmpty(1), true);

    stack.push_back(1, 2);
    ASSERT_EQ(stack.isEmpty(1), false);

    stack.pop(1);
    ASSERT_EQ(stack.isEmpty(1), true);

    ASSERT_EQ(stack.isEmpty(2), true);

    stack.push_back(2, 2);
    ASSERT_EQ(stack.isEmpty(2), false);

    stack.pop(2);
    ASSERT_EQ(stack.isEmpty(2), true);

    ASSERT_EQ(stack.isEmpty(3), true);

    stack.push_back(3, 2);
    ASSERT_EQ(stack.isEmpty(3), false);

    stack.pop(3);
    ASSERT_EQ(stack.isEmpty(3), true);

    ASSERT_EQ(stack.isEmpty(4), true);

    stack.push_back(4, 2);
    ASSERT_EQ(stack.isEmpty(4), false);

    stack.pop(4);
    ASSERT_EQ(stack.isEmpty(4), true);
}

TEST(fixed_multi_stack_with_5_stacks_5_capacity, push_peek)
{
    const int numberOfStacks = 5;
    const int capacity = 5;
    datastructures::FixedMultiStack<double> stack(numberOfStacks, capacity);

    stack.push_back(0, 2);
    ASSERT_EQ(stack.peek(0), 2);

    stack.push_back(0, 4);
    ASSERT_EQ(stack.peek(0), 4);

    stack.push_back(1, 7);
    ASSERT_EQ(stack.peek(1), 7);

    stack.push_back(2, 7);
    ASSERT_EQ(stack.peek(2), 7);

    stack.push_back(3, 7);
    ASSERT_EQ(stack.peek(3), 7);

    stack.push_back(4, 7);
    ASSERT_EQ(stack.peek(4), 7);

    ASSERT_THROW(stack.push_back(5, 7), std::out_of_range);
}

TEST(fixed_multi_stack_with_5_stacks_5_capacity, push_pop)
{
    const int numberOfStacks = 5;
    const int capacity = 5;
    datastructures::FixedMultiStack<double> stack(numberOfStacks, capacity);

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

    stack.push_back(2, 2);
    ASSERT_EQ(stack.pop(2), 2);

    stack.push_back(3, 0);
    stack.push_back(3, 1);
    stack.push_back(3, 2);
    stack.push_back(3, 4);
    ASSERT_EQ(stack.pop(3), 4);
    ASSERT_EQ(stack.pop(3), 2);
    ASSERT_EQ(stack.pop(3), 1);
    ASSERT_EQ(stack.pop(3), 0);

    stack.push_back(4, 2);
    ASSERT_EQ(stack.pop(4), 2);

    ASSERT_THROW(stack.pop(5), std::out_of_range);
}

TEST(fixed_multi_stack_with_5_stacks_5_capacity, isEmpty)
{
    const int numberOfStacks = 5;
    const int capacity = 5;
    datastructures::FixedMultiStack<double> stack(numberOfStacks, capacity);

    ASSERT_EQ(stack.isEmpty(0), true);

    stack.push_back(0, 2);
    ASSERT_EQ(stack.isEmpty(0), false);

    stack.pop(0);
    ASSERT_EQ(stack.isEmpty(0), true);

    ASSERT_EQ(stack.isEmpty(1), true);

    stack.push_back(1, 2);
    ASSERT_EQ(stack.isEmpty(1), false);

    stack.pop(1);
    ASSERT_EQ(stack.isEmpty(1), true);

    ASSERT_EQ(stack.isEmpty(2), true);

    stack.push_back(2, 2);
    ASSERT_EQ(stack.isEmpty(2), false);

    stack.pop(2);
    ASSERT_EQ(stack.isEmpty(2), true);

    ASSERT_EQ(stack.isEmpty(3), true);

    stack.push_back(3, 2);
    ASSERT_EQ(stack.isEmpty(3), false);

    stack.pop(3);
    ASSERT_EQ(stack.isEmpty(3), true);

    ASSERT_EQ(stack.isEmpty(4), true);

    stack.push_back(4, 2);
    ASSERT_EQ(stack.isEmpty(4), false);

    stack.pop(4);
    ASSERT_EQ(stack.isEmpty(4), true);
}
