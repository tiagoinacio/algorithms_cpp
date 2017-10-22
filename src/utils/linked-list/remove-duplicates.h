#ifndef UTILS_LINKED_LIST_REMOVE_DUPLICATES_H_INCLUDED
#define UTILS_LINKED_LIST_REMOVE_DUPLICATES_H_INCLUDED

#include "data-structures/linked-list.h"

namespace utils {

    namespace linkedList {

        template <typename T>
        void removeDuplicates(datastructures::LinkedList<T> &list) {
            for (size_t i = 0; i < list.size(); i++) {
                for (size_t j = i + 1; j < list.size(); j++) {
                    if (list.get(i) == list.get(j)) {
                        list.deleteElementAtPosition(j);
                        j = j - 1;
                    }
                }
            }
        }
    }
}

#endif