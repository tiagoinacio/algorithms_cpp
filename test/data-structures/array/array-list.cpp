#include "gtest/gtest.h"
#include "data-structures/array/array-list.h"

TEST(array_list, default_params)
{
    datastructures::ArrayList<double> arrayList;

    ASSERT_EQ(arrayList.size(), 0);
    ASSERT_EQ(arrayList.capacity(), 1);
}

TEST(array_list, push_back)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(4);
    ASSERT_EQ(arrayList.size(), 1);
    ASSERT_EQ(arrayList.capacity(), 1);

    arrayList.push_back(10);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.capacity(), 2);

    arrayList.push_back(15);
    ASSERT_EQ(arrayList.size(), 3);
    ASSERT_EQ(arrayList.capacity(), 4);

    arrayList.push_back(16);
    ASSERT_EQ(arrayList.size(), 4);
    ASSERT_EQ(arrayList.capacity(), 4);

    arrayList.push_back(17);
    ASSERT_EQ(arrayList.size(), 5);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 6);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 7);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 8);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 9);
    ASSERT_EQ(arrayList.capacity(), 16);
}

TEST(array_list, copy_constructor)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(4);
    ASSERT_EQ(arrayList.get(0), 4);

    datastructures::ArrayList<double> cloneArrayList(arrayList);
    ASSERT_EQ(cloneArrayList.get(0), 4);
}

TEST(array_list, get_out_of_bounds)
{
    datastructures::ArrayList<double> arrayList;

    ASSERT_ANY_THROW(arrayList.get(1));
}

TEST(array_list, isEmpty)
{
    datastructures::ArrayList<double> arrayList;
    EXPECT_EQ(arrayList.isEmpty(), true);

    arrayList.push_back(1);
    EXPECT_EQ(arrayList.isEmpty(), false);
}

TEST(array_list, assignment_operator)
{
    datastructures::ArrayList<double> arrayList;
    datastructures::ArrayList<double> arrayList2;

    arrayList.push_back(7);

    arrayList2 = arrayList;
    ASSERT_EQ(arrayList2.get(0), 7);
}

TEST(array_list, set)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(7);
    ASSERT_EQ(arrayList.size(), 1);
    ASSERT_EQ(arrayList.get(0), 7);

    arrayList.set(0, 5);
    ASSERT_EQ(arrayList.get(0), 5);
}

TEST(array_list, set_throw)
{
    datastructures::ArrayList<double> arrayList;
    ASSERT_THROW(arrayList.set(4, 5), std::out_of_range);
}

TEST(array_list, insert)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(7);
    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.get(0), 7);
    ASSERT_EQ(arrayList.get(1), 1);

    arrayList.insert(1, 9);
    ASSERT_EQ(arrayList.size(), 3);
    ASSERT_EQ(arrayList.get(0), 7);
    ASSERT_EQ(arrayList.get(1), 9);
    ASSERT_EQ(arrayList.get(2), 1);

    ASSERT_THROW(arrayList.set(4, 5), std::out_of_range);
}

TEST(array_list, pop)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(7);
    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.get(0), 7);
    ASSERT_EQ(arrayList.get(1), 1);

    ASSERT_EQ(arrayList.pop(), 1);
    ASSERT_EQ(arrayList.size(), 1);

    ASSERT_EQ(arrayList.pop(), 7);
    ASSERT_EQ(arrayList.size(), 0);
}

TEST(array_list, pop_throw)
{
    datastructures::ArrayList<double> arrayList;
    ASSERT_THROW(arrayList.pop(), std::out_of_range);
}

TEST(array_list, prepend)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(7);
    arrayList.push_back(1);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.get(0), 7);
    ASSERT_EQ(arrayList.get(1), 1);

    arrayList.prepend(9);
    ASSERT_EQ(arrayList.size(), 3);
    ASSERT_EQ(arrayList.get(0), 9);
    ASSERT_EQ(arrayList.get(1), 7);
    ASSERT_EQ(arrayList.get(2), 1);
}

TEST(array_list, remove)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(0);
    arrayList.push_back(1);
    arrayList.push_back(2);
    ASSERT_EQ(arrayList.size(), 3);
    ASSERT_EQ(arrayList.get(0), 0);
    ASSERT_EQ(arrayList.get(1), 1);
    ASSERT_EQ(arrayList.get(2), 2);

    arrayList.remove(1);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.get(0), 0);
    ASSERT_EQ(arrayList.get(1), 2);
}

TEST(array_list, removeByValue)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.push_back(0);
    arrayList.push_back(12);
    arrayList.push_back(2);
    ASSERT_EQ(arrayList.size(), 3);
    ASSERT_EQ(arrayList.get(0), 0);
    ASSERT_EQ(arrayList.get(1), 12);
    ASSERT_EQ(arrayList.get(2), 2);

    arrayList.removeByValue(12);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.get(0), 0);
    ASSERT_EQ(arrayList.get(1), 2);

    arrayList.removeByValue(14);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.get(0), 0);
    ASSERT_EQ(arrayList.get(1), 2);
}

TEST(array_list, find)
{
    datastructures::ArrayList<double> arrayList;

    ASSERT_EQ(arrayList.find(2), -1);

    arrayList.push_back(1);
    arrayList.push_back(4);
    arrayList.push_back(12);
    arrayList.push_back(12);
    arrayList.push_back(18);

    ASSERT_EQ(arrayList.find(1), 0);
    ASSERT_EQ(arrayList.find(4), 1);
    ASSERT_EQ(arrayList.find(12), 2);
    ASSERT_EQ(arrayList.find(18), 4);

    arrayList.removeByValue(12);

    ASSERT_EQ(arrayList.find(12), -1);
}
