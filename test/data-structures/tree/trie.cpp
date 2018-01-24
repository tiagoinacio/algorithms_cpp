#include "gtest/gtest.h"
#include <string>
#include "data-structures/tree/trie.h"

TEST(trie, insert) {
    datastructures::Trie<std::string> trie;

    trie.insert("tiago");

    ASSERT_STREQ(trie.root()->value.c_str(), "t");
}