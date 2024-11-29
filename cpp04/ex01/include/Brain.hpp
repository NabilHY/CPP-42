# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
    private:
        std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain( Brain const & );
		Brain &operator=( Brain const &);
		void	setIdea(std::string idea, int index);
		std::string	getIdea(int index) const;
		void	printIdeas();
};

#endif