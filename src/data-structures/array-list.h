#ifndef DATA_STRUCTURES_ARRAY_LIST_H_INCLUDED
#define DATA_STRUCTURES_ARRAY_LIST_H_INCLUDED

#include <memory>
#include <iostream>
#include <stdexcept>

namespace datastructures {

template <typename T>
class ArrayList {
 private:
  T *array_;
  int size_;
  int capacity_;

 public:
  ArrayList<T>()
    :
    array_(new T[1]),
    size_(0),
    capacity_(1)
    {}

  ~ArrayList<T>() {
    delete[] array_;
    size_ = 0;
    capacity_ = 0;
  }

  // copy constructor
  explicit ArrayList<T>(const ArrayList<T> &obj) {
    size_ = obj.size_;
    capacity_ = obj.capacity_;
    array_ = new T[capacity_];
    *array_ = *(obj.array_);
  }

  // assignment operator
  ArrayList<T>& operator=(const ArrayList<T> &rhs) {
    if (this != &rhs) {
      *this->array_ = *(rhs.array_);
      this->size_ = rhs.size_;
      this->capacity_ = rhs.capacity_;
    }
    return *this;
  }

  void push_back(const T &value) {
    if (size_ == capacity_) {
      // allocate new array with double capacity
      capacity_ = capacity_ * 2;
      T *newArray = new T[capacity_];

      // copy elements to new allocated array
      for (int i = 0; i < capacity_; i++) {
        newArray[i] = array_[i];
      }

      // delete old array
      delete[] array_;

      // update array pointer
      array_ = newArray;
    }
    array_[size_] = value;
    size_++;
  }

  void set(int index, const T &value) {
    if (index < 0 || index > size_) {
      throw std::out_of_range("Index out of bounds");
    }
    array_[index] = value;
  }

  void insert(int index, const T &value) {
    if (index < 0 || index > size_ + 1 || index + 1 > capacity_) {
      throw std::out_of_range("Index out of bounds");
    }
    // shift elements to the right
    for (int i = size_; i > index; i--) {
      array_[i] = array_[i - 1];
    }
    // insert element at position index
    array_[index] = value;
    size_ = size_ + 1;
  }

  T get(int index) {
    if (index < 0 || index > size_) {
      throw std::out_of_range("Index out of bounds");
    }
    return array_[index];
  }

  void remove(int index) {
    if (index < 0 || index > size_) {
      throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size_ - 1; i++) {
      array_[i] = array_[i + 1];
    }
    size_ = size_ - 1;
  }

  void removeByValue(const T &value) {
    for (int i = 0; i < size_; i++) {
      if (array_[i] == value) {
        remove(i);
        // prevent from skipping the next element
        // because it was shifted to the current index
        i = i - 1;
      }
    }
  }

  int find(const T &value) {
    for (int i = 0; i < size_; i++) {
      if (array_[i] == value) {
        return i;
      }
    }
    return -1;
  }

  bool isEmpty() {
    return size_ == 0;
  }

  int size() {
    return size_;
  }

  int capacity() {
    return capacity_;
  }
};
}
#endif
