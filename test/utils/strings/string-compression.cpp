#include "gtest/gtest.h"
#include "utils/strings/string-compression.cpp"
#include <string>

TEST(stringCompression, with_empty_string)
{
    std::string str("");

    EXPECT_EQ(stringCompression(str), "");
}