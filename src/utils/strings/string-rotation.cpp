#include "utils/strings/string-rotation.h"
#include <string>
#include <algorithm>

bool isStringRotation(const std::string &s1, const std::string &s2) {
    std::string s1Sorted = s1;
    std::string s2Sorted = s2;

    // sort is made in place
    // we could also remove the const keyword and pass both strings as copy to this function
    std::sort(s1Sorted.begin(), s1Sorted.end());
    std::sort(s2Sorted.begin(), s2Sorted.end());

    if (s1Sorted.find(s2Sorted) != std::string::npos) {
        return true;
    }
    return false;
}

bool stringRotation(std::string s1, std::string s2) {
    // sort is made in place
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    if (s1.find(s2) != std::string::npos) {
        return true;
    }
    return false;
}