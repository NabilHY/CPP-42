#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") { std::cout << "WrongAnimal Default constructor\n"; }

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {std::cout << "WrongAnimal Parameritized Constructor\n";};

WrongAnimal::WrongAnimal( const WrongAnimal & ref ){ _type = ref._type; std::cout << "WrongAnimal Copy Constructor\n"; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal Deconstructor\n"; }

WrongAnimal &WrongAnimal::operator=( WrongAnimal const & ref ) { std::cout << "WrongAnimal Copy Assignment operator\n"; if (this != &ref) { _type = ref._type;}; return *this; };

void    WrongAnimal::makeSound() const { std::cout << "Roarrr\n"; };

std::string    WrongAnimal::getType() const { return _type; };