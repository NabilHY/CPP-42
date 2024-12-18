#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( WrongCat const &);
		~WrongCat();
		WrongCat &operator=( WrongCat const &);
		void    makeSound();
		std::string    getType() const;
};


#endif