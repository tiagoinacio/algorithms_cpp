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

            // if key already exists
            // replace it
            if (array_.get(i) != nullptr && array_.get(i)->key.compare(key) == 0) {
                break;
            }
        }
        array_.set(i, keyValuePair);
    }

    void remove(const std::string &key) {
        int probe = 1;
        size_t i = hashFn(key, square(probe));
        map<T> *keyValuePair = array_.get(i);

        if (keyValuePair == nullptr) {
            throw std::out_of_range("key not found");
        }

        while (keyValuePair->key.compare(key) != 0) {
            probe++;
            i = hashFn(key, square(probe));
            keyValuePair = array_.get(i);

            if (keyValuePair == nullptr) {
                throw std::out_of_range("key not found");
            }
        }

        keyValuePair->wasDeleted = true;
    }

    T get(const std::string &key) {
        map<T> *keyValuePair;
        int i = 1;
        while (true) {
            int index = hashFn(key, square(i));
            keyValuePair = array_.get(index);
            if (keyValuePair != nullptr) {
                if (keyValuePair->key.compare(key) == 0) {
                    break;
                }
            } else {
                throw std::out_of_range("key not found");
            }
            i++;
        }

        return keyValuePair->value;
    }

    bool exists(const std::string &key) {
        map<T> *keyValuePair;
        int i = 1;
        while (true) {
            int index = hashFn(key, square(i));
            keyValuePair = array_.get(index);
            if (keyValuePair != nullptr) {
                if (keyValuePair->key.compare(key) == 0 && keyValuePair->wasDeleted == false) {
                    return true;
                }
            } else {
                return false;
            }
            i++;
        }
    }

    int square(int i) const {
        return i * i;
    }

    int hashFn(const std::string &key, int probe) {
        int index = 0;

        for ( int i = 0; i < key.length(); i++ ) {
		    index += int(key[i]);
        }

        return (index + probe) % capacity_;
    }
};
}
#endif