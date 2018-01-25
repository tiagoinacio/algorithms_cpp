#ifndef DATA_STRUCTURES_TREE_TRIE_H_INCLUDED
#define DATA_STRUCTURES_TREE_TRIE_H_INCLUDED

#include <memory>
#include "data-structures/hash-table/open-addressing.h"

namespace datastructures {

struct TrieNode {
    std::string value;
    bool isWord;
    datastructures::HashTable<TrieNode*> childrens;

    TrieNode(const std::string& value_)
        :
        value(value_),
        isWord(false),
        childrens(datastructures::HashTable<TrieNode*>())
        {}
};

template <typename T>
class Trie {
 private:
    TrieNode* root_;

 public:
    Trie<T>()
    :
    root_(nullptr)
    {}

    ~Trie<T>() {
    }

    // should validate if it is valid char of alphabet
    void insert(const T& value) {
        TrieNode* node = root_;

        for (auto i : value) {
            const std::string e = std::string(1, i);

            if (node == nullptr) {
                node = new TrieNode(e);
                root_ = node;
            } else {
                if (node->childrens.exists(e)) {
                    node = node->childrens.get(e);
                } else {
                    TrieNode* children = new TrieNode(e);
                    node->childrens.set(e, children);
                    node = children;
                }
            }
        }
    }

    void deleteNode() {

    }

    void search() {

    }

    TrieNode* root() {
        return root_;
    }
};

}

#endif