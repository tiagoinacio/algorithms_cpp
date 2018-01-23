#include "utils/bit-manipulation/bit-manipulation.h"

bool isNumberEven(int number) {
    return (number & 1) == 0;
}