#ifndef UTILS_QUEUE_ANIMAL_SHELTER_H_INCLUDED
#define UTILS_QUEUE_ANIMAL_SHELTER_H_INCLUDED

#include "data-structures/linked-list/singly-linked-list-with-tail.h"
#include <string>
#include <typeinfo>
#include "gsl/gsl"

namespace utils {

    namespace queue {

        /*
         * An animal shelter, which holds only dogs and cats, operates on a strictly first in, first out basis.
         * People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
         * or they can select whether they would prefer a dog or a cat
         * (and will receive the oldest animal of that type).
         * They cannot select which speci c animal they would like.
         * Create the data structures to maintain this system and implement operations such as:
         * enqueue, dequeueAny, dequeueDog, and dequeueCat.
         * You may use the built-in Linked list data structure.
        */
        class Animal {
            public:
                std::string name;
                int order;
        };

        class Dog: public Animal {};
        class Cat: public Animal {};

        class AnimalShelter {
            datastructures::LinkedList<Animal> cats_;
            datastructures::LinkedList<Animal> dogs_;

            public:

            AnimalShelter() :
                cats_(datastructures::LinkedList<Animal>()),
                dogs_(datastructures::LinkedList<Animal>())
                {}

            void enqueue(const Animal& animal) {
                if (typeid(animal) == typeid(Cat)) {
                    cats_.push_back(animal);
                    return;
                }

                if (typeid(animal) == typeid(Dog)) {
                    dogs_.push_back(animal);
                    return;
                }
                return;
                //throw "unsuported animal provided";
            }

            Animal dequeueCat() {
                if (cats_.empty()) {
                    throw std::out_of_range("there are no cats in the queue");
                }

                return cats_.pop_front();
            }

            Animal dequeueDog() {
                if (dogs_.empty()) {
                    throw std::out_of_range("there are no dogs in the queue");
                }

                return dogs_.pop_front();
            }
        };
    }
}

#endif