#ifndef UTILS_SEARCH_BINARY_SEARCH_H_INCLUDED
#define UTILS_SEARCH_BINARY_SEARCH_H_INCLUDED

#include <math.h>
#include "gsl/gsl"

namespace utils {

    namespace search {

        template <typename T>
        T binarySearch(T* array, T key, size_t min, size_t max)
        {
            int midPoint = floor((max - min) / 2) + min;

            if (max < min) {
                throw std::out_of_range("key not found");
            }

            if (array[midPoint] == key) {
                return midPoint;
            }

            if (array[midPoint] < key) {
                return binarySearch(array, key, midPoint + 1, max);
            }

            if (array[midPoint] > key) {
                return binarySearch(array, key, min, midPoint - 1);
            }

            throw std::out_of_range("key not found");
        }
    }
}

#endif