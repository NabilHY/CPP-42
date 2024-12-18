#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure") { std::cout << ""; std::cout << "Cure Constructor Called\n";}

Cure::Cure(std::string type) : AMateria(type) { std::cout << "Cure Copy Constructor Called\n"; };

Cure::~Cure() { std::cout << "Cure destructor\n"; };

Cure::Cure(const Cure& ref) : AMateria(ref._type) {
    std::cout << "Cure Copy Constructor Called\n";
    _type = ref._type;
};

Cure &Cure::operator=(const Cure& ref) {
    std::cout << "Cure copy assignment operator called\n";
    if (this != &ref)
        _type = ref._type;
    return *this;
};

void    Cure::use(ICharacter &target) {std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;};

AMateria *Cure::clone() const {
    return (new Cure(this->getType()));
};
