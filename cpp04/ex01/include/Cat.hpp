#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *ideas;
	public:
		Cat();
		Cat( Cat const &);
		~Cat();
		Cat &operator=( Cat const &);
		void    makeSound() const;
		std::string    getType() const;
};

#endif