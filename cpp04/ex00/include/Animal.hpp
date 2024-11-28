#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string &);
		Animal( Animal const &);
		virtual ~Animal();
		Animal &operator=( Animal const &);
		virtual void    makeSound() const;
		std::string    getType() const;
};

#endif