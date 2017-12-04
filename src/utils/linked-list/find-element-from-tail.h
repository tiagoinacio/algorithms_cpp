#ifndef UTILS_LINKED_LIST_FIND_ELEMENT_FROM_TAIL_H_INCLUDED
#define UTILS_LINKED_LIST_FIND_ELEMENT_FROM_TAIL_H_INCLUDED

#include "data-structures/linked-list.h"

namespace utils {

    namespace linkedList {

        /*
        *  assuming that size() is already calculated, we have Big O(1)
        *  if we need to iterate through all the list to know the size,
        *  then we would have to iterate backwards after that, to get the nth element from last
        *  which would give us 2 N cycles,
        *  resumming to 2n = Big O(n)
        */
        template <typename T>
        T getNthValueFromTail(datastructures::LinkedList<T> &list, unsigned int position) {
            if (position >= list.size()) {
                throw "out of range";
            }

            return list.value_at(list.size() - 1 - position);
        }

        /* for position = 2
        *             NODE -> NODE -> NODE -> NODE -> NULL
        *  current      >
        *  follower     >
        *             NODE -> NODE -> NODE -> NODE -> NULL
        *  current             >
        *  follower     >
        *             NODE -> NODE -> NODE -> NODE -> NULL
        *  current                     >
        *  follower     >
        *             NODE -> NODE -> NODE -> NODE -> NULL
        *  current                              >
        *  follower             >
        *             NODE -> NODE -> NODE -> NODE -> NULL
        *  current                                      >
        *  follower                    >
        *  algorithm Big O(n):
        *  start at HEAD
        *  avance current until position
        *  from this point on, avance current until end, but for every move, move the follower too.
        * when current reach the end, the follower will be at the desired position
        */
        template <typename T>
        T findNthElementFromTail(datastructures::LinkedList<T> &list, unsigned int position) {
            datastructures::Node<T> *current = list.head();
            datastructures::Node<T> *follower = list.head();

            for (size_t i = 0; i < position; ++i) {
                if (current->next == nullptr) {
                    throw "out of range";
                }
                current = current->next;
            }

            while (current->next != nullptr) {
                current = current->next;
                follower = follower->next;
            }

            return follower->value;
        }

    }

}

#endif
