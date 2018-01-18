#ifndef DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED
#define DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED

#include <memory>
#include <iostream>

namespace datastructures {

template <typename E>
struct TreeNode {
    E value;
    TreeNode* leftNode;
    TreeNode* rightNode;
};

template <typename T>
class BinaryTree {
 private:
    TreeNode<T>* root_;

 public:
    BinaryTree<T>() {}

    void insert(const T& value) {
        TreeNode<T>* node = root_;

        if (node == nullptr) {
            root_ = new TreeNode<T>;
            root_->value = value;
            return;
        }

        inOrderTraversalInsert(node);
    }

    inOrderTraversalInsert(TreeNode<T>& node) {
    }

    ~BinaryTree<T>() {
    }

};
}
#endif