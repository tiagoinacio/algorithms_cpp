#include "gtest/gtest.h"
#include "utils/strings/rotate-matrix.h"

// TEST(rotateMatrixBy90Degrees, with_empty_matrix)
// {
//     std::vector<std::vector<int >> matrix;

//     EXPECT_EQ(rotateMatrixBy90Degrees(matrix), matrix);
// }

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

13  2  7  1
16 11 10  5
 9  3  6 12
 4 14 15  8

*/
TEST(rotateMatrixBy90Degrees, with_3x3_matrix)
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
 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25


Expected
21 16 11  6  1
22 17 12  7  2
23 18 13  8  3
24 19 14  9  4
25 20 15 10  5

*/
// TEST(rotateMatrixBy90Degrees, with_5x5_matrix)
// {
//     std::vector< std::vector<int> > inputMatrix;
//     std::vector<int> firstRowInput = {1, 2, 3, 4, 5};
//     std::vector<int> secondRowInput = {6, 7, 8, 9, 10};
//     std::vector<int> thirdRowInput = {11, 12, 13, 14, 15};
//     std::vector<int> fourthRowInput = {16, 17, 18, 19, 20};
//     std::vector<int> fifthRowInput = {21, 22, 23, 24, 25};

//     inputMatrix.push_back(firstRowInput);
//     inputMatrix.push_back(secondRowInput);
//     inputMatrix.push_back(thirdRowInput);
//     inputMatrix.push_back(fourthRowInput);
//     inputMatrix.push_back(fifthRowInput);

//     std::vector< std::vector<int> > expectedMatrix;
//     std::vector<int> expectedFirstRow = {21, 16, 11, 6, 1};
//     std::vector<int> expectedSecondRow = {22, 17, 12, 7, 2};
//     std::vector<int> expectedThirdRow = {23, 18, 13, 8, 3};
//     std::vector<int> expectedFourthRow = {24, 19, 14, 9, 4};
//     std::vector<int> expectedFifthRow = {25, 20, 15, 10, 5};

//     expectedMatrix.push_back(expectedFirstRow);
//     expectedMatrix.push_back(expectedSecondRow);
//     expectedMatrix.push_back(expectedThirdRow);
//     expectedMatrix.push_back(expectedFourthRow);
//     expectedMatrix.push_back(expectedFifthRow);

//     EXPECT_EQ(rotateMatrixBy90Degrees(inputMatrix), expectedMatrix);
// }