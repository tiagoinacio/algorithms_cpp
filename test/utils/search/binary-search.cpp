#include "gtest/gtest.h"
#include "utils/search/binary-search.h"
#include <vector>

TEST(binary_search, with_existing_key)
{
    double vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    EXPECT_EQ(utils::search::binarySearch<double>(vec, 1, 0, 9), 0);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 2, 0, 9), 1);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 3, 0, 9), 2);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 4, 0, 9), 3);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 5, 0, 9), 4);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 6, 0, 9), 5);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 7, 0, 9), 6);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 8, 0, 9), 7);
    EXPECT_EQ(utils::search::binarySearch<double>(vec, 9, 0, 9), 8);
}

TEST(binary_search, without_existing_key)
{
    double vec[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};

    ASSERT_ANY_THROW(utils::search::binarySearch<double>(vec, 5, 0, 8));
    ASSERT_ANY_THROW(utils::search::binarySearch<double>(vec, 20, 0, 8));
    ASSERT_ANY_THROW(utils::search::binarySearch<double>(vec, 15, 0, 8));
    ASSERT_ANY_THROW(utils::search::binarySearch<double>(vec, 0, 0, 8));
}