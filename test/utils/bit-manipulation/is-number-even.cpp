#include "gtest/gtest.h"
#include "utils/bit-manipulation/bit-manipulation.h"

TEST(isNumberEven, with_even_input) {
    ASSERT_EQ(isNumberEven(2), true);
}

TEST(isNumberEven, with_odd_input) {
    ASSERT_EQ(isNumberEven(1), false);
}