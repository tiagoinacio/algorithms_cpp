#ifndef DATA_STRUCTURES_STACK_ARRAY_H_INCLUDED
#define DATA_STRUCTURES_STACK_ARRAY_H_INCLUDED

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
class StackArray {
 private:
     T *array_;
     int capacity_;
     int top_;

 public:
    StackArray() :
        array_(new T[10]),
        capacity_(10),
        top_(-1)
        {}

    StackArray(int capacity) :
        array_(new T[capacity]),
        capacity_(capacity),
        top_(-1)
        {}

    ~StackArray() {
        delete[] array_;
    }

    bool isEmpty() const {
        return top_ < 0;
    }

    void push_back(const T &data) {
        if (top_ == capacity_) {
            throw std::out_of_range("Capacity is full");
        }
        ++top_;
        array_[top_] = data;
    }

    T peek() const {
        if (top_ < 0) {
            throw std::out_of_range("Stack is empty.");
        }
        return array_[top_];
    }

    T pop() {
        if (top_ < 0) {
            throw std::out_of_range("Stack is empty.");
        }

        --top_;
        return array_[top_ + 1];
    }
};
}
#endif
