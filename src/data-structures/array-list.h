#ifndef DATA_STRUCTURES_ARRAY_LIST_H_INCLUDED
#define DATA_STRUCTURES_ARRAY_LIST_H_INCLUDED

#include <memory>
#include <iostream>

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
    clear();
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

  void add(const T &value) {
    if (size_ + 1 <= capacity_) {
      array_[size_] = value;
    } else {
      capacity_ = capacity_ * 2;
      T *newArray = new T[capacity_];
      for (int i = 0; i < capacity_; i++) {
        newArray[i] = array_[i];
      }
      delete[] array_;
      array_ = newArray;
    }
    size_++;
  }

  void set(int index, const T &value) {
    if (index <= capacity_) {
      array_[index] = value;
      size_ = size_ > index ? size_ : index;
    } else {
      capacity_ = index * 2;
      T *newArray = new T[capacity_];
      for (int i = 0; i < size_; i++) {
        newArray[i] = array_[i];
      }
      for (int i = size_; i < capacity_; i++) {
        newArray[i] = T();
      }
      newArray[index] = value;
      delete[] array_;
      array_ = newArray;
      size_ = index;
    }
  }

  T get(int index) {
    if (index > size_) {
      throw "Index out of bounds";
    }
    return array_[index];
  }

  void clear() {
    delete[] array_;
    size_ = 0;
    capacity_ = 0;
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
