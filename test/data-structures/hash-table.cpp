#include "gtest/gtest.h"
#include <string>
#include "data-structures/hash-table.h"

TEST(hash_table, constructor)
{
    datastructures::HashTable<std::string> hashTable;

    hashTable.set("first_name", "tiago");
    hashTable.set("last_name", "inacio");

    ASSERT_EQ(hashTable.get("first_name"), "tiago");
    ASSERT_EQ(hashTable.get("last_name"), "inacio");

    //ASSERT_EQ(hashTable.get("some_property"), "");
}
