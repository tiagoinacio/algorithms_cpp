#include "gtest/gtest.h"
#include "utils/strings/check-permutation.h"
#include <string>

TEST(checkPermutation_char, with_empty_strings)
{
    char first[] = "";
    char second[] = "";

    EXPECT_EQ(checkPermutation(first, second), true);
}
