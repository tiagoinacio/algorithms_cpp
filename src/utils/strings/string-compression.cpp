#include "utils/strings/string-compression.h"

// assumming only a-z and A-Z letters
std::string stringCompression(const std::string &uncompressedString) {
    std::string compressedString = "";
    std::string::const_iterator it = uncompressedString.begin();

    while (it != uncompressedString.end()) {
        if ((*it) == *(it + 1)) {
            unsigned int count = 1;
            while ((*it) == *(it + 1)) {
                count++;
                it++;
            }
            compressedString = compressedString + *(it - 1) + std::to_string(count);
            it++;
            continue;
        }

        compressedString = compressedString + (*it);
        it++;
    }

    if (uncompressedString.size() <= compressedString.size()) {
        return uncompressedString;
    }

    return compressedString;
}