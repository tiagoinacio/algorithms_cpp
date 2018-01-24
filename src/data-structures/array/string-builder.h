#ifndef DATA_STRUCTURES_STRING_BUILDER_H_INCLUDED
#define DATA_STRUCTURES_STRING_BUILDER_H_INCLUDED

#include <memory>
#include <string>
#include <iostream>

namespace datastructures {

class StringBuilder {
 private:
    // TODO: convert to gsl owner
    std::unique_ptr<char[]> str_;
    std::unique_ptr<char[]> trimmedStr_;
    size_t arraySize_;
    size_t count_;

 public:
    StringBuilder ()
    :
    str_(new char[16]()),
    arraySize_(16),
    count_(0)
    {}

    ~StringBuilder() {
        str_.reset();
    }

    void push_back(const char *str) {
        auto strLength = strlen(str);

        if (count_ + strLength >= arraySize_) {
            arraySize_ = (count_ + strLength + 1) * 2;
            auto newArray = std::make_unique<char[]>(arraySize_);
            auto ptr = newArray.get();
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
        // count_ + 1 to have space for the null char
        trimmedStr_ = std::make_unique<char[]>(count_ + 1);
        auto ptr = trimmedStr_.get();

        for (int i = 0; i < count_; i++) {
            ptr[i] = str_.get()[i];
        }

        ptr[count_] = '\0';

        return ptr;
    }
};
}
#endif
