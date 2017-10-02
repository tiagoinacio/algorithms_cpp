#include "gtest/gtest.h"
#include "utils/strings/is-palindrome.h"

TEST(isPalindrome_char, with_empty_string)
{
    char str[] = "";

    EXPECT_EQ(isPalindrome(str, 0), false);
}

TEST(isPalindrome_char, no_palindrome)
{
    char str[] = "abcdefg";

    EXPECT_EQ(isPalindrome(str, 7), false);
}

TEST(isPalindrome_char, is_palindrome)
{
    char str[] = "abccba";

    EXPECT_EQ(isPalindrome(str, 6), true);
}

TEST(isPalindrome_char, is_palindrome_with_one_middle)
{
    char str[] = "abcba";

    EXPECT_EQ(isPalindrome(str, 5), true);
}

TEST(isPalindrome_char, is_palindrome_with_white_space)
{
    char str[] = "a bc  c b a";

    EXPECT_EQ(isPalindrome(str, 11), true);
}

TEST(isPalindrome_string, with_empty_string)
{
    std::string str;

    EXPECT_EQ(isPalindrome(str), false);
}

TEST(isPalindrome_string, no_palindrome)
{
    std::string str("abcdefg");

    EXPECT_EQ(isPalindrome(str), false);
}

TEST(isPalindrome_string, is_palindrome)
{
    std::string str("abccba");

    EXPECT_EQ(isPalindrome(str), true);
}

TEST(isPalindrome_string, is_palindrome_with_one_middle)
{
    std::string str("abcba");

    EXPECT_EQ(isPalindrome(str), true);
}

TEST(isPalindrome_string, is_palindrome_with_white_space)
{
    std::string str("a bc  c b a");

    EXPECT_EQ(isPalindrome(str), true);
}