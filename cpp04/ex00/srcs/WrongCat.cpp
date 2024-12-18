#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat Default constructor\n"; };

WrongCat::WrongCat( const WrongCat & ref ){ std::cout << "WrongCat Copy Constructor\n"; _type = ref._type; };

WrongCat::~WrongCat() { std::cout << "WrongCat Deconstructor\n"; };

WrongCat &WrongCat::operator=( WrongCat const & ref ) { std::cout << "WrongCat Copy Assignment operator\n";if (this != &ref) { _type = ref._type;}; return *this; };

void    WrongCat::makeSound() { std::cout << "Meow\n"; };

std::string    WrongCat::getType() const { return _type; };