#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/Brain.hpp"

int main()
{
    Animal *animals[6];
    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();
    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 6; i++)
        delete animals[i];
}
