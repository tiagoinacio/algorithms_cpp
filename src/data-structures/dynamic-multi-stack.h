#ifndef DATA_STRUCTURES_DYNAMIC_MULTI_STACK_H_INCLUDED
#define DATA_STRUCTURES_DYNAMIC_MULTI_STACK_H_INCLUDED

/*
Stack of Plates:

Imagine a (literal) stack of plates.
If the stack gets too high, it might topple.
Composed of several stacks and should create a new stack once the previous one exceeds capacity.
SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack
(that is, pop() should return the same values as it would if there were just a single stack).

FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

There are two possible solutions for the popAt function.

- Keep poping from stacks and have some kind of index to indicate wihch is the last element of each stack.
  The downside of this is that we may waste space.

- Every time we pop from a stack, we shift all the elements from the right to the left.
  This could be performed at O(n) time.
*/

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
class DynamicMultiStack {
 private:
    int currentStack_;
    int *index_;
    // create array for each stack to keep track of index value
    // to make popAtStack work
    // each stack needs to have an index indicating wether they are full or not
    int capacity_;
    T **array_;

 public:
    DynamicMultiStack() :
        currentStack_(-1),
        index_(new int[1]),
        capacity_(5),
        array_(new T*[1])
        {
            array_[0] = new T[capacity_]{};
            index_[0] = -1;
        }

    ~DynamicMultiStack() {
        for (int i = 0; i <= currentStack_; ++i) {
            delete[] array_[i];
        }
        if (array_) {
            if (currentStack_ == -1) {
                delete[] array_[0];
            }
            delete[] array_;
        }
        delete[] index_;
    }

    bool isEmpty() const {
        return currentStack_ == -1 || index_[currentStack_] == -1;
    }

    void push_back(const T &data) {
        if (currentStack_ == -1) {
            // already instantiated
            ++currentStack_;
        }
        if (index_[currentStack_] == capacity_ - 1) {
            ++currentStack_;
            array_ = (T**)realloc(array_, currentStack_ * sizeof(T*));
            index_ = (int*)realloc(index_, currentStack_ * sizeof(int));
            index_[currentStack_] = 0;
            array_[currentStack_] = new T[capacity_]{};
            array_[currentStack_][0] = data;
        } else {
            index_[currentStack_] = index_[currentStack_] + 1;
            array_[currentStack_][index_[currentStack_]] = data;
        }
    }

    T peek() const {
        if (index_[currentStack_] == -1) {
            throw std::out_of_range("Stack is empty.");
        }
        return array_[currentStack_][index_[currentStack_]];
    }

    T pop() {
        if (index_[currentStack_] == -1 || currentStack_ == -1) {
            throw std::out_of_range("Stack is empty.");
        }

        T value = array_[currentStack_][index_[currentStack_]];

        if (index_[currentStack_] == 0) {
            if (currentStack_ == 0) {
                currentStack_ = -1;
                index_[0] = -1;
                return value;
            }

            currentStack_--;
            index_[currentStack_ + 1] = capacity_ - 1;
            delete[] array_[currentStack_ + 1];
            return value;
        }

        index_[currentStack_] = index_[currentStack_] - 1;
        return value;
    }

    T popAtStack(int stack) {
        if (index_[stack] == -1 || stack > currentStack_ || stack < 0) {
            throw std::out_of_range("Stack is empty.");
        }

        T value = array_[stack][index_[stack]];

        if (index_[stack] == 0) {
            if (currentStack_ == 0) {
                currentStack_ = -1;
                index_[0] = -1;
                return value;
            }

            currentStack_--;
            index_[stack] = capacity_ - 1;
            delete[] array_[currentStack_ + 1];
            index_ = (int*)realloc(index_, currentStack_ * sizeof(int));
            return value;
        }

        index_[stack] = index_[stack] - 1;
        return value;
    }
};
}
#endif
