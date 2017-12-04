#ifndef DATA_STRUCTURES_HASH_TABLE_H_INCLUDED
#define DATA_STRUCTURES_HASH_TABLE_H_INCLUDED

#include <memory>
#include <string>
#include <iostream>
#include "./linked-list.h"
#include "./array-list.h"

namespace datastructures {

template <typename E>
struct map {
    std::string key;
    E value;
};

template <typename T>
class HashTable {
 private:
    // [linkedList<map> *, linkedList<map> *]
    datastructures::ArrayList<datastructures::LinkedList<map<T> > *> array_;

 public:
    HashTable<T>()
    {
        for (int i = 0; i < 127; i++) {
            array_.add(new datastructures::LinkedList<map<T> >);
        }

    }

    void set(const std::string &key, const T &value) {
        int index = hashFn(key);
        datastructures::LinkedList<map<T> > *linkedList = array_.get(index);
        map<T> keyValue;
        keyValue.key = key;
        keyValue.value = value;
        linkedList->push_back(keyValue);
        array_.set(index, linkedList);
    }

    T get(const std::string &key) {
        int index = hashFn(key);
        datastructures::LinkedList<map<T> > *linkedList = array_.get(index);

        if (linkedList->size() > 0) {
            for (int i = 0; i < linkedList->size(); i++) {
                map<T> map_ = linkedList->get(i);
                if (map_.key == key) {
                    return map_.value;
                }
            }
        }
        throw "no key found on hash table";
    }

    int hashFn(const std::string &key) {
        int index = 0;

        for ( int i = 0; i < key.length(); i++ ) {
		    index += int(key[i]);
        }

        return index % 127;
    }
};
}
#endif
