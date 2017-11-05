#ifndef UTILS_LINKED_LIST_SUM_LISTS_H_INCLUDED
#define UTILS_LINKED_LIST_SUM_LISTS_H_INCLUDED

#include "data-structures/linked-list.h"
#include "gsl/gsl"

namespace utils {

    namespace linkedList {
        template <typename T>
        datastructures::LinkedList<T> sumLists(const datastructures::LinkedList<T> &first, const datastructures::LinkedList<T> &second) {

            while (first != nullptr) {
                firstSum = first->getValue() + firstSum;
                first = first->getNext();
            }

            while (second != nullptr) {
                secondSum = second->getValue() + secondSum;
                second = second->getNext();
            }

            return std::stoi(firstSum, std::string::size_type) + std::stoi(secondSum, std::string::size_type);
        }
    }
}

#endif