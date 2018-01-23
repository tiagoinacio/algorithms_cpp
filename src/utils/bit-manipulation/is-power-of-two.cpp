#include "utils/bit-manipulation/bit-manipulation.h"

/*
 * In binary system, all power of two's numbers only have 1 digit witht the value "1"
 * So, we subtract one, and by applying the AND operator, we should not have any one's
 */
bool isPowerOfTwo(int number) {
    return (number & (number - 1)) == 0;
}