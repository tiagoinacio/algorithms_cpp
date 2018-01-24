#include "gtest/gtest.h"
#include "data-structures/tree/binary-tree.h"
#include <vector>

TEST(binary_tree, insert)
{
    /*
     *             10
     *       4             15
     *    1     6      13       17
     * 0             11
     *
     */
    datastructures::BinaryTree<double> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(17);
    tree.insert(13);
    tree.insert(4);
    tree.insert(6);
    tree.insert(1);
    tree.insert(0);
    tree.insert(11);

    ASSERT_EQ(tree.root()->value, 10);
    ASSERT_EQ(tree.root()->left->value, 4);
    ASSERT_EQ(tree.root()->left->left->value, 1);
    ASSERT_EQ(tree.root()->left->left->left->value, 0);
    ASSERT_EQ(tree.root()->left->right->value, 6);
    ASSERT_EQ(tree.root()->right->value, 15);
    ASSERT_EQ(tree.root()->right->right->value, 17);
    ASSERT_EQ(tree.root()->right->left->value, 13);
    ASSERT_EQ(tree.root()->right->left->left->value, 11);
}

TEST(binary_tree, insert_iteratively)
{
    /*
     *             10
     *       4             15
     *    1     6      13       17
     * 0             11
     *
     */
    datastructures::BinaryTree<double> tree;

    tree.insertIteratively(10);
    tree.insertIteratively(15);
    tree.insertIteratively(17);
    tree.insertIteratively(13);
    tree.insertIteratively(4);
    tree.insertIteratively(6);
    tree.insertIteratively(1);
    tree.insertIteratively(0);
    tree.insertIteratively(11);

    ASSERT_EQ(tree.root()->value, 10);
    ASSERT_EQ(tree.root()->left->value, 4);
    ASSERT_EQ(tree.root()->left->left->value, 1);
    ASSERT_EQ(tree.root()->left->left->left->value, 0);
    ASSERT_EQ(tree.root()->left->right->value, 6);
    ASSERT_EQ(tree.root()->right->value, 15);
    ASSERT_EQ(tree.root()->right->right->value, 17);
    ASSERT_EQ(tree.root()->right->left->value, 13);
    ASSERT_EQ(tree.root()->right->left->left->value, 11);
}

TEST(binary_tree, with_value_already_in_the_tree)
{
    datastructures::BinaryTree<double> tree;

    ASSERT_EQ(tree.insertIteratively(10), true);
    ASSERT_EQ(tree.insertIteratively(10), false);

    tree.insertIteratively(15);
    tree.insertIteratively(20);
    ASSERT_EQ(tree.insertIteratively(20), false);
}

TEST(binary_tree, search)
{
    datastructures::BinaryTree<double> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(17);
    tree.insert(13);
    tree.insert(4);
    tree.insert(6);
    tree.insert(1);
    tree.insert(0);
    tree.insert(11);

    ASSERT_EQ(tree.search(10)->value, 10);
    ASSERT_EQ(tree.search(4)->value, 4);
    ASSERT_EQ(tree.search(1)->value, 1);
    ASSERT_EQ(tree.search(0)->value, 0);
    ASSERT_EQ(tree.search(6)->value, 6);
    ASSERT_EQ(tree.search(15)->value, 15);
    ASSERT_EQ(tree.search(17)->value, 17);
    ASSERT_EQ(tree.search(13)->value, 13);
    ASSERT_EQ(tree.search(11)->value, 11);
}

TEST(binary_tree, search_out_of_range)
{
    datastructures::BinaryTree<double> tree;

    ASSERT_THROW(tree.search(10), std::out_of_range);

    tree.insert(5);

    ASSERT_THROW(tree.search(6), std::out_of_range);
}

TEST(binary_tree, in_order_traversal)
{
    datastructures::BinaryTree<double> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(17);
    tree.insert(13);
    tree.insert(4);
    tree.insert(6);
    tree.insert(1);
    tree.insert(0);
    tree.insert(11);

    std::vector<double> vector = tree.getAscendingValues();

    ASSERT_EQ(vector[0], 0);
    ASSERT_EQ(vector[1], 1);
    ASSERT_EQ(vector[2], 4);
    ASSERT_EQ(vector[3], 6);
    ASSERT_EQ(vector[4], 10);
    ASSERT_EQ(vector[5], 11);
    ASSERT_EQ(vector[6], 13);
    ASSERT_EQ(vector[7], 15);
    ASSERT_EQ(vector[8], 17);
}

TEST(binary_tree, post_order_traversal)
{
    datastructures::BinaryTree<double> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(17);
    tree.insert(13);
    tree.insert(4);
    tree.insert(6);
    tree.insert(1);
    tree.insert(0);
    tree.insert(11);

    std::vector<double> vector = tree.getDescendingValues();

    ASSERT_EQ(vector[0], 17);
    ASSERT_EQ(vector[1], 15);
    ASSERT_EQ(vector[2], 13);
    ASSERT_EQ(vector[3], 11);
    ASSERT_EQ(vector[4], 10);
    ASSERT_EQ(vector[5], 6);
    ASSERT_EQ(vector[6], 4);
    ASSERT_EQ(vector[7], 1);
    ASSERT_EQ(vector[8], 0);
}

/*
 *             10
 *       4             15
 *    1     6      13       17
 * 0             11
 *
 */
TEST(binary_tree, breadthFirstTraversal)
{
    datastructures::BinaryTree<double> tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(17);
    tree.insert(13);
    tree.insert(4);
    tree.insert(6);
    tree.insert(1);
    tree.insert(0);
    tree.insert(11);

    std::vector<double> vector = tree.breadthFirstTraversal();

    ASSERT_EQ(vector[0], 10);
    ASSERT_EQ(vector[1], 4);
    ASSERT_EQ(vector[2], 15);
    ASSERT_EQ(vector[3], 1);
    ASSERT_EQ(vector[4], 6);
    ASSERT_EQ(vector[5], 13);
    ASSERT_EQ(vector[6], 17);
    ASSERT_EQ(vector[7], 0);
    ASSERT_EQ(vector[8], 11);
}