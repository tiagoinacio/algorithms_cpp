#include "gtest/gtest.h"
#include <string>
#include "data-structures/tree/trie.h"

TEST(trie, constructor) {
    datastructures::Trie<std::string> trie;

    ASSERT_TRUE(trie.root() != nullptr);
    ASSERT_TRUE(trie.root()->isEndOfWord == false);
}

TEST(trie, insert_contains) {
    datastructures::Trie<std::string> trie;

    trie.insert("tiago");

    ASSERT_EQ(trie.contains("t"), false);
    ASSERT_EQ(trie.contains("ti"), false);
    ASSERT_EQ(trie.contains("tia"), false);
    ASSERT_EQ(trie.contains("tiag"), false);
    ASSERT_EQ(trie.contains("tiago"), true);
}

TEST(trie, isPrefix) {
    datastructures::Trie<std::string> trie;

    trie.insert("tiago");

    ASSERT_EQ(trie.isPrefix("t"), true);
    ASSERT_EQ(trie.isPrefix("ti"), true);
    ASSERT_EQ(trie.isPrefix("tia"), true);
    ASSERT_EQ(trie.isPrefix("tiag"), true);
    ASSERT_EQ(trie.isPrefix("tiago"), false);
}

TEST(trie, deleteNode) {
    datastructures::Trie<std::string> trie;

    trie.insert("tiago");

    ASSERT_EQ(trie.contains("tiago"), true);

    trie.deleteNode(trie.root());

    ASSERT_EQ(trie.contains("t"), false);
    ASSERT_EQ(trie.contains("ti"), false);
    ASSERT_EQ(trie.contains("tia"), false);
    ASSERT_EQ(trie.contains("tiag"), false);
    ASSERT_EQ(trie.contains("tiago"), false);
}