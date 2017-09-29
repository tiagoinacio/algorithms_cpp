#include "utils/strings/urlify.h"
#include <string>

std::string urlify(std::string &str) {
    std::string::reverse_iterator it = str.rbegin();
    std::string out = "";

    while (it != str.rend()) {
        if (*it == ' ') {
            if (out.size() == 0) {
                ++it;
                continue;
            }
            out = "%20" + out;
        } else {
            out = *it + out;
        }
        ++it;
    }

    return out;
}
