#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat Default constructor\n"; };

Cat::Cat( const Cat & ref ){ std::cout << "Cat Copy Constructor\n"; _type = ref._type; };

Cat::~Cat() { std::cout << "Cat Deconstructor\n";};

Cat &Cat::operator=( Cat const & ref ) { std::cout << "Cat Copy Assignment operator\n";if (this != &ref) { _type = ref._type;}; return *this; };

void    Cat::makeSound() const { std::cout << "Meow\n"; };

std::string    Cat::getType() const { return _type; };
