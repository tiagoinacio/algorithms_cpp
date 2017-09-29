#include "utils/strings/check-permutation.h"

bool checkPermutation(char* first, char* second, size_t firstSize, size_t secondSize)
{
    bool wasFoundOnFirst = false;
    bool wasFoundOnSecond = false;

    for (int i = 0; i < firstSize; i++) {
        for (int j = 0; j < secondSize; j++) {
            if (first[i] == second[j]) {
                wasFoundOnFirst = true;
            }
        }
        if (!wasFoundOnFirst) {
            return false;
        }
    }

    for (int i = 0; i < secondSize; i++) {
        for (int j = 0; j < firstSize; j++) {
            if (second[i] == first[j]) {
                wasFoundOnSecond = true;
            }
        }
        if (!wasFoundOnSecond) {
            return false;
        }
    }

    return true;
}

