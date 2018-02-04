#ifndef UTILS_TREE_MINIMAL_TREE_H_INCLUDED
#define UTILS_TREE_MINIMAL_TREE_H_INCLUDED

#include "data-structures/tree/binary-search-tree.h"
#include "gsl/gsl"

namespace utils {

namespace tree {

template <typename T>
void insertInto(datastructures::BinarySearchTree<T>& tree,
    datastructures::ArrayList<T>& array, const T& min, const T& max) {
    int middle = static_cast<T>(max / 2);

    tree.insert(array.get(min + middle));
    insertInto(tree, array, 0, middle);
    insertInto(tree, array, middle, max);
}

template <typename T>
datastructures::BinarySearchTree<T> minimalTreeOptimized(
    datastructures::ArrayList<T>& array) {
    datastructures::BinarySearchTree<T> tree;

    for (int i = 0; i < array.size(); i++) {
        tree.insert(array.get(i));
    }

    return tree;
}
}   // namespace tree
}   // namespace utils

namespace utils {

namespace tree {

/*
 * Minimal Tree:
 *
 * Given a sorted (increasing order) array with unique integer elements,
 * write an algorithm to create a binary search tree with minimal height.
 *
 * 1 2 3 4 5 6 7 8 9 10
 *
 *           5
 *    2            8
 * 1    3       7     9
 *        4   6         10
 *
 *
 * To create a tree of minimal height, we need to match the number of nodes
 * in the left subtree to the number of nodes in the right subtree as much
 * as possible. This means that we want the root to be the middle of the array,
 * since this would mean that half the elements would be less than the root
 * and half would be greater than it.
 * We proceed with constructing our tree in a similar fashion.
 * The middle of each subsection of the array becomes the root of the node.
 * The left half of the array will become our left subtree, and the right half
 * of the array will become the right subtree.
 * One way to implement this is to use a simple root.insertNode(int v) method
 * which inserts the value v through a recursive process that starts with the
 * root node.
 * This will indeed construct a tree with minimal height but it will not do
 * so very efficiently.
 * Each insertion will require traversing the tree, giving a
 * total cost of O(N log N) to the tree.
 * Alternatively, we can cut out the extra traversals by recursively using the
 * createMinimalBST method.
 * This method is passed just a subsection of the array and returns the root
 * of a minimal tree for that array.
 *
 * The algorithm is as follows:
 * 1. Insert into the tree the middle element of the array.
 * 2. Insert (into the left subtree) the left sub array elements.
 * 3. Insert (into the right sub tree) the right sub array elements.
 * 4. Recurse.
 *
 */
template <typename T>
datastructures::BinarySearchTree<T> minimalTree(
    datastructures::ArrayList<T>& array) {
    datastructures::BinarySearchTree<T> tree;

    size_t arraySize = array.size();
    int left = static_cast<T>(arraySize / 2);
    int right = left;

    if (left != 0) {
        tree.insert(left);
    }

    insertInto<int>(tree, array, 0, arraySize - 1);

    return tree;
}
}   // namespace tree
}   // namespace utils

#endif
