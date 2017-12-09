#ifndef DATA_STRUCTURES_QUEUE_ARRAY_H_INCLUDED
#define DATA_STRUCTURES_QUEUE_ARRAY_H_INCLUDED

#include <memory>
#include <stdexcept>

namespace datastructures {

template <typename T>
class QueueArray {
 private:
     T *array_;
     int capacity_;
     int front_;
     int rear_;

 public:
    QueueArray() :
        array_(new T[10]),
        capacity_(10),
        front_(-1),
        rear_(-1)
        {}

    QueueArray(int capacity) :
        array_(new T[capacity]),
        capacity_(capacity),
        front_(-1),
        rear_(-1)
        {}

    ~QueueArray() {
        delete[] array_;
    }

    bool isEmpty() const {
        return front_ == -1 && rear_ == -1;
    }

    bool isFull() const {
        // return top_ < 0;
        return false;
    }

    void enqueue(const T &data) {
        if (isFull()) {
            throw std::out_of_range("Capacity is full");
        }

        if (isEmpty()) {
            rear_ = front_ = 0;
        } else {
            if (rear_ == capacity_) {
                rear_ = 0;
            } else {
                rear_++;
            }
        }

        array_[rear_] = data;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty.");
        }
        return array_[front_];
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty.");
        }

        int indexToReturn = 0;
        if (front_ == 0) {
            // array is zero based, so we need to subtract one
            front_ = capacity_ - 1;
            indexToReturn = 0;
        } else {
            --front_;
            ++indexToReturn;
        }

        if (rear_ == indexToReturn) {
            rear_ = front_ = -1;
        }

        return array_[indexToReturn];
    }
};
}
#endif
