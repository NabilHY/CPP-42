#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") {std::cout << "Dog Default constructor\n";};

Dog::Dog( const Dog & ref ){ std::cout << "Dog Copy Constructor\n"; _type = ref._type;};

Dog::~Dog() { std::cout << "Dog Deconstructor\n";};

Dog &Dog::operator=( Dog const & ref ) {std::cout << "Dog Copy Assignment operator\n"; if (this != &ref) { _type = ref._type;}; return *this; };

void    Dog::makeSound() const { std::cout << "Woof Woof\n"; };

std::string    Dog::getType() const { return _type; };
