#ifndef UTILS_LINKED_LIST_DELETE_MIDDLE_NODE_H_INCLUDED
#define UTILS_LINKED_LIST_DELETE_MIDDLE_NODE_H_INCLUDED

#include "data-structures/linked-list.h"

namespace utils {

    namespace linkedList {

        /*
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
                list.deleteElementAtPosition(0);
                return list;
            }

            datastructures::Node<T> *current = list.getHead();
            datastructures::Node<T> *follower = list.getHead();

            size_t listSize = 1;
            while (current->getNext() != nullptr) {
                current = current->getNext();

                ++listSize;

                if (listSize % 2 == 0) {
                    follower = follower->getNext();
                }
            }

            if (listSize % 2 == 0) {
                list.deleteElementAtPosition((listSize - 1) / 2);
                list.deleteElementAtPosition((listSize - 1) / 2);
            } else {
                list.deleteElementAtPosition(listSize / 2);
            }

            return list;
        }
    }
}

#endif