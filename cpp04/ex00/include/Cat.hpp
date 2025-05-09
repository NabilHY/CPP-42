#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat( Cat const &);
		~Cat();
		Cat &operator=( Cat const &);
		void    makeSound() const;
		std::string    getType() const;
};


#endif