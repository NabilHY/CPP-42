#include "../include/Character.hpp"

#include <unistd.h>

Character::Character() {
    std::cout << "Character Default Constructor\n";
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _name = "The Cursed";
};

Character::Character(std::string const &name) : _name(name) {
    std::cout << "Character Parameritized Constructor\n";
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::~Character() {
    std::cout << "Character Destructor Called\n";
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    };
}

Character::Character(Character const &rhs){
    std::cout << "Character Copy Constructor Called\n";
    this->_name = rhs._name;
    for (int i = 0; i < 4; i++)
    {
        if (rhs._inventory[i])
            _inventory[i] = rhs._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character&  Character::operator=(Character const &rhs){
    std::cout << "Character Copy assignment operator Called\n";
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const {
    return (_name);
}


void    Character::equip(AMateria *m){
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i]) {
            _inventory[i] = m;
            std::cout << m->getType() << " Materia Equipped For Character " << _name << std::endl;
            return ;
        };
    }
    std::cout << "Inventory is Full !!\n";
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid Index\n";
        return ;
    }
    if (_inventory[idx])
    {
        _inventory[idx] = NULL;
        std::cout << "Materia unequiped !\n";
        return ;
    }
    else
        std::cout << "No Materia Found in pocket " << idx << std::endl ;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4){
        std::cout << "Invalid Index\n";
        return ;
    }
    if (!_inventory[idx]){std::cout << "No Materia Found in pocket \n";return;}
    _inventory[idx]->use(target);
    delete _inventory[idx];
    _inventory[idx] = NULL;
}