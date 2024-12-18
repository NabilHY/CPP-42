#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat pm("Prime Minister", 150);
        std::cout << "I got here\n";
        pm.decrementGrade();
        std::cout << pm;
        Bureaucrat pm2("Prime Minister2", 151);
        std::cout << "I got here2\n";
    } catch (std::exception &e) {
        std::cout << "Exception Caught: " << e.what();
    }
}
