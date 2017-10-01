#include "gtest/gtest.h"
#include "utils/sort/bublesort.h"
#include <vector>

TEST(bublesort_vec, unsorted_vector)
{
    std::vector<double> unsortedVec;
    unsortedVec.push_back(8);
    unsortedVec.push_back(5);
    unsortedVec.push_back(7);
    unsortedVec.push_back(1);

    std::vector<double> sortedVec;
    sortedVec.push_back(1);
    sortedVec.push_back(5);
    sortedVec.push_back(7);
    sortedVec.push_back(8);

    bublesort(unsortedVec);

    EXPECT_EQ(unsortedVec, sortedVec);
}

TEST(bublesort_improved_vec, unsorted_vector)
{
    std::vector<double> unsortedVec;
    unsortedVec.push_back(8);
    unsortedVec.push_back(5);
    unsortedVec.push_back(7);
    unsortedVec.push_back(1);

    std::vector<double> sortedVec;
    sortedVec.push_back(1);
    sortedVec.push_back(5);
    sortedVec.push_back(7);
    sortedVec.push_back(8);

    bublesort_improved(unsortedVec);

    EXPECT_EQ(unsortedVec, sortedVec);
}

TEST(bublesort_array, unsorted_vector)
{
    double vec[] = {8, 5, 7, 1};

    bublesort(vec, 4);

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec[2], 7);
    EXPECT_EQ(vec[3], 8);
}

TEST(bublesort_improved_array, unsorted_vector)
{
    double vec[] = {8, 5, 7, 1};

    bublesort_improved(vec, 4);

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec[2], 7);
    EXPECT_EQ(vec[3], 8);
}
