#ifndef DATA_STRUCTURES_QUEUE_STACK_H_INCLUDED
#define DATA_STRUCTURES_QUEUE_STACK_H_INCLUDED

#include <memory>
#include <stdexcept>
#include "./stack-list.h"

namespace datastructures {

template <typename T>
class QueueStack {
 private:
    datastructures::StackList<T> firstStack_;
    datastructures::StackList<T> secondStack_;
 public:
    QueueStack() :
        {}

    ~QueueStack() {
    }

    bool isEmpty() const {
    }

    bool isFull() const {
    }

    void enqueue(const T &data) {
        // push to stack
    }

    T peek() const {
    }

    T dequeue() {
    }
};
}
#endif
