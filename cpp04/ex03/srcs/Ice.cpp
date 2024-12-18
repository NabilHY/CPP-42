#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice") { std::cout << ""; std::cout << "Ice Constructor Called\n";}

Ice::Ice(std::string type) : AMateria(type) { std::cout << "Ice Constructor Called\n"; };

Ice::~Ice() { std::cout << "Ice destructor \n"; };

Ice::Ice(const Ice& ref) : AMateria(ref._type) {
    std::cout << "Ice Copy Constructor Called\n";
    _type = ref._type;
};

Ice &Ice::operator=(const Ice& ref) {
    std::cout << "Ice copy assignment operator called\n";
    if (this != &ref)
        _type = ref._type;
    return *this;
};

void    Ice::use(ICharacter &target) {std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;};

AMateria *Ice::clone() const {
    return (new Ice(this->getType()));
};
