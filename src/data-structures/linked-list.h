#ifndef DATA_STRUCTURES_LINKED_LIST_H_INCLUDED
#define DATA_STRUCTURES_LINKED_LIST_H_INCLUDED

#include <gsl/gsl>
#include <iostream>
#include <memory>
#include <utility>

namespace datastructures {

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class LinkedList {
 private:
    // TODO: convert to gsl owner
    datastructures::Node<T>* head;
    int listSize;

 public:
    LinkedList() : head(nullptr), listSize(0) {
    }

    ~LinkedList() {
        if (head != nullptr) {
            reset();
        }
    }

    LinkedList<T>(const LinkedList<T>& other) {
        datastructures::Node<T>* current = other.getHead();
        datastructures::Node<T>* newNode = new datastructures::Node<T>();
        head = newNode;

        listSize = other.size();

        while (current != nullptr) {
            newNode->value = current->value;
            newNode->next = new datastructures::Node<T>();
            newNode = newNode->next;
            current = current->next;
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
        while (head->next != nullptr) {
            datastructures::Node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
        delete head;
        head = nullptr;
        listSize = 0;
    }

    // TODO: insert element at specified position
    void append(const T& value) {
        if (head == nullptr) {
            head = new datastructures::Node<T>();
            head->value = value;
            listSize++;
            return;
        }

        datastructures::Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new datastructures::Node<T>();
        current->next->value = value;
        listSize++;
    }

    void insertAtPosition(unsigned int position, const T& value) {
        if (position > listSize) {
            throw "index out of bounds";
        }

        // handle HEAD
        if (position == 0) {
            datastructures::Node<T>* newNode =
                new datastructures::Node<T>();
            newNode->value = value;
            newNode->next = head;
            head = newNode;
            listSize++;
            return;
        }

        // handle middle position
        datastructures::Node<T>* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        datastructures::Node<T>* after = current->next;
        current->next = new datastructures::Node<T>();
        current->next->value = value;
        current->next->next = after;
        listSize++;
    }

    void preppend(const T& value) {
        if (head == nullptr) {
            head = new datastructures::Node<T>();
            if (!head) {
                throw "";
            }
            head->value = value;
            listSize++;
            return;
        }

        datastructures::Node<T>* newNode = new datastructures::Node<T>();
        if (!newNode) {
            throw "";
        }
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        listSize++;
    }

    T& get(int index) {
        if (index >= listSize) {
            throw "index out of bounds";
        }

        if (index == 0) {
            return head->value;
        }

        datastructures::Node<T>* current = head;
        for (int i = 0; i < index; i++) {
            if (current->next == nullptr) {
                throw "out of range";
            }

            current = current->next;
        }

        return current->value;
    }

    void deleteElementAtPosition(unsigned int index) {
        if (index > listSize) {
            throw "index out of bounds";
        }

        datastructures::Node<T>* current = head;
        datastructures::Node<T>* previous = current;
        // handle TAIL
        if (index == listSize) {
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
                if (current->next == nullptr) {
                    previous->next = nullptr;
                    listSize--;
                    return;
                }
            }
        }

        // handle HEAD
        if (index == 0) {
            head = head->next;
            delete current;
            listSize--;
            return;
        }

        // handle middle nodes
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
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
            ptr = ptr->next;
        }
        return ptr->value;
    }

    int size() const {
        return listSize;
    }
};
}
#endif
