#include "../include/Brain.hpp"

Brain::Brain() { std::cout << "Brain Default constructor\n"; };

Brain::Brain( const Brain & ref ){
    std::cout << "Brain Copy Constructor\n";
    *this = ref;
}

Brain::~Brain() { std::cout << "Brain Deconstructor\n";};

Brain &Brain::operator=( Brain const & ref ) {
    std::cout << "Brain Copy Assignment operator\n";
    for (int i = 0; i < 100; ++i)
    {
        if (!ref.getIdea(i).empty())
            setIdea(ref.getIdea(i), i);
    }
    return *this;
};

void    Brain::setIdea(std::string idea, int index) {ideas[index] = idea;};

void    Brain::printIdeas(){
    std::cout << "====BRAIN IDEAS====\n";
    for (int i = 0; i < 100; i++)
    {
        if (!ideas[i].empty())
           std::cout << ideas[i] << std::endl;
    }
    std::cout << "====================\n";
}

std::string    Brain::getIdea(int index) const {
    return (ideas[index]);
}