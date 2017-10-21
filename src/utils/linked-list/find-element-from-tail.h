#ifndef UTILS_LINKED_LIST_FIND_ELEMENT_FROM_TAIL_H_INCLUDED
#define UTILS_LINKED_LIST_FIND_ELEMENT_FROM_TAIL_H_INCLUDED

#include "data-structures/linked-list.h"

namespace utils {

    namespace linkedList {

        template <typename T>
        T findElementFromTail(datastructures::LinkedList<T> &list, unsigned int position) {
            if (position >= list.size()) {
                throw "out of range";
            }

            return list.get(list.size() - 1 - position);
        }

    }

}

#endif