#ifndef DATA_STRUCTURES_LINKED_LIST_H_INCLUDED
#define DATA_STRUCTURES_LINKED_LIST_H_INCLUDED

#include <memory>
#include <iostream>
#include <gsl/gsl>

namespace datastructures {

template <typename T>
class Node {
 private:
  T value;
  gsl::owner<Node*> next;

 public:
  Node() :
    value(),
    next(nullptr)
    {}
  
  ~Node() {
    std::cout << "calling ~Node with value " << value << std::endl;
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

  void setNext(gsl::owner<Node*> next_) {
    // TODO: doest this delete the next pointer, before replacing it?
    delete next;
    next = next_;
  }
};

template <typename T>
class LinkedList {
 private:
  // TODO: convert to gsl owner
  gsl::owner<datastructures::Node<T> *> head;
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
    auto n = head;
    while (n->getNext() != nullptr) {
      auto current = n;
      n = n->getNext();
      delete current;
    }
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
    // handle TAIL
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

    gsl::owner<datastructures::Node<T> *> newNode = new datastructures::Node<T>(value);
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
      head = current->getNext();
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

  int size() {
    return listSize;
  }
};
}
#endif
