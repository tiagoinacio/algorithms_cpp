#ifndef DATA_STRUCTURES_STACK_LIST_H_INCLUDED
#define DATA_STRUCTURES_STACK_LIST_H_INCLUDED

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
struct StackNode {
    T data;
    StackNode* next;
};

template <typename T>
class StackList {
 private:
    datastructures::StackNode<T> *top_;

 public:
    StackList() :
        top_(nullptr)
        {}

    bool isEmpty() const {
        return top_ == nullptr;
    }

    void push_back(const T &data) {
        datastructures::StackNode<T> *secondNode = top_;
        top_ = new datastructures::StackNode<T>();
        top_->data = data;
        top_->next = secondNode;
    }

    T peek() const throw {
        if (top_ == nullptr) {
            throw std::out_of_range("Stack is empty.");
        }
        return top_->data;
    }

    T pop() throw {
        if (top_ == nullptr) {
            throw std::out_of_range("Stack is empty.");
        }

        datastructures::StackNode<T> *previousHead = top_;
        T tmpData = top_->data;
        top_ = top_->next;
        delete previousHead;

        return tmpData;
    }
};
}
#endif
