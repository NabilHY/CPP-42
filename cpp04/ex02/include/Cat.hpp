#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat( Cat const &);
		~Cat();
		Cat &operator=( Cat const &);
		void    makeSound() const;
		std::string    getType() const;
		void set_idea(std::string idea, int index);
		std::string get_idea(int index) const;
		void print_ideas();
};

#endif