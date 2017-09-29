#include "gtest/gtest.h"
#include "utils/strings/check-permutation.h"
#include <string>

TEST(checkPermutation_char, with_empty_strings)
{
    char first[] = "";
    char second[] = "";

    EXPECT_EQ(checkPermutation(first, second, 0, 0), true);
}

TEST(checkPermutation_char, with_permutation)
{
    char first[] = "abcd";
    char second[] = "dcab";

    EXPECT_EQ(checkPermutation(first, second, 4, 4), true);
}

TEST(checkPermutation_char, without_permutation)
{
    char first[] = "abcde";
    char second[] = "sabcde";

    EXPECT_EQ(checkPermutation(first, second, 5, 6), false);
}

TEST(checkPermutation_char, without_permutation_all_chars_different)
{
    char first[] = "abcde";
    char second[] = "zxcv";

    EXPECT_EQ(checkPermutation(first, second, 5, 4), false);
}
