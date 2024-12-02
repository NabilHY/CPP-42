#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/AMateria.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource Default Constructor Called\n";
    _materias[0] = NULL;
    _materias[1] = NULL;
};

MateriaSource::MateriaSource(MateriaSource &rhs) {
    std::cout << "MateriaSource Copy Constructor Called\n";
    for (int i = 0; i < 2; i++) {
        if (rhs._materias[i]) { _materias[i] = rhs._materias[i]->clone();}
    }
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &rhs) {
    std::cout << "MateriaSource Copy Assignment Operator Called\n";
    for (int i = 0; i < 2; i++)
    {
        if (_materias[i])
        {
            delete _materias[i];
            _materias[i] = NULL;
        }
        if (rhs._materias[i])
            _materias[i] = rhs._materias[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource Destructor Called\n";
    for (int i = 0; i < 2; i++)
    {
        if (_materias[i])
            _materias[i] = NULL;
    }
};

int MateriaSource::checker(AMateria *materia, AMateria *m) {
    if (materia && m) {if (materia->getType() == m->getType()) {return 1;};};
    return 0;
};

int MateriaSource::existsByMateria(AMateria *materia){
        for (int i = 0; i < 2; i++) {
            if (_materias[i] && _materias[i]->getType() == materia->getType()) {return 1;}
        }
        return 0;
};

int MateriaSource::existsByType(std::string const &type){
        for (int i = 0; i < 2; i++) { if (_materias[i] && _materias[i]->getType() == type) return i; };
        return (-1);
};

void    MateriaSource::learnMateria(AMateria *m) {
    if (!m) {std::cout << "Non Valid Materia\n"; return;};
    if (m->getType() != "ice" && m->getType() != "cure") { std::cout << "MateriaSource Restricted to only learning Ice and Cure materias\n"; return ;}
    else if (existsByMateria(m)) {std::cout << m->getType() << " Materia Already Learned !\n"; return ;}
    else
    {
        for (int i = 0; i < 2; i++) {
            if (!_materias[i]) {_materias[i] = m; break;}
        };
        std::cout << m->getType() << " Materia Learned !!!\n";
    }
};

AMateria*   MateriaSource::createMateria(std::string const &type) {
    int choice = 0;
    std::string materia;
    if ((type != "ice" && type != "cure") || existsByType(type) == -1)
    {
        std::cout << "Non-Existing Materia\n";
        std::string input;
        while (choice != 1 && choice != 2) {
            std::cout << "Choose A Materia To Create: (1. Ice 2. Cure)\n";
            std::getline(std::cin, input);
            if (input == "1" || input == "2") {
                materia = input;
                break;
            } else {
                std::cout << "Invalid input. Please choose 1 or 2.\n";
            }
        }
        if (materia == "1")
        {
            std::cout << "Learning Ice Materia ....\n";
            this->learnMateria(new Ice());
        }
        else if (materia == "2")
        {
            std::cout << "Learning Cure Materia ....\n";
            this->learnMateria(new Cure());
        }
    }
    return _materias[existsByType(type)];
};