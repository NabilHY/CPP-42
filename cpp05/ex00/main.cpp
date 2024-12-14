#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat pm("Prime Minister", 1);
        // pm.incrementGrade();
        if (pm.getGrade() < 1)
        {
            throw GradeTooHighException();
        } else if (pm.getGrade() > 150) {
            throw GradeTooLowException();
        }
        std::cout << pm;
    } catch (std::exception &e) {
        std::cout << "Exception Caught: " << e.what();
    }
}
