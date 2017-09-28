#include "utils/strings/is-unique.h"

#include <iostream>

bool isUnique(std::string &str)
{
    std::string::iterator i = str.begin();

    while (i != str.end()) {
        int j = i - str.begin();
        while(j != str.length()) {
            j++; // do not compare the same char with itself
            if (str[j] == *i) {
                return false;
            }
        }
        i++;
    }
    return true;
}

bool isUnique(char *str, size_t strSize)
{
    int i = 0;
    while (i != strSize) {
        for (int j = i + 1; j < strSize; j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
        i++;
    }
    return true;
}

