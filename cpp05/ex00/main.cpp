#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat pm("Prime Minister", 150);
        pm.decrementGrade();
        std::cout << pm;
        Bureaucrat pm2("Prime Minister2", 151);
    } catch (std::exception &e) {
        std::cout << "Exception Caught: " << e.what();
    }
}
