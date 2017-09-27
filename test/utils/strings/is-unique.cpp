#include "gtest/gtest.h"
#include "utils/strings/is-unique.h"
#include <string>

TEST(isUnique, with_empty_string)
{
    std::string str("");

    EXPECT_EQ(isUnique(str), true);
}

TEST(isUnique, is_not_unique)
{
    std::string str("aabcde");

    EXPECT_EQ(isUnique(str), false);
}

TEST(isUnique, is_unique)
{
    std::string str("abcde");

    EXPECT_EQ(isUnique(str), true);
}
