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

        /*
         * Partition:
         * Write code to partition a linked list around a value x,
         * such that all nodes less than x come before all nodes greater than or equal to x.
         * If x is contained within the list, the values of x only need to be after the elements less than x.
         * The partition element x can appear anywhere in the "right partition";
         * it does not need to appear between the left and right partitions
         *
         *
         * with X = 5
         * List
         *
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         *
         * curr         .
         * lessThanX    .
         * biggerThanX  .
         *
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         * curr              .
         * lessThanX    .
         * biggerThanX       .
         *
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         * curr                   .
         * lessThanX    .
         * biggerThanX            .
         *
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         * curr                        .
         * lessThanX    .
         * biggerThanX                 .
         *
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         * curr                              .
         * lessThanX    .
         * biggerThanX                       .
         *
         *
         *              3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         *              3 -> 2 -> 5 -> 8 -> 5 -> 10 -> 1 -> NULL
         * curr                                   .
         * lessThanX                              .
         * biggerThanX                       .
         *
         * input        3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 -> NULL
         * output       3 -> 2 -> 1 -> 5 -> 8 -> 5 -> 10 -> NULL
         * curr                                        .
         * lessThanX                                   .
         * biggerThanX                       .
         *
         */
        template <typename T>
        datastructures::LinkedList<T> partition(datastructures::LinkedList<T> &list, T x) {
            datastructures::Node<T> *current = list.getHead();
            datastructures::Node<T> *follower = list.getHead();
            datastructures::Node<T> *lessThanX = list.getHead();
            datastructures::Node<T> *greaterThanX = list.getHead();

            if (current == nullptr) {
                throw "out_of_range";
            }

            // skip first values less than X
            if (current->getNext() != nullptr) {
                while (current->getValue() < x) {
                    current = current->getNext();
                }
            }

            while (current != nullptr) {
                if (current->getValue() < x) {
                    auto tmp = current;
                    auto newNode = new datastructures::Node<T>(tmp->getValue());

                    if (current->getNext() != nullptr) {
                        current->setValue(current->getNext()->getValue());
                        current->setNext(current->getNext());
                        delete tmp;
                    } else {
                        follower->setNext(nullptr);
                    }

                    newNode->setNext(lessThanX->getNext());
                    lessThanX->setNext(newNode);
                    if (newNode->getNext() != nullptr) {
                        lessThanX = newNode;
                    }

                    current = current->getNext();
                    continue;
                }

                current = current->getNext();
                follower = follower->getNext();
            }

            return list;
        }
    }
}

#endif