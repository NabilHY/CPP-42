#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *ideas;
	public:
		Dog();
		Dog( Dog const &);
		~Dog();
		Dog &operator=( Dog const &);
		void    makeSound() const;
		std::string    getType() const;
};

#endif