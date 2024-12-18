# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const std::string &);
		Animal( Animal const &);
		Animal &operator=( Animal const &);
		virtual void    makeSound() const = 0;
		std::string    getType() const;
};

# endif