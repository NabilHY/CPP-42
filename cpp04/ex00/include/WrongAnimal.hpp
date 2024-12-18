#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &);
		WrongAnimal( WrongAnimal const &);
		~WrongAnimal();
		WrongAnimal &operator=( WrongAnimal const &);
		void    makeSound() const;
		std::string    getType() const;
};

#endif

