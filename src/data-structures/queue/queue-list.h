#ifndef DATA_STRUCTURES_QUEUE_LIST_H_INCLUDED
#define DATA_STRUCTURES_QUEUE_LIST_H_INCLUDED

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
struct QueueNode {
    T data;
    QueueNode* next;
};

template <typename T>
class QueueList {
 private:
    datastructures::QueueNode<T> *head_;
    datastructures::QueueNode<T> *tail_;

 public:
    QueueList() :
        head_(nullptr),
        tail_(nullptr)
        {}

    bool isEmpty() const {
        return head_ == nullptr;
    }

    void enqueue(const T &data) {
        datastructures::QueueNode<T> *node = new datastructures::QueueNode<T>();
        node->data = data;

        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        } else {
            tail_->next = node;
            tail_ = tail_->next;
        }
    }

    T peek() const {
        if (head_ == nullptr) {
            throw std::out_of_range("Queue is empty.");
        }
        return head_->data;
    }

    T dequeue() {
        if (head_ == nullptr) {
            throw std::out_of_range("Queue is empty.");
        }

        datastructures::QueueNode<T> *previousHead = head_;
        T tmpData = head_->data;
        head_ = head_->next;
        delete previousHead;

        return tmpData;
    }
};
}
#endif
