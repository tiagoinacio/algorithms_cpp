#include "utils/strings/zero-matrix.h"

std::vector<std::vector<int> >& zeroMatrix(std::vector<std::vector<int> > &matrix) {
    std::vector<int>::size_type rows = matrix.size();
    if (rows < 1) {
        return matrix;
    }

    std::vector<int>::size_type columns = matrix[0].size();
    std::vector<int>::size_type i, j;
    std::vector<int> rowsToZero;
    std::vector<int> columnsToZero;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (matrix[i][j] == 0) {
                rowsToZero.push_back(i);
                columnsToZero.push_back(j);
            }
        }
    }

    for (i = 0; i < rowsToZero.size(); i++) {
        for (j = 0; j < columns; j++) {
            matrix[rowsToZero[i]][j] = 0;
        }
    }
    for (i = 0; i < columnsToZero.size(); i++) {
        for (j = 0; j < rows; j++) {
            matrix[j][columnsToZero[i]] = 0;
        }
    }

    return matrix;
}