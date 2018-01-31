#include "gtest/gtest.h"
#include "data-structures/array/array-list.h"
#include "data-structures/tree/binary-search-tree.h"
#include "utils/tree/minimal-tree.h"

TEST(minimal_tree, with_empty_array)
{
    datastructures::ArrayList<int> array;
    datastructures::BinarySearchTree<int> tree = utils::tree::minimalTree(array);

    EXPECT_EQ(tree.isEmpty(), true);
}

TEST(minimal_tree, with_one_value)
{
    datastructures::ArrayList<int> array;
    array.push_back(1);
    datastructures::BinarySearchTree<int> tree = utils::tree::minimalTree(array);

    EXPECT_EQ(tree.isEmpty(), false);
    EXPECT_EQ(tree.contains(1), true);
}
