#ifndef DATA_STRUCTURES_HASH_TABLE_OPEN_ADDRESSING_H_INCLUDED
#define DATA_STRUCTURES_HASH_TABLE_OPEN_ADDRESSING_H_INCLUDED

#include <memory>
#include <string>
#include <iostream>
#include "../array-list.h"

namespace datastructures {

template <typename E>
struct map {
    std::string key;
    E value;
    bool wasDeleted;
};

template <typename T>
class HashTable {
 private:
    size_t capacity_;
    datastructures::ArrayList<map<T> *> array_;

 public:
    HashTable<T>(size_t capacity = 127)
        :
        capacity_(capacity),
        array_(datastructures::ArrayList<map<T> *>(capacity, capacity))
        {}

    ~HashTable<T>() {
        for (size_t i = 0; i < capacity_; i++) {
            if (array_.get(i) != nullptr) {
                delete array_.get(i);
            }
        }
    }

    void set(const std::string &key, const T &value) {
        map<T> *keyValuePair = new map<T>();
        keyValuePair->key = key;
        keyValuePair->value = value;
        keyValuePair->wasDeleted = false;

        int probe = 1;
        size_t i = hashFn(key, square(probe));
        while (array_.get(i) != nullptr && array_.get(i)->wasDeleted == false) {
            probe++;
            i = hashFn(key, square(probe));
        }
        array_.set(i, keyValuePair);
    }

    T get(const std::string &key) {
        map<T> *keyValuePair;
        int i = 1;
        while (true) {
            int index = hashFn(key, square(i));
            keyValuePair = array_.get(index);
            if (keyValuePair != nullptr) {
                if (keyValuePair->key == key) {
                    break;
                }
            } else {
                throw std::out_of_range("key not found");
            }
            i++;
        }

        return keyValuePair->value;
    }

    int square(int i) const {
        return i * i;
    }

    int hashFn(const std::string &key, int probe) {
        int index = 0;

        for ( int i = 0; i < key.length(); i++ ) {
		    index += int(key[i]);
        }

        return (index + probe) % 127;
    }

    // TODO: delete function
    // set for wasDeleted flag
};
}
#endif