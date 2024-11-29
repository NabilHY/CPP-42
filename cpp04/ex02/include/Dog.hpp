#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog( Dog const &);
		~Dog();
		Dog &operator=( Dog const &);
		void    makeSound() const;
		std::string    getType() const;
		void set_idea(std::string idea, int index);
		std::string get_idea(int index) const;
		void print_ideas();
};

#endif