#ifndef DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED
#define DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED

#include <memory>
#include <iostream>
#include <vector>
#include "data-structures/queue-array.h"

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

    TreeNode<T>* search(const T& value) {
        if (root_ == nullptr) {
            throw std::out_of_range("tree is empty");
        }
        return preOrderTraversalSearch(value, root_);
    }
    /* TODO
     * insert Iteratively
     *
     */

    bool insertIteratively(const T& value) {
        TreeNode<T>* currentNode = root_;

        if(currentNode == nullptr) {
            root_ = new TreeNode<T>(value);
            return true;
        }

        bool isBigger = value > currentNode->value;
        while (((!isBigger && currentNode->left != nullptr) || (isBigger && currentNode->right != nullptr))) {
            // element with the same value already found in the tree
            if (currentNode->value == value) {
                return false;
            }

            if (value > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
            isBigger = value > currentNode->value;
        }

        if (value > currentNode->value) {
            currentNode->right = new TreeNode<T>(value);
            return true;
        }

        if (value < currentNode->value) {
            currentNode->left = new TreeNode<T>(value);
            return true;
        }

        // element with the same value already found in the tree
        return false;
    }

    void deleteKey() {

        // iterate until last left child is nullptr
        // copy value to deleted node
        // delete last left child
    }

    TreeNode<T>* searchIteratively(const T& value) {
        TreeNode<T>* currentNode = root_;

        while (currentNode) {
            if (currentNode->value == value) {
                return currentNode;
            }

            if (value < currentNode) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }

        throw std::out_of_range("tree is empty");
    }

    TreeNode<T>* preOrderTraversalSearch(const T& value, TreeNode<T>* node) {
        if (node != nullptr) {
            if (value == node->value) {
                return node;
            }

            if (value < node->value) {
                return preOrderTraversalSearch(value, node->left);
            }

            return preOrderTraversalSearch(value, node->right);
        }

        throw std::out_of_range("value not found");
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

    std::vector<T> breadthFirstTraversal() {
        auto queue = datastructures::QueueArray<TreeNode<T>*>();
        auto vector = std::vector<T>{};

        queue.enqueue(root_);

        while (!queue.isEmpty()) {
            auto node = queue.dequeue();

            vector.push_back(node->value);

            if (node->left != nullptr) {
                queue.enqueue(node->left);
            }

            if (node->right != nullptr) {
                queue.enqueue(node->left);
            }
        }
        return vector;
    }
};
}
#endif