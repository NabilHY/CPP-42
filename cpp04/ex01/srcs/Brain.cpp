#include "../include/Brain.hpp"

Brain::Brain() { std::cout << "Brain Default constructor\n"; };

Brain::Brain( const Brain & ref ){(void)ref; std::cout << "Brain Copy Constructor\n"; };

Brain::~Brain() { std::cout << "Brain Deconstructor\n";};

Brain &Brain::operator=( Brain const & ref ) {(void)ref; std::cout << "Brain Copy Assignment operator\n"; return *this;};