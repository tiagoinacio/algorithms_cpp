#include "gtest/gtest.h"
#include "utils/strings/is-unique.h"
#include <string>

TEST(isUnique_str, with_empty_string)
{
    std::string str("");

    EXPECT_EQ(isUnique(str), true);
}

TEST(isUnique_str, is_not_unique)
{
    std::string str("aabcde");

    EXPECT_EQ(isUnique(str), false);
}

TEST(isUnique_str, is_unique)
{
    std::string str("abcde");

    EXPECT_EQ(isUnique(str), true);
}

TEST(isUnique_char, with_empty_string)
{
    char str[] = "";

    EXPECT_EQ(isUnique(str, 0), true);
}

TEST(isUnique_char, is_not_unique)
{
    char str[] = "aabcde";

    EXPECT_EQ(isUnique(str, 6), false);
}

TEST(isUnique_char, is_unique)
{
    char str[] = "abcde";

    EXPECT_EQ(isUnique(str, 5), true);
}
