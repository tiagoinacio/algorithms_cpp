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
    // std::unique_ptr<Node> nextPtr(next_);
    // TODO: doest this delete the next pointer, before replacing it?
    //std::cout << "before setNext " << next.get()->value << std::endl;
    next.reset(next_);
    std::cout << "after setNext " << next.get()->value << std::endl;
  }
};

template <typename T>
class LinkedList {
 private:
  // TODO: convert to gsl owner
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

  // TODO: insert element at specified position

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

  // TODO: delete element
  void deleteElement(int index) {
    if (index > listSize || index < 1) {
      throw "index out of bounds";
    }

    datastructures::Node<T>* current = head.get();
    // TODO: handle if is last node
    // TODO: handle if is HEAD
    for (int i = 0; i < index - 1; i++) {
      current = current->getNext();
    }
    current->setNext(current->getNext()->getNext());

    listSize--;
  }

  int size() {
    return listSize;
  }
};
}
#endif
