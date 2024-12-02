#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria *_inventory[4];
    public:
        Character();
        ~Character();
        Character(Character const &);
        Character(std::string const &);
        Character &operator=(Character const &);
        std::string const &getName() const;
        void    equip(AMateria *);
        void    unequip(int);
        void    use(int, ICharacter &);
};

#endif