#ifndef UTILS_LINKED_LIST_PARTITION_H_INCLUDED
#define UTILS_LINKED_LIST_PARTITION_H_INCLUDED

#include "data-structures/linked-list.h"

namespace utils {

    namespace linkedList {

        /*
        all nodes less than X
        come before all nodes greater or equal to x
        */
        template <typename T>
        void partition(datastructures::LinkedList<T> &list, unsigned int position) {
            if (position > list.size()) {
                throw "out of range";
            }
            if (position == 0) {
                return;
            }

        }

    }

}

#endif