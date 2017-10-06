#include "utils/strings/one-away.h"
#include <string> // std::string, std::string::const_iterator

bool isOneAway(const std::string &first, const std::string &second) {
    std::string::const_iterator firstIterator = first.begin();
    std::string::const_iterator secondIterator = second.begin();
    int differences = 0;

    int sizeDifference = first.size() - second.size();
    if (sizeDifference > 1 || sizeDifference < -1) {
        return false;
    }

    while (firstIterator != first.end()) {
        if (secondIterator == second.end()) {
            // if end of second string, 
            // we must increment at least one time the differences, 
            // because we are still evaluating chars from the first string
            differences++;
            firstIterator++;

            if (differences > 1) {
                return false;
            }
            continue;
        }
        if (*firstIterator != *secondIterator) {
            differences++;
            if (*(firstIterator + 1) == *secondIterator) {
                firstIterator++;
            } else if (*firstIterator == *(secondIterator + 1)) {
                secondIterator++;
            }
        }

        if (differences > 1) {
            return false;
        }
        firstIterator++;
        secondIterator++;
    }

    return true;
}