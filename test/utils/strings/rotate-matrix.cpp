#include "gtest/gtest.h"
#include "utils/strings/rotate-matrix.h"

TEST(rotateMatrix, with_empty_matrix)
{
    std::vector<std::vector<int >> matrix;

    EXPECT_EQ(rotateMatrix(matrix), matrix);
}

TEST(rotateMatrix, with_1x1_matrix)
{
    std::vector<std::vector<int >> matrix;
    std::vector<int> row = {1};

    matrix.push_back(row);

    EXPECT_EQ(rotateMatrix(matrix), matrix);
}

/*
Rotate by 90 degrees
Input
1 2 3
4 5 6
7 8 9


Expected
7 4 1
8 5 2
9 6 3
*/
TEST(rotateMatrix, with_3x3_matrix)
{
    std::vector<std::vector<int >> inputMatrix;
    std::vector<int> firstRowInput = {1, 2, 3};
    std::vector<int> secondRowInput = {4, 5, 6};
    std::vector<int> thirdRowInput = {7, 8, 9};

    inputMatrix.push_back(firstRowInput);
    inputMatrix.push_back(secondRowInput);
    inputMatrix.push_back(thirdRowInput);

    std::vector<std::vector<int >> expectedMatrix;
    std::vector<int> expectedFirstRow = {7, 4, 1};
    std::vector<int> expectedSecondRow = {8, 5, 2};
    std::vector<int> expectedThirdRow = {9, 6, 3};

    expectedMatrix.push_back(expectedFirstRow);
    expectedMatrix.push_back(expectedSecondRow);
    expectedMatrix.push_back(expectedThirdRow);

    EXPECT_EQ(rotateMatrix(inputMatrix), expectedMatrix);
}

