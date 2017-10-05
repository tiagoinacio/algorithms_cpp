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