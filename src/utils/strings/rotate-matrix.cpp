#include "utils/strings/rotate-matrix.h"
#include <iostream>

std::vector<std::vector<int> >& rotateMatrix(std::vector<std::vector<int> > &matrix) {

    for (std::vector<std::vector<int> >::size_type columnIndex = 0; columnIndex < matrix.size(); columnIndex++) {
        std::vector<int>::size_type rowSize = matrix[columnIndex].size();
        for (std::vector<int>::size_type rowIndex = 0; rowIndex < rowSize; rowIndex++) {
            int tmp = matrix[columnIndex][rowSize - rowIndex];

            std::cout << matrix[columnIndex][rowIndex] << std::endl;
        }
    }

    return matrix;
}