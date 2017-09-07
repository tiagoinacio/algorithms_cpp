#ifndef DATA_STRUCTURES_LINKED_LIST_H_INCLUDED
#define DATA_STRUCTURES_LINKED_LIST_H_INCLUDED

#include <memory>
#include <iostream>

namespace datastructures {

template <typename T>
class Node {
 private:
  T value;
  std::unique_ptr<Node> next;

 public:
  Node() :
    value(),
    next(nullptr)
    {}

  explicit Node(T value_) :
    value(value_),
    next(nullptr)
    {}

  void setValue(T value_) {
    value = value_;
  }

  T getValue() {
    return value;
  }

  Node* getNext() {
    return next.get();
  }

  void setNext(Node* next_) {
    std::unique_ptr<Node> nextPtr(next_);
    next = std::move(nextPtr);
  }
};

template <typename T>
class LinkedList {
 private:
  std::unique_ptr<datastructures::Node<T> > head;
  int listSize;

 public:
  LinkedList() :
    head(nullptr),
    listSize(0)
    {}

  // assignment operator
  LinkedList<T>& operator=(const LinkedList<T>& rhs) {
    if (this != &rhs) {
      this->next = rhs.next;
      this->value = rhs.value;
    }
    return *this;
  }

  void clear() {
    head.reset(nullptr);
    listSize = 0;
  }

  void append(T value) {
    if (head.get() == nullptr) {
      std::unique_ptr<datastructures::Node<T> > newValue(new datastructures::Node<T>(value));
      head = std::move(newValue);
      listSize++;
      return;
    }

    datastructures::Node<T>* current = head.get();
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    datastructures::Node<T>* newNode = new datastructures::Node<T>(value);
    current->setNext(newNode);
    listSize++;
  }

  void preppend(T value) {
    if (head.get() == nullptr) {
      std::unique_ptr<datastructures::Node<T> > newValue(new datastructures::Node<T>(value));
      head = std::move(newValue);
      listSize++;
      return;
    }

    std::unique_ptr<datastructures::Node<T> > newNode(new datastructures::Node<T>(value));
    newNode->setNext(head.release());
    head = std::move(newNode);
    listSize++;
  }

  T get(int index) {
    if (index >= listSize) {
      throw "index out of bounds";
    }

    if (index == 0) {
      return head->getValue();
    }

    datastructures::Node<T>* current = head.get();
    for (int i = 0; i < index; i++) {
      current = current->getNext();
    }

    return current->getValue();
  }

  int size() {
    return listSize;
  }
};
}
#endif
