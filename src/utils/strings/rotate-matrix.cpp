#include "utils/strings/rotate-matrix.h"

// rotate matrix in place by 90 dregrees
std::vector<std::vector<int> >& rotateMatrixBy90Degrees(std::vector<std::vector<int> > &matrix) {
    std::vector<int>::size_type rows = matrix[0].size();
    std::vector< std::vector<int> >::size_type cycles = floor(rows / 2);
    std::vector< std::vector<int> >::size_type currentCycle;

    for (currentCycle = 0; currentCycle < cycles; currentCycle++) {

        for (int i = 0; i < 3; i++) {
            int tmp2 = matrix[currentCycle][3 - i];
            matrix[currentCycle][3 - i] = matrix[currentCycle + 1][i];

            int tmp1 = matrix[rows - i - 1][3 - i];
            matrix[rows - i - 1][3 - i] = tmp2;

            tmp2 = matrix[rows - i - 1][i];
            matrix[rows - i - 1][i] = tmp1;

            matrix[currentCycle][i] = tmp2;
        }
    }

    return matrix;
}