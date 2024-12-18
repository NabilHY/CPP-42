#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/ShrubberyCreationForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main() {
    try {
    //     // Create Bureaucrats
        // Bureaucrat lowRank("LowRank", 146);
        // Bureaucrat midRank("MidRank", 70);
        Bureaucrat highRank("HighRank", 1);

        // std::cout << highRank;
    //     // Create Forms
        ShrubberyCreationForm shrubbery("Garden");
    //     RobotomyRequestForm robotomy("Bender");
    //     PresidentialPardonForm pardon("Alice");

    //     // Test signing and executing forms
        std::cout << "\n--- Testing ShrubberyCreationForm ---\n";
        std::cout << shrubbery << std::endl;
        highRank.signForm(shrubbery);
        highRank.executeForm(shrubbery);

    //     std::cout << "\n--- Testing RobotomyRequestForm ---\n";
    //     std::cout << robotomy << std::endl;
    //     midRank.signForm(robotomy);
    //     midRank.executeForm(robotomy);

    //     std::cout << "\n--- Testing PresidentialPardonForm ---\n";
    //     std::cout << pardon << std::endl;
    //     highRank.signForm(pardon);
    //     highRank.executeForm(pardon);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}