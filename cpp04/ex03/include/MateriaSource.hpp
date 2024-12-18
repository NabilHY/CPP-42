#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria *_materias[2];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource &);
        MateriaSource &operator=(const MateriaSource &);
        void learnMateria(AMateria *m);
        AMateria    *createMateria(std::string const &type);
        int checker(AMateria *materia, AMateria *m);
        int existsByType(std::string const &type);
        int existsByMateria(AMateria *materia);
};

#endif