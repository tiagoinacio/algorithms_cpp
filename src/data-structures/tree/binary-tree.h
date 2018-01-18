#ifndef DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED
#define DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED

#include <memory>
#include <iostream>

namespace datastructures {

template <typename E>
struct TreeNode {
    E value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const E& value_)
        :
        value(value_),
        left(nullptr),
        right(nullptr)
        {}
};

template <typename T>
class BinaryTree {
 private:
    TreeNode<T>* root_;

 public:
    BinaryTree<T>()
    :
    root_(nullptr)
    {}

    ~BinaryTree<T>() {
        deleteNode(root_);
    }

    void deleteNode(TreeNode<T>* node) {
        if (node != nullptr) {
            deleteNode(node->left);
            deleteNode(node->right);
            delete node;
        }
    }

    void preOrderTraversalInsert(const T& value, TreeNode<T>* node) {
        if (value < node->value) {
            if (node->left != nullptr) {
                preOrderTraversalInsert(value, node->left);
            } else {
                TreeNode<T>* newNode = new TreeNode<T>(value);
                node->left = newNode;
            }
        } else if (value > node->value) {
            if (node->right != nullptr) {
                preOrderTraversalInsert(value, node->right);
            } else {
                TreeNode<T>* newNode = new TreeNode<T>(value);
                node->right = newNode;
            }
        }
    }

    void insert(const T& value) {
        TreeNode<T>* node = root_;

        if (node == nullptr) {
            root_ = new TreeNode<T>(value);
            return;
        }

        preOrderTraversalInsert(value, node);
    }

    TreeNode<T>* root() {
        return root_;
    }

    TreeNode<T>* search(const T& key) {
        if (root_ == nullptr) {
            throw std::out_of_range("tree is empty");
        }
        return preOrderTraversalSearch(key, root_);
    }

    TreeNode<T>* preOrderTraversalSearch(const T& key, TreeNode<T>* node) {
        if (node != nullptr) {
            if (key == node->value) {
                return node;
            }

            if (key < node->value) {
                return preOrderTraversalSearch(key, node->left);
            }

            return preOrderTraversalSearch(key, node->right);
        }

        throw std::out_of_range("key not found");
    }

    std::vector<T> getAscendingValues() {
        std::vector<T> vector;

        inOrderTraversal(root_, vector);

        return vector;
    }

    void inOrderTraversal(TreeNode<T>* node, std::vector<T>& vector) {
        if (node != nullptr) {
            inOrderTraversal(node->left, vector);
            vector.push_back(node->value);
            inOrderTraversal(node->right, vector);
        }
    }

    std::vector<T> getDescendingValues() {
        std::vector<T> vector;

        postOrderTraversal(root_, vector);

        return vector;
    }

    void postOrderTraversal(TreeNode<T>* node, std::vector<T>& vector) {
        if (node != nullptr) {
            postOrderTraversal(node->right, vector);
            vector.push_back(node->value);
            postOrderTraversal(node->left, vector);
        }
    }
};
}
#endif