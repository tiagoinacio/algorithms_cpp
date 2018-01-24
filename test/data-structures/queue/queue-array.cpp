#include "gtest/gtest.h"
#include "data-structures/queue/queue-array.h"

TEST(queue_array, enqueue_peek)
{
    datastructures::QueueArray<double> queue;

    queue.enqueue(2);
    ASSERT_EQ(queue.peek(), 2);

    queue.enqueue(4);
    ASSERT_EQ(queue.peek(), 2);

    queue.enqueue(7);
    ASSERT_EQ(queue.peek(), 2);
}

TEST(queue_array, peek_throw)
{
    datastructures::QueueArray<double> queue;
    ASSERT_THROW(queue.peek(), std::out_of_range);
}

TEST(queue_array, enqueue_dequeue)
{
    datastructures::QueueArray<double> queue;

    queue.enqueue(2);
    ASSERT_EQ(queue.dequeue(), 2);

    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(4);
    ASSERT_EQ(queue.dequeue(), 0);
    ASSERT_EQ(queue.dequeue(), 1);
    ASSERT_EQ(queue.dequeue(), 2);
    ASSERT_EQ(queue.dequeue(), 4);

    ASSERT_THROW(queue.dequeue(), std::out_of_range);
}

TEST(queue_array, enqueue_throw)
{
    datastructures::QueueArray<double> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    ASSERT_THROW(queue.enqueue(11), std::out_of_range);
}

TEST(queue_array, is_full)
{
    datastructures::QueueArray<double> queue;

    queue.enqueue(1);
    ASSERT_EQ(queue.isFull(), false);

    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);

    queue.enqueue(9);
    ASSERT_EQ(queue.isFull(), false);

    queue.enqueue(10);
    ASSERT_EQ(queue.isFull(), true);
}

TEST(queue_array, isEmpty)
{
    datastructures::QueueArray<double> queue;

    ASSERT_EQ(queue.isEmpty(), true);
    queue.enqueue(2);
    ASSERT_EQ(queue.isEmpty(), false);
    queue.dequeue();
    ASSERT_EQ(queue.isEmpty(), true);
}
