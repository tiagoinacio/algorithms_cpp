#ifndef UTILS_LINKED_LIST_PARTITION_AROUND_VALUE_H_INCLUDED
#define UTILS_LINKED_LIST_PARTITION_AROUND_VALUE_H_INCLUDED

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
         *
         *
         *
         * List
         *
         * 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         * 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8 -> NULL
         *
         */
        template <typename T>
        datastructures::LinkedList<T> partitionAroundValue(const datastructures::LinkedList<T> &list, T x) {
            datastructures::LinkedList<T> partitionedList;
            datastructures::Node<T> *current = list.getHead();

            if (current == nullptr) {
                throw "out_of_range";
            }

            while (current != nullptr) {
                T value = current->getValue();
                if (value < x) {
                    partitionedList.preppend(value);
                } else {
                    partitionedList.append(value);
                }

                current = current->getNext();
            }

            return partitionedList;
        }
    }
}

#endif