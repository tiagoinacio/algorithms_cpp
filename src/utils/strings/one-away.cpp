#include "utils/strings/one-away.h"

bool isOneAway(const std::string &first, const std::string &second) {
    std::string::const_iterator firstIterator = first.begin();
    std::string::const_iterator secondIterator = second.begin();
    int differences = 0;

    while (firstIterator != first.end()) {
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