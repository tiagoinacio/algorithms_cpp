#include "utils/strings/is-palindrome.h"

bool isPalindrome(char* str, size_t size) {
    if (size < 1) {
        return false;
    }

    if (size == 1) {
        return true;
    }

    // create new string without whitespaces
    void * ptr = malloc(sizeof(char) * size);

    if (ptr == NULL) {
        throw "no memory available";
    }

    char * trimmedStr = (char *)ptr;
    size_t trimmedStrSize = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            continue;
        }
        trimmedStr[i] = str[i];
        trimmedStrSize++;
    }
    trimmedStr[trimmedStrSize + 1] = '\0';

    // iterate through only half of the chars, comparing both sides
    // a b c c b a
    // 1st iteration: a ... a
    // 2nd iteration: ... b ... b ...
    // 3th iteration: ... c c ...
    // if the size is even, we check all chars, if the size is odd, 
    // we have one middle char that can be unique and have only one occurence
    // e.g.: a b c b a -> 'c' only appears once
    int numberOfIterations = trimmedStrSize % 2 == 0 ? trimmedStrSize / 2 : (trimmedStrSize - 1) / 2;

    for (int i = 0; i < numberOfIterations; i++) {
        if (trimmedStr[i] != trimmedStr[size - i - 1]) {
            return false;
        }
    }

    // free string on the heap
    free(trimmedStr);

    return true;
}

bool isPalindrome(const std::string &str) {
    size_t size = str.size();

    if (size < 1) {
        return false;
    }

    if (size == 1) {
        return true;
    }

    std::string::const_iterator up = str.begin();
    std::string::const_reverse_iterator down = str.rbegin();
    int numberOfIterations = str.size() % 2 == 0 ? str.size() / 2 : (str.size() - 1) / 2;
    for (int i = 0; i < numberOfIterations; i++) {
        while (*up == ' ') {
            up++;
        }
        while (*down == ' ') {
            down++;
        }
        if (*up != *down) {
            return false;
        }
        up++;
        down++;
    }

    return true;
}