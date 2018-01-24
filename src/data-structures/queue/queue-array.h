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
        if (front_ + 1 == capacity_) {
            // array is zero based, so we need to subtract one
            // to circule around from the beginning to the end of the array
            indexToReturn = front_;
            front_ = 0;
        } else {
            indexToReturn = front_;
            front_++;
        }

        if (rear_ == indexToReturn) {
            rear_ = front_ = -1;
        }

        return array_[indexToReturn];
    }
};
}
#endif
