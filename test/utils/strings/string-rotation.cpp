#include "gtest/gtest.h"
#include "utils/strings/string-rotation.cpp"
#include <string>

TEST(stringRotation, with_empty_strings)
{
    std::string s1("");
    std::string s2("");

    EXPECT_EQ(stringRotation(s1, s2), true);
}

TEST(stringRotation, with_equal_strings)
{
    std::string s1("waterbottle");
    std::string s2("erbottlewat");

    EXPECT_EQ(stringRotation(s1, s2), true);
}

TEST(stringRotation, with_equal_strings_2)
{
    std::string s1("abcdefgh");
    std::string s2("cde");

    EXPECT_EQ(stringRotation(s1, s2), true);
}


TEST(stringRotation, with_non_equal_strings)
{
    std::string s1("waterbottle");
    std::string s2("erzbottlewat");

    EXPECT_EQ(stringRotation(s1, s2), false);
}

TEST(stringRotation, with_non_equal_strings_2)
{
    std::string s1("abcdefgh");
    std::string s2("ptrewq");

    EXPECT_EQ(stringRotation(s1, s2), false);
}

TEST(isStringRotation, with_empty_strings)
{
    std::string s1("");
    std::string s2("");

    EXPECT_EQ(isStringRotation(s1, s2), true);
}

TEST(isStringRotation, with_equal_strings)
{
    std::string s1("waterbottle");
    std::string s2("erbottlewat");

    EXPECT_EQ(isStringRotation(s1, s2), true);
}

TEST(isStringRotation, with_equal_strings_2)
{
    std::string s1("abcdefgh");
    std::string s2("cde");

    EXPECT_EQ(isStringRotation(s1, s2), true);
}


TEST(isStringRotation, with_non_equal_strings)
{
    std::string s1("waterbottle");
    std::string s2("erzbottlewat");

    EXPECT_EQ(isStringRotation(s1, s2), false);
}

TEST(isStringRotation, with_non_equal_strings_2)
{
    std::string s1("abcdefgh");
    std::string s2("ptrewq");

    EXPECT_EQ(isStringRotation(s1, s2), false);
}