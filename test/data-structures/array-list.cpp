#include "gtest/gtest.h"
#include "data-structures/array-list.h"

TEST(array_list, default_params)
{
    datastructures::ArrayList<double> arrayList;

    ASSERT_EQ(arrayList.size(), 0);
    ASSERT_EQ(arrayList.capacity(), 1);
}

TEST(array_list, add)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.add(4);
    ASSERT_EQ(arrayList.size(), 1);
    ASSERT_EQ(arrayList.capacity(), 1);

    arrayList.add(10);
    ASSERT_EQ(arrayList.size(), 2);
    ASSERT_EQ(arrayList.capacity(), 2);

    arrayList.add(15);
    ASSERT_EQ(arrayList.size(), 3);
    ASSERT_EQ(arrayList.capacity(), 4);

    arrayList.add(16);
    ASSERT_EQ(arrayList.size(), 4);
    ASSERT_EQ(arrayList.capacity(), 4);

    arrayList.add(17);
    ASSERT_EQ(arrayList.size(), 5);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.add(1);
    ASSERT_EQ(arrayList.size(), 6);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.add(1);
    ASSERT_EQ(arrayList.size(), 7);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.add(1);
    ASSERT_EQ(arrayList.size(), 8);
    ASSERT_EQ(arrayList.capacity(), 8);

    arrayList.add(1);
    ASSERT_EQ(arrayList.size(), 9);
    ASSERT_EQ(arrayList.capacity(), 16);
}

TEST(array_list, copy_constructor)
{
    datastructures::ArrayList<double> arrayList;

    arrayList.add(4);
    ASSERT_EQ(arrayList.get(0), 4);

    datastructures::ArrayList<double> cloneArrayList(arrayList);
    ASSERT_EQ(cloneArrayList.get(0), 4);
}
