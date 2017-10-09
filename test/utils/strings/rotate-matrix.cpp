#include "gtest/gtest.h"
#include "utils/strings/rotate-matrix.h"

TEST(rotateMatrixBy90Degrees, with_empty_matrix)
{
    std::vector<std::vector<int >> matrix;

    EXPECT_EQ(rotateMatrixBy90Degrees(matrix), matrix);
}

TEST(rotateMatrixBy90Degrees, with_1x1_matrix)
{
    std::vector<std::vector<int >> matrix;
    std::vector<int> row = {1};

    matrix.push_back(row);

    EXPECT_EQ(rotateMatrixBy90Degrees(matrix), matrix);
}

/*
Rotate by 90 degrees
Input
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16

Expected
13  9  5  1
14 10  6  2
15 11  7  3
16 12  8  4

13  9  5  1
14 10  6  2
15 11  7  3
16 12  8  4

*/
TEST(rotateMatrixBy90Degrees, with_4x4_matrix)
{
    std::vector< std::vector<int> > inputMatrix;
    std::vector<int> firstRowInput = {1, 2, 3, 4};
    std::vector<int> secondRowInput = {5, 6, 7, 8};
    std::vector<int> thirdRowInput = {9, 10, 11, 12};
    std::vector<int> fourthRowInput = {13, 14, 15, 16};

    inputMatrix.push_back(firstRowInput);
    inputMatrix.push_back(secondRowInput);
    inputMatrix.push_back(thirdRowInput);
    inputMatrix.push_back(fourthRowInput);

    std::vector< std::vector<int> > expectedMatrix;
    std::vector<int> expectedFirstRow = {13, 9, 5, 1};
    std::vector<int> expectedSecondRow = {14, 10, 6, 2};
    std::vector<int> expectedThirdRow = {15, 11, 7, 3};
    std::vector<int> expectedFourthRow = {16, 12, 8, 4};

    expectedMatrix.push_back(expectedFirstRow);
    expectedMatrix.push_back(expectedSecondRow);
    expectedMatrix.push_back(expectedThirdRow);
    expectedMatrix.push_back(expectedFourthRow);

    EXPECT_EQ(rotateMatrixBy90Degrees(inputMatrix), expectedMatrix);
}

/*
Rotate by 90 degrees
Input
 1  2  3  4  5  6  7  8
 9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64


Expected
57 49 41 33 25 17  9 1
58 50 42 34 26 18 10 2
59 51 43 35 27 19 11 3
60 52 44 36 28 20 12 4
61 53 45 37 29 21 13 5
62 54 46 38 30 22 14 6
63 55 47 39 31 23 15 7
64 56 48 40 32 24 16 8
*/
TEST(rotateMatrixBy90Degrees, with_8x8_matrix)
{
    std::vector<std::vector<int>> inputMatrix;
    std::vector<int> firstRowInput = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> secondRowInput = {9, 10, 11, 12, 13, 14, 15, 16};
    std::vector<int> thirdRowInput = {17, 18, 19, 20, 21, 22, 23, 24};
    std::vector<int> fourthRowInput = {25, 26, 27, 28, 29, 30, 31, 32};
    std::vector<int> fifthRowInput = {33, 34, 35, 36, 37, 38, 39, 40};
    std::vector<int> sixthRowInput = {41, 42, 43, 44, 45, 46, 47, 48};
    std::vector<int> seventhRowInput = {49, 50, 51, 52, 53, 54, 55, 56};
    std::vector<int> eighthRowInput = {57, 58, 59, 60, 61, 62, 63, 64};

    inputMatrix.push_back(firstRowInput);
    inputMatrix.push_back(secondRowInput);
    inputMatrix.push_back(thirdRowInput);
    inputMatrix.push_back(fourthRowInput);
    inputMatrix.push_back(fifthRowInput);
    inputMatrix.push_back(sixthRowInput);
    inputMatrix.push_back(seventhRowInput);
    inputMatrix.push_back(eighthRowInput);

    std::vector<std::vector<int>> expectedMatrix;
    std::vector<int> expectedFirstRow = {57, 49, 41, 33, 25, 17, 9, 1};
    std::vector<int> expectedSecondRow = {58, 50, 42, 34, 26, 18, 10, 2};
    std::vector<int> expectedThirdRow = {59, 51, 43, 35, 27, 19, 11, 3};
    std::vector<int> expectedFourthRow = {60, 52, 44, 36, 28, 20, 12, 4};
    std::vector<int> expectedFifthRow = {61, 53, 45, 37, 29, 21, 13, 5};
    std::vector<int> expectedSixthRow = {62, 54, 46, 38, 30, 22, 14, 6};
    std::vector<int> expectedSeventhRow = {63, 55, 47, 39, 31, 23, 15, 7};
    std::vector<int> expectedEighthRow = {64, 56, 48, 40, 32, 24, 16, 8};

    expectedMatrix.push_back(expectedFirstRow);
    expectedMatrix.push_back(expectedSecondRow);
    expectedMatrix.push_back(expectedThirdRow);
    expectedMatrix.push_back(expectedFourthRow);
    expectedMatrix.push_back(expectedFifthRow);
    expectedMatrix.push_back(expectedSixthRow);
    expectedMatrix.push_back(expectedSeventhRow);
    expectedMatrix.push_back(expectedEighthRow);

    EXPECT_EQ(rotateMatrixBy90Degrees(inputMatrix), expectedMatrix);
}