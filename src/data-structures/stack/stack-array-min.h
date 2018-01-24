#ifndef DATA_STRUCTURES_STACK_ARRAY_MIN_H_INCLUDED
#define DATA_STRUCTURES_STACK_ARRAY_MIN_H_INCLUDED

#include <memory>
#include <stdexcept>
#include "./stack-array.h"

namespace datastructures {

template <typename T>
class StackArrayMin : public datastructures::StackArray<T> {
 private:
     datastructures::StackArray<T> minStack_;

 public:
    void push_back(const T &data) {
        if (minStack_.isEmpty()) {
            minStack_.push_back(data);
        } else {
            if (data < minStack_.peek()) {
                minStack_.push_back(data);
            }
        }
        datastructures::StackArray<T>::push_back(data);
    }

    T pop() {
        T value = datastructures::StackArray<T>::pop();

        if (!minStack_.isEmpty()) {
            if (value == minStack_.peek()) {
                minStack_.pop();
            }
        }

        return value;
    }

    T min() {
        if (minStack_.isEmpty()) {
            throw std::out_of_range("stack is empty");
        }
        return minStack_.peek();
    }
};
}
#endif
