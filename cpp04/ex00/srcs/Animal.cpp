#include "../include/Animal.hpp"

Animal::Animal() : _type("Animal") { std::cout << "Animal Default constructor\n"; }

Animal::Animal(const std::string &type) : _type(type) {std::cout << "Animal Parameritized Constructor\n";};

Animal::Animal( const Animal & ref ){ _type = ref._type; std::cout << "Animal Copy Constructor\n"; }

Animal::~Animal() { std::cout << "Animal Deconstructor\n"; }

Animal &Animal::operator=( Animal const & ref ) { std::cout << "Animal Copy Assignment operator\n"; if (this != &ref) { _type = ref._type;}; return *this; };

void    Animal::makeSound() const { std::cout << "Roarrr\n"; };

std::string    Animal::getType() const { return _type; };