#ifndef DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED
#define DATA_STRUCTURES_TREE_BINARY_TREE_H_INCLUDED

#include <memory>
#include <iostream>
#include <vector>
#include "data-structures/queue/queue-array.h"

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
        deleteTree(root_);
    }

    void deleteTree(TreeNode<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
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

    bool deleteNode(const T& value) {
        TreeNode<T>* node = root_;

        if (node == nullptr) {
            return false;
        }

        bool isBigger = value > node->value;
        while ((isBigger && node->right != nullptr) || (!isBigger && node->left != nullptr)) {
            if (isBigger) {
                node = node->right;
            } else {
                node = node->left;
            }

            if (!node) {
                return false;
            }

            isBigger = value > node->value;

            if (node->value == value) {
                break;
            }
        }

        if (node->value != value) {
            return false;
        }

        TreeNode<T> *tmp = node;
        TreeNode<T> *parent = node;
        if (isBigger) {
            while (tmp->left) {
                tmp = tmp->left;
                if (tmp->left) {
                    parent = tmp;
                }
            }

            if (tmp == root_) {
                delete root_;
                root_ = nullptr;
                return true;
            }

            T tmpValue = tmp->value;

            node->value = tmpValue;

            delete parent->left;
            parent->left = nullptr;
            return true;
        } else {
            while (tmp->right) {
                tmp = tmp->right;
                if (tmp->right) {
                    parent = tmp;
                }
            }

            if (tmp == root_) {
                delete root_;
                root_ = nullptr;
                return true;
            }

            T tmpValue = tmp->value;

            node->value = tmpValue;

            delete parent->right;
            parent->right = nullptr;

            return true;
        }
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
                queue.enqueue(node->right);
            }
        }
        return vector;
    }
};
}
#endif
