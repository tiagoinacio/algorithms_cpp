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
    bool isSecondStackEmpty;
 public:
    QueueStack() :
        firstStack_(datastructures::StackList<T>()),
        secondStack_(datastructures::StackList<T>()),
        isSecondStackEmpty(true)
        {}

    bool isEmpty() const {
        return firstStack_.isEmpty() && secondStack_.isEmpty();
    }

    void enqueue(const T &data) {
        if (isSecondStackEmpty == false) {
            while (!secondStack_.isEmpty()) {
                firstStack_.push_back(secondStack_.pop());
            }
            isSecondStackEmpty = true;
        }
        firstStack_.push_back(data);
    }

    T peek() {
        if (isSecondStackEmpty == true) {
            while (!firstStack_.isEmpty()) {
                secondStack_.push_back(firstStack_.pop());
            }

            isSecondStackEmpty = false;
        }

        T value = secondStack_.peek();

        return value;
    }

    T dequeue() {
        if (isSecondStackEmpty == true) {
            while (!firstStack_.isEmpty()) {
                secondStack_.push_back(firstStack_.pop());
            }

            isSecondStackEmpty = false;
        }

        return secondStack_.pop();
    }
};
}
#endif
