#include "utils/strings/is-unique.h"

#include <iostream>

bool isUnique(std::string &str)
{
    std::string::iterator i = str.begin();

    while (i != str.end()) {
        int j = i - str.begin();
        while(j != str.length()) {
            j++;
            std::cout << " i " << *i <<  " j " << str[j] << std::endl;
            if (str[j] == *i) {
                std::cout << "are equal: " << *i << " " << str[j] << std::endl;
                return false;
            }
        }
        i++;
    }
    return true;
}

