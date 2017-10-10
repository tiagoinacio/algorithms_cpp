#include "utils/strings/rotate-matrix.h"
#include <iostream>
// rotate matrix in place by 90 dregrees
std::vector<std::vector<int> >& rotateMatrixBy90Degrees(std::vector<std::vector<int> > &matrix) {
    if (matrix.size() < 1) {
        return matrix;
    }

    std::vector<int>::size_type columns = matrix[0].size();
    
    if (columns < 1) {
        return matrix;
    }
    
    std::vector< std::vector<int> >::size_type cycles = floor(columns / 2);
    
    for (int column = 0; column < cycles; column++) {
        for (int elem = 0; elem < columns - 1; elem++) {
            int tmp = matrix[column + elem][columns + column - 1];
            matrix[column + elem][columns + column - 1] = matrix[column][elem + column];
            
            int tmp2 = matrix[columns + column - 1][columns - elem - 1 + column];
            matrix[columns + column - 1][columns - elem - 1 + column] = tmp;
            
            tmp = matrix[columns - elem - 1 + column][column];
            matrix[columns - elem - 1 + column][column] = tmp2;
            matrix[column][elem + column] = tmp;            
        }
        columns = columns - 2;
    }

    return matrix;
}