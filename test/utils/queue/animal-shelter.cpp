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

    ASSERT_EQ(animalShelter.dequeue().name, "first dog");
    ASSERT_EQ(animalShelter.dequeue().name, "first cat");
    ASSERT_EQ(animalShelter.dequeue().name, "second dog");
    ASSERT_EQ(animalShelter.dequeue().name, "second cat");
    ASSERT_EQ(animalShelter.dequeue().name, "third cat");
    ASSERT_EQ(animalShelter.dequeue().name, "third dog");

    ASSERT_THROW(animalShelter.dequeue().name, std::out_of_range);
}

TEST(animal_shelter, dequeue_dog_cat)
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

    ASSERT_EQ(animalShelter.dequeueDog().name, "first dog");
    ASSERT_EQ(animalShelter.dequeueDog().name, "second dog");
    ASSERT_EQ(animalShelter.dequeueDog().name, "third dog");
    ASSERT_EQ(animalShelter.dequeueCat().name, "first cat");
    ASSERT_EQ(animalShelter.dequeueCat().name, "second cat");
    ASSERT_EQ(animalShelter.dequeueCat().name, "third cat");

    ASSERT_THROW(animalShelter.dequeueCat().name, std::out_of_range);
    ASSERT_THROW(animalShelter.dequeueDog().name, std::out_of_range);
}