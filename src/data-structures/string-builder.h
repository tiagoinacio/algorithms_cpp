#ifndef DATA_STRUCTURES_STRING_BUILDER_H_INCLUDED
#define DATA_STRUCTURES_STRING_BUILDER_H_INCLUDED

#include <memory>
#include <string>
#include <iostream>

namespace datastructures {

class StringBuilder {
 private:
    std::unique_ptr<char[]> str_;
    size_t count_;
    size_t arraySize_;

 public:
    StringBuilder ()
    :
    str_(new char[16]),
    arraySize_(16),
    count_(0)
    {}

    void append(const char *str) {
        size_t strLength = strlen(str);

        if (count_ + strLength >= arraySize_) {
            arraySize_ = (count_ + strLength + 1) * 2;
            std::unique_ptr<char[]> newArray(new char[arraySize_]);
            char *ptr = newArray.get();
            for (int i = 0; i < count_; i++) {
                ptr[i] = str_.get()[i];
            }

            for (int i = 0; i < strLength; i++) {
                ptr[count_ + i] = str[i];
            }
            count_ += strLength;
            str_ = std::move(newArray);
        } else {
            for (int i = 0; i < strLength; i++) {
                str_.get()[count_ + i] = str[i];
            }
            count_ += strLength;
        }
    };

    char* toString() {
        return str_.get();
    }
};
}
#endif
