#include "gtest/gtest.h"
#include "utils/bit-manipulation/bit-manipulation.h"

TEST(isNumberOdd, with_even_input) {
    ASSERT_EQ(isNumberOdd(2), false);
}

TEST(isNumberOdd, with_odd_input) {
    ASSERT_EQ(isNumberOdd(1), true);
}