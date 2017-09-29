#include "gtest/gtest.h"
#include "utils/strings/urlify.h"

TEST(urlify, with_empty_string)
{
    std::string str("");

    EXPECT_EQ(urlify(str), "");
}

TEST(urlify, with_string_without_blank_space)
{
    std::string str("abc");

    EXPECT_EQ(urlify(str), "abc");
}

TEST(urlify, with_string_with_blank_space)
{
    std::string str("abc abc abc");

    EXPECT_EQ(urlify(str), "abc%20abc%20abc");
}

TEST(urlify, with_white_space_on_end)
{
    std::string str("abc abc           ");

    EXPECT_EQ(urlify(str), "abc%20abc");
}
