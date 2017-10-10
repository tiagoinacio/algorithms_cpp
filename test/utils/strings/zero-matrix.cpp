#include "gtest/gtest.h"
#include "utils/strings/zero-matrix.h"
#include <vector>

TEST(zeroMatrix, with_empty_matrix)
{
    std::vector<std::vector <int> > matrix;
    std::vector<int> row = {};
    matrix.push_back(row);

    std::vector<std::vector <int> > expectedMatrix;
    std::vector<int> expectedRow = {};
    expectedMatrix.push_back(expectedRow);

    EXPECT_EQ(zeroMatrix(matrix), expectedMatrix);
}

// {1, 2, 3, 4}
// {5, 6, 7, 8}
// {9, 10, 11, 12}
TEST(zeroMatrix, without_zeros)
{
    std::vector<std::vector <int> > matrix;
    std::vector<int> first = {1, 2, 3, 4};
    std::vector<int> second = {5, 6, 7, 8};
    std::vector<int> third = {9, 10, 11, 12};

    matrix.push_back(first);
    matrix.push_back(second);
    matrix.push_back(third);

    std::vector<std::vector <int> > expectedMatrix;
    expectedMatrix.push_back(first);
    expectedMatrix.push_back(second);
    expectedMatrix.push_back(third);

    EXPECT_EQ(zeroMatrix(matrix), expectedMatrix);
}

/*
Input
{1, 2, 3, 4}
{5, 0, 7, 8}
{9, 10, 11, 12}

Expected
{1, 0, 3, 4}
{0, 0, 0, 0}
{9, 0, 11, 12}
*/
TEST(zeroMatrix, with_zeros_3x4)
{
    std::vector<std::vector <int> > matrix;
    std::vector<int> first = {1, 2, 3, 4};
    std::vector<int> second = {5, 0, 7, 8};
    std::vector<int> third = {9, 10, 11, 12};

    matrix.push_back(first);
    matrix.push_back(second);
    matrix.push_back(third);

    std::vector<std::vector <int> > expectedMatrix;
    std::vector<int> firstExpected = {1, 0, 3, 4};
    std::vector<int> secondExpected = {0, 0, 0, 0};
    std::vector<int> thirdExpected = {9, 0, 11, 12};
    expectedMatrix.push_back(firstExpected);
    expectedMatrix.push_back(secondExpected);
    expectedMatrix.push_back(thirdExpected);

    EXPECT_EQ(zeroMatrix(matrix), expectedMatrix);
}

/*
Input
{1, 2, 3, 4}
{5, 6, 7, 8}
{9, 10, 0, 12}
{13, 14, 15, 16}
{17, 18, 19, 20}

Expected
{1, 2, 0, 4}
{5, 6, 0, 8}
{0, 0, 0, 0}
{13, 14, 0, 16}
{17, 18, 0, 20}
*/
TEST(zeroMatrix, with_zeros_5x4)
{
    std::vector<std::vector <int> > matrix;
    std::vector<int> first = {1, 2, 3, 4};
    std::vector<int> second = {5, 6, 7, 8};
    std::vector<int> third = {9, 10, 0, 12};
    std::vector<int> fourth = {13, 14, 15, 16};
    std::vector<int> fifth = {17, 18, 19, 20};

    matrix.push_back(first);
    matrix.push_back(second);
    matrix.push_back(third);
    matrix.push_back(fourth);
    matrix.push_back(fifth);

    std::vector<std::vector <int> > expectedMatrix;
    std::vector<int> firstExpected = {1, 2, 0, 4};
    std::vector<int> secondExpected = {5, 6, 0, 8};
    std::vector<int> thirdExpected = {0, 0, 0, 0};
    std::vector<int> fourthExpected = {13, 14, 0, 16};
    std::vector<int> fifthExpected = {17, 18, 0, 20};
    expectedMatrix.push_back(firstExpected);
    expectedMatrix.push_back(secondExpected);
    expectedMatrix.push_back(thirdExpected);
    expectedMatrix.push_back(fourthExpected);
    expectedMatrix.push_back(fifthExpected);

    EXPECT_EQ(zeroMatrix(matrix), expectedMatrix);
}
