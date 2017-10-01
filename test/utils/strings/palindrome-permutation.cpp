#include "gtest/gtest.h"
#include "utils/strings/palindrome-permutation.h"

TEST(isPalindromePermutation, with_empty_string)
{
    char str[] = "";

    EXPECT_EQ(isPalindromePermutation(str, 0), false);
}

TEST(isPalindromePermutation, no_palindrome)
{
    char str[] = "abcdefg";

    EXPECT_EQ(isPalindromePermutation(str, 7), false);
}

TEST(isPalindromePermutation, is_palindrome)
{
    char str[] = "abccba";

    EXPECT_EQ(isPalindromePermutation(str, 6), true);
}

TEST(isPalindromePermutation, is_palindrome_with_white_space)
{
    char str[] = "a bc  c b a";

    EXPECT_EQ(isPalindromePermutation(str, 11), true);
}

TEST(isPalindromePermutation, is_palindrome_with_one_middle)
{
    char str[] = "a bc  b a";

    EXPECT_EQ(isPalindromePermutation(str, 9), true);
}