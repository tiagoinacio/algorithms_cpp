#include "gtest/gtest.h"
#include <string>
#include "data-structures/string-builder.h"

// TEST(string_builder, constructor)
// {
//     datastructures::StringBuilder stringBuilder;
//
//
//     ASSERT_STREQ(stringBuilder.toString(), "");
// }
//
// TEST(string_builder, append_one)
// {
//     datastructures::StringBuilder stringBuilder;
//
//     stringBuilder.append("foo");
//
//     ASSERT_STREQ(stringBuilder.toString(), "foo");
// }
//
// TEST(string_builder, append_multiple)
// {
//     datastructures::StringBuilder stringBuilder;
//
//     stringBuilder.append("foo");
//     ASSERT_STREQ(stringBuilder.toString(), "foo");
//
//     stringBuilder.append("bar");
//     ASSERT_STREQ(stringBuilder.toString(), "foobar");
//
//     stringBuilder.append("foo");
//     ASSERT_STREQ(stringBuilder.toString(), "foobarfoo");
// }
//
// TEST(string_builder, duplicate_array)
// {
//     datastructures::StringBuilder stringBuilder;
//
//     stringBuilder.append("1234567891011");
//     ASSERT_STREQ(stringBuilder.toString(), "1234567891011");
//
//     stringBuilder.append("1234567891011");
//     ASSERT_STREQ(stringBuilder.toString(), "12345678910111234567891011");
// }
//
// TEST(string_builder, big_values)
// {
//     datastructures::StringBuilder stringBuilder;
//
//     stringBuilder.append("abcdefgh");
//     ASSERT_STREQ(stringBuilder.toString(), "abcdefgh");
//
//     stringBuilder.append("abcdefgh");
//     ASSERT_STREQ(stringBuilder.toString(), "abcdefghabcdefgh");
//
//     // stringBuilder.append("abcdefgh");
//     // stringBuilder.append("abcdefgh");
//     // stringBuilder.append("abcdefgh");
//     // ASSERT_STREQ(stringBuilder.toString(), "abcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh");
// }
