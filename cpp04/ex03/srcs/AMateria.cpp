#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("Cursed Materia") {std::cout << "AMatria Default Constructor\n";};

AMateria::AMateria(std::string const &type) : _type(type) { std::cout << "AMateria Parameritized Constructor\n"; };

AMateria::AMateria(AMateria const & rhs)
{
    std::cout << "Copy Constructor Called!\n";
    _type = rhs._type;
}

AMateria &AMateria::operator=(AMateria const & rhs)
{
    std::cout << "Copy Assignment Operator Called!\n";
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

AMateria::~AMateria() { std::cout << "AMateria Destructor\n";};

std::string const& AMateria::getType() const { return (_type); };

void AMateria::use(ICharacter &target) { std::cout << "* Throwing an empty glass bottle at " << target.getName() << " *" << std::endl;};


