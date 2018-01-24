#ifndef UTILS_LINKED_LIST_DELETE_MIDDLE_NODE_H_INCLUDED
#define UTILS_LINKED_LIST_DELETE_MIDDLE_NODE_H_INCLUDED

#include "data-structures/linked-list/linked-list.h"
#include "gsl/gsl"

namespace utils {

    namespace linkedList {

        /*
         * Current and follower technique
         * Two pointers, one always ahead of the other by twice the distance
         *
         *      | 0 | 1 | 2 | 3 | 4 | 5 | NULL |
         *
         * curr   ^
         * foll   ^
         *
         * curr       ^
         * foll   ^
         *
         * curr           ^
         * foll       ^
         *
         * curr               ^
         * foll       ^
         *
         * curr                   ^
         * foll           ^
         *
         * curr                       ^
         * foll           ^
         *
         * curr                            ^
         * foll           ^
         *
         */
        template <typename T>
        datastructures::LinkedList<T>& deleteMiddleNode(datastructures::LinkedList<T> &list) {
            if (list.size() < 1) {
                return list;
            }

            if (list.size() == 1) {
                list.erase(0);
                return list;
            }

            datastructures::Node<T> *current = list.head();
            datastructures::Node<T> *follower = list.head();

            size_t listSize = 1;
            while (current->next != nullptr) {
                current = current->next;

                if (listSize % 2 == 0) {
                    follower = follower->next;
                }

                ++listSize;
            }

            if (listSize % 2 == 0) {
                list.erase((listSize - 1) / 2);
                list.erase((listSize - 1) / 2);
            } else {
                list.erase(listSize / 2);
            }

            return list;
        }

        /*
         * Delete Middle Node:
         * Implement an algorithm to delete a node in the middle
         * (i.e., any node but the  rst and last node, not necessarily the exact middle)
         * of a singly linked list, given only access to that node.
         */
        template <typename T>
        void deleteNode(gsl::not_null<datastructures::Node<T> *> ptrNode) {
            auto next = ptrNode->next;

            if (next == nullptr) {
                throw "throw out of range";
            }

            ptrNode->value = next->value;
            ptrNode->next = next->next;
        }
    }
}

#endif
