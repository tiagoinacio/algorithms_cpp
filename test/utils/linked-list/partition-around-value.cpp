#ifndef UTILS_LINKED_LIST_DELETE_MIDDLE_NODE_H_INCLUDED
#define UTILS_LINKED_LIST_DELETE_MIDDLE_NODE_H_INCLUDED

#include "data-structures/linked-list.h"
#include "gsl/gsl"

namespace utils {

    namespace linkedList {
        /*
         * Partition:
         * Write code to partition a linked list around a value x,
         * such that all nodes less than x come before all nodes greater than or equal to x.
         * If x is contained within the list, the values of x only need to be after the elements less than x.
         * The partition element x can appear anywhere in the "right partition";
         * it does not need to appear between the left and right partitions
         */
        template <typename T>
        void partitionAroundValue(gsl::not_null<datastructures::LinkedList<T> *> list) {
        }
    }
}

#endif