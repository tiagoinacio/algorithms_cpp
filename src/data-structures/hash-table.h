#ifndef DATA_STRUCTURES_HASH_TABLE_H_INCLUDED
#define DATA_STRUCTURES_HASH_TABLE_H_INCLUDED

#include <memory>
#include <string>
#include <iostream>
#include "./linked-list.h"
#include "./array-list.h"

namespace datastructures {

template <typename T>
class HashTable {
 private:
    datastructures::ArrayList<std::unique_ptr<datastructures::LinkedList<T> > > array_;

 public:
    HashTable<T>()
    {}

    void set(const std::string &key, const T &value) {
        int index = hashFn(key);
        std::unique_ptr<datastructures::LinkedList<T> > linkedList(new datastructures::LinkedList<T>);
        linkedList.add(value);
        array_.set(index, linkedList);
    }

    T get(const std::string &key) {
        int index = hashFn(key);
        return array_[index].get(index);
    }

    int hashFn(const std::string &key) {
        return 0;
    }
};
}
#endif
