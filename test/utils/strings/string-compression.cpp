#include "gtest/gtest.h"
#include "utils/strings/string-compression.cpp"
#include <string>

TEST(stringCompression, with_empty_string)
{
    std::string str("");

    EXPECT_EQ(stringCompression(str), "");
}

TEST(stringCompression, without_repeated_chars)
{
    std::string str("abcdef");

    EXPECT_EQ(stringCompression(str), "abcdef");
}

TEST(stringCompression, with_repeated_chars_very_compressed)
{
    std::string str("aabcccccaaa");

    EXPECT_EQ(stringCompression(str), "a2bc5a3");
}

TEST(stringCompression, with_repeated_chars_but_not_very_compressed)
{
    std::string str("aabbcd");

    EXPECT_EQ(stringCompression(str), "aabbcd");
}