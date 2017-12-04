#include "gtest/gtest.h"
#include <string>
#include "data-structures/string-builder.h"

TEST(string_builder, constructor)
{
    datastructures::StringBuilder stringBuilder;


    ASSERT_STREQ(stringBuilder.toString(), "");
}

TEST(string_builder, push_back_one)
{
    datastructures::StringBuilder stringBuilder;

    stringBuilder.push_back("foo");

    ASSERT_STREQ(stringBuilder.toString(), "foo");
}

TEST(string_builder, push_back_multiple)
{
    datastructures::StringBuilder stringBuilder;

    stringBuilder.push_back("foo");
    ASSERT_STREQ(stringBuilder.toString(), "foo");

    stringBuilder.push_back("bar");
    ASSERT_STREQ(stringBuilder.toString(), "foobar");

    stringBuilder.push_back("foo");
    ASSERT_STREQ(stringBuilder.toString(), "foobarfoo");
}

TEST(string_builder, duplicate_array)
{
    datastructures::StringBuilder stringBuilder;

    stringBuilder.push_back("1234567891011");
    ASSERT_STREQ(stringBuilder.toString(), "1234567891011");

    stringBuilder.push_back("1234567891011");
    ASSERT_STREQ(stringBuilder.toString(), "12345678910111234567891011");
}

TEST(string_builder, big_values)
{
    datastructures::StringBuilder stringBuilder;

    stringBuilder.push_back("abcdefgh");
    ASSERT_STREQ(stringBuilder.toString(), "abcdefgh");

    stringBuilder.push_back("abcdefgh");
    ASSERT_STREQ(stringBuilder.toString(), "abcdefghabcdefgh");

    stringBuilder.push_back("abcdefgh");
    stringBuilder.push_back("abcdefgh");
    stringBuilder.push_back("abcdefgh");
    ASSERT_STREQ(stringBuilder.toString(), "abcdefghabcdefghabcdefghabcdefghabcdefgh");
}
