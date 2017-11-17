#ifndef DATA_STRUCTURES_LINKED_LIST_H_INCLUDED
#define DATA_STRUCTURES_LINKED_LIST_H_INCLUDED

#include <memory>
#include <iostream>
#include <gsl/gsl>
#include <utility>

namespace datastructures {

template <typename T>
class Node {
 private:
  T value;
  Node* next;

 public:
  Node() :
    value(),
    next(nullptr)
    {}

  ~Node() {}

  Node<T>(const Node<T> &other) {
    value = other.value;
    next = other.next;
  }

  // assignment operator
  Node<T>& operator=(const Node<T>& rhs) {
    if (this != &rhs) {
      this->value = rhs.value;
      this->next = rhs.next;
    }
    return *this;
  }

  explicit Node(const T &value_) :
    value(value_),
    next(nullptr)
    {}

  void setValue(const T &value_) {
    value = value_;
  }

  T& getValue() {
    return value;
  }

  Node* getNext() {
    return next;
  }

  void setNext(Node* next_) {
    next = next_;
  }
};

template <typename T>
class LinkedList {
 private:
  // TODO: convert to gsl owner
  datastructures::Node<T> *head;
  int listSize;

 public:
  LinkedList() :
    head(nullptr),
    listSize(0)
    {}

    ~LinkedList() {
      if (head != nullptr) {
        reset();
      }
    }

    LinkedList<T>(const LinkedList<T> &other) {
      datastructures::Node<T> *current = other.getHead();
      datastructures::Node<T> *newNode = new datastructures::Node<T>();
      head = newNode;

      listSize = other.size();

      while (current != nullptr) {
        newNode->setValue(current->getValue());
        newNode->setNext(new datastructures::Node<T>());
        newNode = newNode->getNext();
        current = current->getNext();
      }
    }

  // assignment operator
  LinkedList<T>& operator=(const LinkedList<T>& rhs) {
    if (this != &rhs) {
      auto tmp(rhs);
      std::swap(head, tmp.head);
      std::swap(listSize, tmp.listSize);
    }
    return *this;
  }

  void reset() {
    while (head->getNext() != nullptr) {
      datastructures::Node<T> *tmp = head;
      head = head->getNext();
      delete tmp;
    }
    delete head;
    head = nullptr;
    listSize = 0;
  }

  // TODO: insert element at specified position
  void append(const T &value) {
    if (head == nullptr) {
      head = new datastructures::Node<T>(value);
      listSize++;
      return;
    }

    datastructures::Node<T>* current = head;
    while (current->getNext() != nullptr) {
      current = current->getNext();
    }
    current->setNext(new datastructures::Node<T>(value));
    listSize++;
  }

  void insertAtPosition(unsigned int position, const T &value) {
    if (position > listSize) {
      throw "index out of bounds";
    }

    // handle HEAD
    if (position == 0) {
      datastructures::Node<T> *newNode = new datastructures::Node<T>(value);
      newNode->setNext(head);
      head = newNode;
      listSize++;
      return;
    }

    // handle middle position
    datastructures::Node<T>* current = head;
    for (int i = 0; i < position - 1; i++) {
      current = current->getNext();
    }
    datastructures::Node<T>* after = current->getNext();
    current->setNext(new datastructures::Node<T>(value));
    current->getNext()->setNext(after);
    listSize++;
  }

  void preppend(const T &value) {
    if (head == nullptr) {
      head = new datastructures::Node<T>(value);
      listSize++;
      return;
    }

    datastructures::Node<T> *newNode = new datastructures::Node<T>(value);
    newNode->setNext(head);
    head = newNode;
    listSize++;
  }

  T& get(int index) {
    if (index >= listSize) {
      throw "index out of bounds";
    }

    if (index == 0) {
      return head->getValue();
    }

    datastructures::Node<T>* current = head;
    for (int i = 0; i < index; i++) {
      if (current->getNext() == nullptr) {
        throw "out of range";
      }

      current = current->getNext();
    }

    return current->getValue();
  }

  void deleteElementAtPosition(unsigned int index) {
    if (index > listSize) {
      throw "index out of bounds";
    }

    datastructures::Node<T>* current = head;
    datastructures::Node<T>* previous = current;
    // handle TAIL
    if (index == listSize) {
      while (current->getNext() != nullptr) {
        previous = current;
        current = current->getNext();
        if (current->getNext() == nullptr) {
          previous->setNext(nullptr);
          listSize--;
          return;
        }
      }
    }

    // handle HEAD
    if (index == 0) {
      head = head->getNext();
      delete current;
      listSize--;
      return;
    }

    // handle middle nodes
    for (int i = 0; i < index - 1; i++) {
      current = current->getNext();
    }
    current->setNext(current->getNext()->getNext());
    listSize--;
  }

  datastructures::Node<T>* getHead() const {
    return head;
  }

  T findElementFromTail(unsigned int position) {
    if (position >= listSize) {
      throw "out of range";
    }

    size_t toIterate = listSize - position - 1;
    datastructures::Node<T>* ptr = head;
    for (size_t i = 0; i < toIterate; i++) {
      ptr = ptr->getNext();
    }
    return ptr->getValue();
  }

  int size() const {
    return listSize;
  }
};
}
#endif
