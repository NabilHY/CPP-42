#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {std::cout << "Cat Default constructor\n";brain = new Brain();};

Cat::Cat( const Cat & ref ) : Animal() {
    std::cout << "Cat Copy Constructor\n";
    brain = new Brain();
    *this = ref;
};

Cat::~Cat() { std::cout << "Cat Deconstructor\n"; delete brain;};

Cat &Cat::operator=( Cat const & ref ) {
    std::cout << "Cat Copy Assignment operator\n";
    if (this != &ref)
    {
        _type = ref._type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain();
        *(this->brain) = *(ref.brain);
    };
    return *this;
};
void    Cat::makeSound() const { std::cout << "Meow\n"; };

std::string Cat::get_idea(int index) const { return brain->getIdea(index); };

void    Cat::set_idea(std::string idea, int index) { brain->setIdea(idea, index); };

void    Cat::print_ideas() { brain->printIdeas();};