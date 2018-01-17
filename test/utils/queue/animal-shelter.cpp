#include "gtest/gtest.h"
#include "utils/queue/animal-shelter.h"

TEST(animal_shelter, queue_enqueue_any)
{
    utils::queue::AnimalShelter animalShelter;

    utils::queue::Dog firstDog, secondDog, thirdDog;
    utils::queue::Cat firstCat, secondCat, thirdCat;

    firstDog.name = "first dog";
    secondDog.name = "second dog";
    thirdDog.name = "third dog";

    firstCat.name = "first cat";
    secondCat.name = "second cat";
    thirdCat.name = "third cat";

    animalShelter.enqueue(firstDog);
    animalShelter.enqueue(firstCat);
    animalShelter.enqueue(secondDog);
    animalShelter.enqueue(secondCat);
    animalShelter.enqueue(thirdCat);
    animalShelter.enqueue(thirdDog);
}