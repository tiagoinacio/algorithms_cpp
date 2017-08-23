#include "sorting/bublesort.h"

/**
 * @brief bublesort
 *
 * sorts a vector of doubles using two nested for loops
 * even if the vector is already sorted, it will always loop for all elements
 * big O(n^2)
 *
 * @param vec reference to an unsorted vector of doubles
 */
void bublesort(std::vector<double> &vec)
{
    int vecSize = vec.size();

    for (int i = 0; i < vecSize; i++) {
        for (int j = i + 1; j < vecSize; j++) {
            if (vec[j] < vec[i]) {
                double tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}

/**
 * @brief bublesort
 *
 * sorts an of doubles using two nested for loops
 * even if the array is already sorted, it will always loop for all elements
 * big O(n^2)
 *
 * @param arr reference to an array of doubles
 * @param size of the array
 */
void bublesort(double arr[], int size)
{
    if (size < 1) return;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                double tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

/**
 * @brief bublesort_improved
 *
 * sorts a vector of doubles using two nested for loops
 * even if the vector is already sorted, it will always loop for all elements
 * big O(n^2)
 *
 * @param vec reference to an unsorted vector of doubles
 */
void bublesort_improved(std::vector<double> &vec)
{
    bool swapped;
    int vecSize = vec.size();

    do {
        swapped = false;

        for (int index = 0; index < vecSize - 1; index++) {

            if (vec[index] > vec[index + 1]) {
                double tmp = vec[index];

                vec[index] = vec[index + 1];
                vec[index + 1] = tmp;
                swapped = true;
            }
        }

    } while (swapped == true);
}

/**
 * @brief bublesort_improved
 *
 * sorts an of doubles using two nested for loops
 * if the array is already sorted, it will stop the iterations
 * big O(n^2)
 *
 * @param arr reference to an array of doubles
 * @param size of the array
 */
void bublesort_improved(double arr[], int size)
{
    bool swapped;

    do {
        swapped = false;

        for (int index = 0; index < size - 1; index++) {

            if (arr[index] > arr[index + 1]) {
                int tmp = arr[index];

                arr[index] = arr[index + 1];
                arr[index + 1] = tmp;
                swapped = true;
            }
        }

    } while (swapped == true);
}
