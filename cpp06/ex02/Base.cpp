#include "Base.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

Base::~Base()
{
    std::cout << "Destructor" << std::endl;
}

Base* generate(void) {
    std::srand(std::time(0));
    int randomNum = std::rand() % 3;
    
    switch (randomNum) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    };

    return NULL;
};

void    identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "Class is of Type A." << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "Class is of Type B." << std::endl;
    }  else if (dynamic_cast<C *>(p)) {
        std::cout << "Class is of Type C." << std::endl;
    }
}

void    identify(Base &p) {
    std::string type;

    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        type = "A.";
    } catch (std::exception &e) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            type = "B.";
        } catch (std::exception &e) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                type = "C.";
            } catch (std::exception &e) {};
        }
    }
    std::cout << "Class if of type " << type << std::endl;
};
