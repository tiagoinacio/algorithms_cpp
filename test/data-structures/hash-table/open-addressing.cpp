#include "gtest/gtest.h"
#include <string>
#include "data-structures/hash-table/open-addressing.h"

TEST(hash_table, constructor)
{
    datastructures::HashTable<std::string> hashTable;
}

TEST(hash_table, set_get)
{
    datastructures::HashTable<std::string> hashTable;

    hashTable.set("first_name", "tiago");
    hashTable.set("last_name", "inacio");

    ASSERT_EQ(hashTable.get("first_name"), "tiago");
    ASSERT_EQ(hashTable.get("last_name"), "inacio");
}

TEST(hash_table, key_not_found)
{
    datastructures::HashTable<std::string> hashTable;

    ASSERT_ANY_THROW(hashTable.get("some_property"));
}

TEST(hash_table, with_collisions)
{
    datastructures::HashTable<std::string> hashTable;

    hashTable.set("abcde", "abcde");
    hashTable.set("edcba", "edcba");
    hashTable.set("ecdba", "ecdba");

    ASSERT_EQ(hashTable.get("abcde"), "abcde");
    ASSERT_EQ(hashTable.get("edcba"), "edcba");
    ASSERT_EQ(hashTable.get("ecdba"), "ecdba");

    hashTable.remove("edcba");

    ASSERT_EQ(hashTable.get("abcde"), "abcde");
    ASSERT_EQ(hashTable.get("ecdba"), "ecdba");

    hashTable.set("edcba", "new value with removed key");
    ASSERT_EQ(hashTable.get("abcde"), "abcde");
    ASSERT_EQ(hashTable.get("ecdba"), "ecdba");
    ASSERT_EQ(hashTable.get("edcba"), "new value with removed key");
}

TEST(hash_table, exists)
{
    datastructures::HashTable<std::string> hashTable;

    hashTable.set("abcde", "abcde");
    hashTable.set("edcba", "edcba");
    hashTable.set("ecdba", "ecdba");

    ASSERT_EQ(hashTable.exists("abcde"), true);
    ASSERT_EQ(hashTable.exists("edcba"), true);
    ASSERT_EQ(hashTable.exists("ecdba"), true);
    ASSERT_EQ(hashTable.exists("some random key"), false);
    ASSERT_EQ(hashTable.exists("other random key"), false);

    hashTable.remove("edcba");
    ASSERT_EQ(hashTable.exists("edcba"), false);

    hashTable.set("edcba", "new value with removed key");
    ASSERT_EQ(hashTable.exists("edcba"), true);
}