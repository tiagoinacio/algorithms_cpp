#ifndef DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_WITH_TAIL_H_INCLUDED
#define DATA_STRUCTURES_LINKED_LIST_SINGLY_LINKED_LIST_WITH_TAIL_H_INCLUDED

#include <gsl/gsl>
#include <iostream>
#include <memory>
#include <utility>
#include <stdexcept>

namespace datastructures {

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class LinkedListWithTail {
 private:
    datastructures::Node<T>* head_;
    datastructures::Node<T>* tail_;
    size_t size_;

 public:
    LinkedListWithTail() :
        head_(nullptr),
        size_(0) {}

    ~LinkedListWithTail() {
        if (head_ != nullptr) {
            while (head_->next != nullptr) {
                datastructures::Node<T>* tmp = head_;
                head_ = head_->next;
                delete tmp;
            }
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }
    }

    LinkedListWithTail<T>(const LinkedListWithTail<T>& other) {
        datastructures::Node<T>* current = other.head_;
        datastructures::Node<T>* newNode = new datastructures::Node<T>();
        head_ = newNode;
        tail_ = newNode;

        size_ = other.size();

        while (current != nullptr) {
            newNode->value = current->value;
            newNode->next = new datastructures::Node<T>();
            newNode = newNode->next;
            current = current->next;
            tail_ = current;
        }
    }

    // assignment operator
    LinkedListWithTail<T>& operator=(const LinkedListWithTail<T>& rhs) {
        if (this != &rhs) {
            auto tmp(rhs);
            std::swap(head_, tmp.head_);
            std::swap(tail_, tmp.tail_);
            std::swap(size_, tmp.size_);
        }
        return *this;
    }

    void push_back(const T& value) {
        if (head_ == nullptr) {
            head_ = tail_ = new datastructures::Node<T>();
            head_->value = value;
            size_++;
            return;
        }

        tail_->next = new datastructures::Node<T>();
        tail_->next->value = value;
        tail_ = tail_->next;
        size_++;
    }

    T pop_back() {
        if (head_ == nullptr) {
            throw std::out_of_range("head is null");
        }

        // we need a previous pointer to make it point to nullptr
        datastructures::Node<T>* current = head_;
        datastructures::Node<T>* previous = head_;
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        previous->next = nullptr;
        tail_ = previous;

        // store return value, because we are going to delete this node
        T tmp = current->value;

        // update size
        --size_;

        // if we do not have nodes, update head pointer
        if (size_ == 0) {
            head_ = nullptr;
            tail_ = nullptr;
        }

        // delete last node
        delete current;

        // return value
        return tmp;
    }

    T back() const {
        if (head_ == nullptr) {
            throw std::out_of_range("head is null");
        }

        return tail_->value;
    }

    T front() const {
        if (head_ == nullptr) {
            throw std::out_of_range("head is null");
        }

        return head_->value;
    }

    void insert(unsigned int index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("index out of bounds");
        }

        // handle head_
        if (index == 0) {
            datastructures::Node<T>* newNode =
                new datastructures::Node<T>();
            newNode->value = value;
            newNode->next = head_;

            // handle the case where the list is empty
            if (head_ == nullptr) {
                tail_ = newNode;
            }

            // update head
            head_ = newNode;
            size_++;
            return;
        }

        // handle middle index
        datastructures::Node<T>* current = head_;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        datastructures::Node<T>* after = current->next;
        current->next = new datastructures::Node<T>();
        current->next->value = value;
        current->next->next = after;

        // handle last node
        if (after == nullptr) {
            tail_ = current->next;
        }

        size_++;
    }

    void push_front(const T& value) {
        if (head_ == nullptr) {
            head_ = new datastructures::Node<T>();
            if (!head_) {
                throw "out of memory";
            }
            head_->value = value;
            tail_ = head_;
            size_++;
            return;
        }

        datastructures::Node<T>* newNode = new datastructures::Node<T>();
        newNode->value = value;
        newNode->next = head_;
        head_ = newNode;
        size_++;
    }

    T pop_front() {
        if (head_ == nullptr) {
            throw std::out_of_range("head is null");
        }

        datastructures::Node<T> *tmp = head_;
        T tmpValue = head_->value;
        head_ = head_->next;
        --size_;
        if (head_ == nullptr) {
            tail_ == nullptr;
        }
        delete tmp;
        return tmpValue;
    }

    T& value_at(int index) {
        if (index >= size_) {
            throw "index out of bounds";
        }

        if (index == 0) {
            return head_->value;
        }

        datastructures::Node<T>* current = head_;
        for (int i = 0; i < index; i++) {
            if (current->next == nullptr) {
                throw "out of range";
            }

            current = current->next;
        }

        return current->value;
    }

    void erase(unsigned int index) {
        if (index > size_) {
            throw std::out_of_range("index out of bounds");
        }

        datastructures::Node<T>* current = head_;
        datastructures::Node<T>* previous = current;
        // handle TAIL
        if (index == size_) {
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
                if (current->next == nullptr) {
                    previous->next = nullptr;
                    size_--;
                    delete current;
                    tail_ = previous;
                    return;
                }
            }
        }

        // handle head_
        if (index == 0) {
            head_ = head_->next;
            delete current;
            size_--;
            return;
        }

        // handle middle nodes
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        size_--;
    }

    datastructures::Node<T>* head() const {
        return head_;
    }

    T getNthValueFromTail(int index) {
        if (index >= size_) {
            throw std::out_of_range("out of range");
        }

        size_t toIterate = size_ - index - 1;
        datastructures::Node<T>* ptr = head_;
        for (size_t i = 0; i < toIterate; i++) {
            ptr = ptr->next;
        }
        return ptr->value;
    }

    void reverse() {
        if (head_ == nullptr) {
            return;
        }

        datastructures::Node<T> *current = head_;
        datastructures::Node<T> *follower = head_;
        datastructures::Node<T> *tmp;

        // update tail
        tail_ = current;

        // start iterating
        current = current->next;
        while (current->next != nullptr) {
            // processingNode = current->value;
            tmp = current->next;
            current->next = follower;
            // currentNodeNextIsEqualTo = follower->value;
            follower = current;
            // followerIsNow = current->value;
            current = tmp;
            // currentIsNow = current->value;
        }
        current->next = follower;
        head_->next = nullptr;
        head_ = current;
    }

    void removeValue(const T &value) {
        if (head_ == nullptr) {
            return;
        }

        if (head_->value == value) {
            datastructures::Node<T> *tmp = head_->next;
            delete head_;
            head_ = tmp;

            // handle tail, because the list may now be empty
            if (head_ == nullptr) {
                tail_ = nullptr;
            }
            --size_;
            return;
        }

        datastructures::Node<T> *current = head_;
        datastructures::Node<T> *follower = head_;
        while (current->next != nullptr) {
            current = current->next;
            if (current->value == value) {
                follower->next = current->next;
                if (current->next == nullptr) {
                    tail_ = follower;
                }
                delete current;
                --size_;
                return;
            }
            follower = follower->next;
        }
    }

    int size() const {
        return size_;
    }

    bool empty() const {
        return head_ == nullptr;
    }
};
}
#endif
