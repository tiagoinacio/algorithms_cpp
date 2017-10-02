#include "utils/strings/palindrome-permutation.h"
#include <map>

bool isPalindromePermutation(char* str, size_t size) {
    std::map<char, unsigned int> chars;

    if (size == 0) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (str[i] == ' ') {
            continue;
        }
        if (chars.find(str[i]) != chars.end()) {
            chars[str[i]]++;
        } else {
            chars.insert(std::make_pair(str[i], 1));
        }
    }

    std::map<char, unsigned int>::const_iterator it = chars.begin();
    int numberOfMiddles = 0;

    /*
     *      middle 'c'
     *   a b | c c | d e
     * 
     *  only one middle is allowed to have one occurence
     * 
     *      middle 'd'
     *   a b c | d | c b a
     * 
     *      middle 'd'
     *   a p w f | d | f w p a
     * 
     * */
    while (it != chars.end()) {
        if (it->second == 1) {
            numberOfMiddles++;
            // we can only have one middle. e.g.: abcba, abccba.
            // ('c' is the middle and can only have one or two occurrences)
            if (numberOfMiddles > 1) {
                return false;
            }
            it++;
            continue;
        }
        if (it->second != 2) {
            return false;
        }
        it++;
    }
    return true;
}