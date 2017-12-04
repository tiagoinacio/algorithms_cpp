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
        datastructures::LinkedList<T> partitionAroundValue(datastructures::Node<T> *head, T x) {
            datastructures::LinkedList<T> partitionedList;
            datastructures::Node<T> *current = head;

            if (current == nullptr) {
                throw "out_of_range";
            }

            while (current != nullptr) {
                T value = current->value;
                if (value < x) {
                    partitionedList.push_front(value);
                } else {
                    partitionedList.push_back(value);
                }

                current = current->next;
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
        datastructures::Node<T>* partition(datastructures::Node<T> *head, T x) {
            datastructures::Node<T> *current = head;
            datastructures::Node<T> *follower = head;
            datastructures::Node<T> *lessThanX = head;
            datastructures::Node<T> *greaterThanX = head;

            if (current == nullptr) {
                throw "out_of_range";
            }

            // skip first values less than X
            if (current->next != nullptr) {
                while (current->value < x) {
                    current = current->next;
                }
            }

            while (current != nullptr) {
                if (current->value < x) {
                    auto tmp = current;
                    // create new node to be push_back to the lessThan
                    auto newNode = new datastructures::Node<T>();
                    newNode->value = current->value;

                    // set less than pointer to the new node
                    newNode->next = lessThanX->next;
                    lessThanX->next = newNode;
                    if (newNode->next != nullptr) {
                        lessThanX = newNode;
                    }

                    // if we are not processing the last node,
                    // delete the node
                    // else, set the follower next to nullptr
                    // to have the final node pointing to nullptr
                    if (current->next != nullptr) {
                        follower->next = current->next;
                        current = current->next;
                        delete tmp;
                    } else {
                        current = current->next;
                        follower->next = nullptr;
                    }

                    continue;
                }

                current = current->next;
                follower = follower->next;
            }

            return head;
        }
    }
}

#endif
