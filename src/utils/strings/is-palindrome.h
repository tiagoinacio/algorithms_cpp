#ifndef UTILS_STRINGS_IS_PALINDROME_H_INCLUDED
#define UTILS_STRINGS_IS_PALINDROME_H_INCLUDED

#include <stddef.h> // size_t
#include <stdlib.h> // malloc, free
#include <string> // std::string

bool isPalindrome(char *str, size_t strSize);
bool isPalindrome(const std::string &str);

#endif