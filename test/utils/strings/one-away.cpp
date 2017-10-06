#include "gtest/gtest.h"
#include "utils/strings/one-away.h"
#include <string>

TEST(oneAway_str, with_empty_string)
{
    std::string str("");

    EXPECT_EQ(isOneAway(str, ""), true);
}

TEST(oneAway_str, with_equal_string)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "abc def ghj"), true);
}

TEST(oneAway_str, with_one_edit_remove_middle)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "abc ef ghj"), true);
}

TEST(oneAway_str, with_one_edit_remove_start)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "bc def ghj"), true);
}

TEST(oneAway_str, with_one_edit_remove_end)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "abc def gh"), true);
}

TEST(oneAway_str, with_one_edit_remove_end_second)
{
    std::string str("abc def gh");

    EXPECT_EQ(isOneAway(str, "abc def ghj"), true);
}

TEST(oneAway_str, with_two_edit_remove_end)
{
    std::string str("abc def ghj ");

    EXPECT_EQ(isOneAway(str, "abc def gh"), false);
}

TEST(oneAway_str, with_two_edit_remove_end_second)
{
    std::string str("abc def gh");

    EXPECT_EQ(isOneAway(str, "abc def ghj "), false);
}

TEST(oneAway_str, with_one_edit_add_middle)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "abc deef ghj"), true);
}

TEST(oneAway_str, with_one_edit_add_start)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "aabc def ghj"), true);
}

TEST(oneAway_str, with_one_edit_add_end)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "abc def ghjj"), true);
}

TEST(oneAway_str, with_two_edit_add_end)
{
    std::string str("abc def ghj");

    EXPECT_EQ(isOneAway(str, "abc def ghjjj"), false);
}

TEST(oneAway_str, pale_ple)
{
    std::string str("pale");

    EXPECT_EQ(isOneAway(str, "ple"), true);
}

TEST(oneAway_str, pales_pale)
{
    std::string str("pales");

    EXPECT_EQ(isOneAway(str, "pale"), true);
}

TEST(oneAway_str, pale_bale)
{
    std::string str("pale");

    EXPECT_EQ(isOneAway(str, "bale"), true);
}

TEST(oneAway_str, pale_bake)
{
    std::string str("pale");

    EXPECT_EQ(isOneAway(str, "bake"), false);
}