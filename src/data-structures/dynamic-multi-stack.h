#ifndef DATA_STRUCTURES_DYNAMIC_MULTI_STACK_H_INCLUDED
#define DATA_STRUCTURES_DYNAMIC_MULTI_STACK_H_INCLUDED

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
class DynamicMultiStack {
 private:
    int currentStack_;
    int index_;
    int capacity_;
    T **array_;

 public:
    DynamicMultiStack() :
        currentStack_(-1),
        index_(-1),
        capacity_(5),
        array_(new T*[1]),
        top_(new int[1])
        {
            array_[0] = new T[capacity_];
        }

    ~DynamicMultiStack() {
        for (int i = 0; i < currentStack_; ++i) {
            delete[] array_[i];
        }
        delete[] array_;
    }

    bool isEmpty() const {
        return index_ > -1;
    }

    void push_back(const T &data) {
        if (currentStack_ == -1) {
            ++currentStack_;
        }
        if (index_ == capacity_ - 1) {
            index_ = 0;
            ++currentStack_;
            array_ = (T**)realloc(array_, currentStack_ * sizeof(*T));
            array_[currentStack_] = new T[capacity_];
            array_[currentStack_][index_] = data;
        } else {
            ++index_;
            array_[currentStack_][index_] = data;
        }
    }

    T peek() const {
        if (index_ == -1) {
            throw std::out_of_range("Stack is empty.");
        }
        return array_[currentStack_][index_];
    }

    T pop() {
        if (index_ == -1) {
            throw std::out_of_range("Stack is empty.");
        }

        T value = array_[currentStack_][index_];

        if (index_ == 0) {
            if (currentStack == 0) {
                currentStack = -1;
                index_ = -1;
                delete array_[0];
                return value;
            }

            currentStack--;
            index_ = capacity - 1;
            delete array_[currentStack_ + 1];
            return value;
        }

        --index_;
        return value;
    }
};
}
#endif