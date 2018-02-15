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

TEST(minimal_tree, with_10_values)
{
    /*
     * 1 2 3 4 5 6 7 8 9 10
     *
     *           5
     *    2            8
     * 1    3       7     9
     *        4   6         10
     */
    datastructures::ArrayList<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(8);
    array.push_back(9);
    array.push_back(10);
    datastructures::BinarySearchTree<int> tree = utils::tree::minimalTree(array);

    EXPECT_EQ(tree.isEmpty(), false);
    EXPECT_EQ(tree.contains(1), true);
    EXPECT_EQ(tree.contains(2), true);
    EXPECT_EQ(tree.contains(3), true);
    EXPECT_EQ(tree.contains(4), true);
    EXPECT_EQ(tree.contains(5), true);
    EXPECT_EQ(tree.contains(6), true);
    EXPECT_EQ(tree.contains(7), true);
    EXPECT_EQ(tree.contains(8), true);
    EXPECT_EQ(tree.contains(9), true);
    EXPECT_EQ(tree.contains(10), true);
    EXPECT_EQ(tree.contains(11), false);
    EXPECT_EQ(tree.contains(12), false);
}

    /*
     * 1 2 3 4 5 6 7 8 9 10
     *
     *         5
     *   2
     * 1     4
     *
     */
