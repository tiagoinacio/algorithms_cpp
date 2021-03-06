#ifndef DATA_STRUCTURES_TREE_TRIE_H_INCLUDED
#define DATA_STRUCTURES_TREE_TRIE_H_INCLUDED

#include <memory>
#include "data-structures/hash-table/open-addressing.h"
#include "data-structures/queue/queue-list.h"
#include "data-structures/stack/stack-list.h"
#include <iostream>

namespace datastructures {

const size_t ALPHABET_SIZE = 26;

struct TrieNode {
    bool isEndOfWord;
    TrieNode* childrens[ALPHABET_SIZE]; // alphabet size

    TrieNode()
        :
        isEndOfWord(false),
        childrens()
        {}
};

template <typename T>
class Trie {
 private:
    TrieNode* root_;

    TrieNode* findNode(const T& word) {
        TrieNode* node = root_;

        if (node == nullptr) {
            return nullptr;
        }

        for (const char i : word) {
            size_t index = i - 'a';

            if (node->childrens[index] != nullptr) {
                node = node->childrens[index];
            } else {
                return nullptr;
            }
        }
        return node;
    }

 public:
    Trie<T>()
    :
    root_(new TrieNode())
    {}

    ~Trie<T>() {
        deleteNode(root_);
    }

    void deleteNode(TrieNode* node) {
        auto queue = datastructures::QueueList<TrieNode*>();

        if (node == nullptr) {
            return;
        }

        queue.enqueue(node);

        while (!queue.isEmpty()) {
            auto node = queue.dequeue();

            for (auto i = 0; i < ALPHABET_SIZE; ++i) {
                if (node->childrens[i] != nullptr) {
                    queue.enqueue(node->childrens[i]);
                    node->childrens[i] = nullptr;
                }
            }

            if (node == root_) {
                root_ = nullptr;
            }

            if (node) {
                delete node;
            }
        }
    }

    // should validate if it is valid char of alphabet
    void insert(const T& word) {
        TrieNode* node = root_;

        for (const char i : word) {
            // if 'a', then is inserted at position 0,
            // if 'b', then is inserted at position 1,
            // and so on, until reach the limit of 26
            size_t index = i - 'a';

            if (node->childrens[index] != nullptr) {
                node = node->childrens[index];
            } else {
                TrieNode* children = new TrieNode();
                node->childrens[index] = children;
                node = children;
            }
        }

        node->isEndOfWord = true;
    }

    void deleteWord(const std::string &word) {
        TrieNode* node = root_;
        TrieNode** nodes = new TrieNode*[word.length()];
        size_t nodeIndex = 0;

        for (const char i : word) {
            // if 'a', then is inserted at position 0,
            // if 'b', then is inserted at position 1,
            // and so on, until reach the limit of 26
            size_t index = i - 'a';

            if (node->childrens[index] != nullptr) {
                nodes[nodeIndex] = node;
                nodeIndex++;
                node = node->childrens[index];
            } else {
                delete[] nodes;
                throw std::out_of_range("word not found");
            }
        }

        if (!node->isEndOfWord) {
            delete[] nodes;
            throw std::out_of_range("word not found");
        }

        int i = word.size() - 1;
        while (i > -1) {
            if (!nodes[i]->isEndOfWord) {
                TrieNode* tmp = nodes[i]->childrens[word[i] - 'a'];
                nodes[i]->childrens[word[i] - 'a'] = nullptr;
                delete tmp;
            } else {
               break;
            }
            i--;
        }
        delete[] nodes;
    }

    bool contains(const T& word) {
        TrieNode* node = findNode(word);

        if (node == nullptr) {
            return false;
        }

        return node->isEndOfWord;
    }

    bool isPrefix(const T& word) {
        TrieNode* node = findNode(word);

        if (node == nullptr) {
            return false;
        }

        return !node->isEndOfWord;
    }

    TrieNode* root() {
        return root_;
    }
};

}

#endif