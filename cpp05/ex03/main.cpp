#include <iostream>
#include "include/Intern.hpp"
#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main() {
    try {
        // Create an Intern
        Intern intern;

        // Bureaucrats
        Bureaucrat alice("Alice", 5);
        Bureaucrat bob("Bob", 150);

        // Create forms using the intern
        AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
        AForm* robotomy = intern.makeForm("robotomy request", "robot");
        AForm* pardon = intern.makeForm("presidential pardon", "criminal");
        // Output forms
        std::cout << *shrubbery << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *pardon << std::endl;

        // Bureaucrats trying to sign and execute the forms
        alice.signForm(*shrubbery);
        alice.executeForm(*shrubbery);

        bob.signForm(*robotomy);
        bob.executeForm(*robotomy);

        alice.signForm(*pardon);
        alice.executeForm(*pardon);

        // Test an invalid form name
        AForm* invalidForm = intern.makeForm("invalid form name", "test target");
        if (invalidForm)
            delete invalidForm;
        delete shrubbery;
        delete robotomy;
        delete pardon;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}