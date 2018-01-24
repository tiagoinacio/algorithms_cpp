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
                size_t order;
                virtual char type() const {
                    return 'A';
                }
                virtual ~Animal() {}
        };

        class Dog: public Animal {
            public:
            virtual char type() const {
                return 'D';
            }
        };
        class Cat: public Animal {
            virtual char type() const {
                return 'C';
            }
        };

        class AnimalShelter {
            datastructures::LinkedListWithTail<Animal> cats_;
            datastructures::LinkedListWithTail<Animal> dogs_;
            size_t order_;

            public:

            AnimalShelter() :
                cats_(datastructures::LinkedListWithTail<Animal>()),
                dogs_(datastructures::LinkedListWithTail<Animal>()),
                order_(0)
                {}

            void enqueue(Animal& animal) {
                if (animal.type() == 'C') {
                    animal.order = order_++;
                    cats_.push_back(animal);
                    return;
                }

                if (animal.type() == 'D') {
                    animal.order = order_++;
                    dogs_.push_back(animal);
                    return;
                }
                throw "unsuported animal provided";
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

            Animal dequeue() {
                if (dogs_.empty() && cats_.empty()) {
                    throw std::out_of_range("empty list");
                }

                if (dogs_.empty()) {
                    return cats_.pop_front();
                }

                if (cats_.empty()) {
                    return dogs_.pop_front();
                }

                if (dogs_.front().order < cats_.front().order) {
                    return dogs_.pop_front();
                }

                return cats_.pop_front();
            }
        };
    }
}

#endif
