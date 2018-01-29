#ifndef DATA_STRUCTURES_TREE_MIN_HEAP_H_INCLUDED
#define DATA_STRUCTURES_TREE_MIN_HEAP_H_INCLUDED

#include <memory>
#include <iostream>
#include <vector>
#include "data-structures/queue/queue-array.h"

namespace datastructures {

template <typename E>
struct MinHeapNode {
    E value;
    MinHeapNode* left;
    MinHeapNode* right;

    MinHeapNode(const E& value_)
        :
        value(value_),
        left(nullptr),
        right(nullptr)
        {}
};

template <typename T>
class MinHeap {
 private:
    MinHeapNode<T>* root_;

 public:
    MinHeap<T>()
    :
    root_(nullptr)
    {}

    ~MinHeap<T>() {
    }
};
}
#endif
