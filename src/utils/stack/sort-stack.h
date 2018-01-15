#ifndef UTILS_STACK_SORT_STACK_H_INCLUDED
#define UTILS_STACK_SORT_STACK_H_INCLUDED

#include "data-structures/stack-array.h"
#include "gsl/gsl"

namespace utils {

    namespace stack {

        /*
         * Sort Stack:
         * Write a program to sort a stack such that the smallest items are on the top.
         * You can use an additional temporary stack,
         * but you may not copy the elements into any other data structure (such as an array).
         * The stack supports the following operations: push, pop, peek, and isEmpty.
         * To ask:
         *
         *  - can we use some constant number of variables, besides one stack?
         *  - what elements will be on the stack?
         *  - how can we compare elements?
         *  - how should we sort the stack? ascending/descending
        */
        template <typename T>
        datastructures::StackArray<T>& sort(datastructures::StackArray<T> &stack) {
            if (stack.isEmpty()) {
                return stack;
            }

            datastructures::StackArray<T> secondStack;
            while (!stack.isEmpty()) {
                T value = stack.pop();
                while (!secondStack.isEmpty() && value > secondStack.peek()) {
                    stack.push_back(secondStack.pop());
                }
                secondStack.push_back(value);
            }

            return stack;
        }
    }
}

#endif
