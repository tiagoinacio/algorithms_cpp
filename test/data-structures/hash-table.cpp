#include "gtest/gtest.h"
#include <string>
#include "data-structures/hash-table.h"

TEST(hash_table, constructor)
{
    datastructures::HashTable<std::string> hashTable;

    hashTable.set("name", "tiago");
    ASSERT_EQ(hashTable.get("name"), "tiago");
}
