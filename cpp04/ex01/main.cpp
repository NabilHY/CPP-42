#include "./include/Animal.hpp"
#include "./include/Dog.hpp"
#include "./include/Cat.hpp"
#include "./include/Brain.hpp"

int main()
{
    /* Ensuring no leaks occur during Animal Creation - Deallocating Brain */
    Animal *animals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << "===\n";
        animals[i]->makeSound();
        std::cout << "===\n";
    }
    for (int i = 0; i < 4; i++)
        delete animals[i];
    /* Deep Copy Checks */
    Cat *kitty = new Cat();
    Cat *whiskers = new Cat();
    kitty->set_idea("Chase mice", 0);
    kitty->set_idea("Climb trees", 1);
    kitty->set_idea("Nap in the sun", 2);
    kitty->set_idea("Play with yarn", 3);
    *whiskers = *kitty;
    kitty->set_idea("Pounce on toys", 4);
    whiskers->print_ideas();
    Cat curious_cat(*kitty);
    kitty->set_idea("Drink milk", 5);
    curious_cat.print_ideas();
    std::cout << "=== Destruction ===\n";
    delete kitty;
    delete whiskers; 
};

    /*Dog *doggo = new Dog();
    Dog *snoopie = new Dog();
    doggo->set_idea("SSosit", 0);
    doggo->set_idea("SSosit1", 1);
    doggo->set_idea("SSosit2", 2);
    doggo->set_idea("SSosit3", 3);
    doggo->print_ideas();
    *snoopie = *doggo;
    doggo->set_idea("SSosit4", 4);
    Dog snoop_dogg(*snoopie);
    snoopie->set_idea("Bones\n", 5);
    snoop_dogg.print_ideas();
    snoop_dogg.set_idea("Chiba", 6);
    snoop_dogg.print_ideas();
    snoopie->print_ideas();
    std::cout << "=== Destruction ===\n";
    delete doggo;
    delete snoopie;*/
