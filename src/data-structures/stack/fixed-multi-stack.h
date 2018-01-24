#ifndef DATA_STRUCTURES_FIXED_MULTI_STACK_H_INCLUDED
#define DATA_STRUCTURES_FIXED_MULTI_STACK_H_INCLUDED

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
class FixedMultiStack {
 private:
    int numberOfStacks_;
    int capacity_;
    T **array_;
    int *top_;

 public:
    FixedMultiStack() :
        numberOfStacks_(3),
        capacity_(10),
        array_(new T*[3]),
        top_(new int[3])
        {
            for (int x = 0; x < numberOfStacks_; ++x) {
                array_[x] = new T[capacity_];
                top_[x] = -1;
            }
        }

    FixedMultiStack(int numberOfStacks) :
        numberOfStacks_(numberOfStacks),
        capacity_(10),
        array_(new T*[numberOfStacks]),
        top_(new int[numberOfStacks])
        {
            for (int x = 0; x < numberOfStacks_; ++x) {
                array_[x] = new T[capacity_];
                top_[x] = -1;
            }
        }

    FixedMultiStack(int numberOfStacks, int capacity) :
        numberOfStacks_(numberOfStacks),
        capacity_(capacity),
        array_(new T*[numberOfStacks]),
        top_(new int[numberOfStacks])
        {
            for (int x = 0; x < numberOfStacks_; ++x) {
                array_[x] = new T[capacity_];
                top_[x] = -1;
            }
        }

    ~FixedMultiStack() {
        for (int x = 0; x < numberOfStacks_; ++x) {
            delete[] array_[x];
        }
        delete[] array_;
        delete[] top_;
    }

    bool isEmpty(int stackNumber) const {
        if (stackNumber >= numberOfStacks_) {
            throw std::out_of_range("Stack number is bigger than number of stacks");
        }
        return top_[stackNumber] < 0;
    }

    void push_back(int stackNumber, const T &data) {
        if (stackNumber >= numberOfStacks_) {
            throw std::out_of_range("Stack number is bigger than number of stacks");
        }
        if (top_[stackNumber] == capacity_) {
            throw std::out_of_range("Capacity is full");
        }
        ++top_[stackNumber];
        array_[stackNumber][top_[stackNumber]] = data;
    }

    T peek(int stackNumber) const {
        if (stackNumber >= numberOfStacks_) {
            throw std::out_of_range("Stack number is bigger than number of stacks");
        }
        if (top_[stackNumber] < 0) {
            throw std::out_of_range("Stack is empty.");
        }
        return array_[stackNumber][top_[stackNumber]];
    }

    T pop(int stackNumber) {
        if (stackNumber >= numberOfStacks_) {
            throw std::out_of_range("Stack number is bigger than number of stacks");
        }
        if (top_[stackNumber] < 0) {
            throw std::out_of_range("Stack is empty.");
        }

        --top_[stackNumber];
        return array_[stackNumber][top_[stackNumber] + 1];
    }
};
}
#endif