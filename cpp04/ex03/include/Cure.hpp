#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
    public:
        Cure();
        Cure(std::string type);
        ~Cure();
        Cure(const Cure &ref);
        Cure &operator=(const Cure& ref);
        AMateria *clone() const;
        void    use(ICharacter &target);
};

#endif