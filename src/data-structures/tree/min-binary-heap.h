#ifndef DATA_STRUCTURES_TREE_MIN_HEAP_H_INCLUDED
#define DATA_STRUCTURES_TREE_MIN_HEAP_H_INCLUDED

#include <memory>
#include <iostream>
#include <vector>
#include "data-structures/array/array-list.h"

namespace datastructures {

template <typename T>
class MinBinaryHeap {
 private:
     datastructures::ArrayList<T> array_;

    void bubbleDown() {

    }

    void bubbleUp() {

    }

 public:
    MinBinaryHeap<T>()
    :
    array_(datastructures::ArrayList<T>())
    {}

    ~MinBinaryHeap<T>() {
    }

    void insert(const T& value) {

    }

    T min() {

    }

    void deleteMin() {

    }
};
}
#endif
