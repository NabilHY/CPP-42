#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "Dog Default constructor\n"; brain = new Brain();};

Dog::Dog( const Dog & ref ) : Animal() {
    std::cout << "Dog Copy Constructor\n";
    brain =new Brain();
    *this = ref;
};

Dog::~Dog() { std::cout << "Dog Deconstructor\n"; delete brain;};

Dog &Dog::operator=( Dog const & ref ) {
    std::cout << "Dog Copy Assignment operator\n";
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

void    Dog::makeSound() const { std::cout << "Woof Woof\n"; };

std::string Dog::get_idea(int index) const { return brain->getIdea(index); };

void    Dog::set_idea(std::string idea, int index) { brain->setIdea(idea, index); };

void    Dog::print_ideas() {brain->printIdeas();};