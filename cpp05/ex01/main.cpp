#include <iostream>
#include <string.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << std::endl;
        try {
            Bureaucrat bob("Bob", 0);
        } catch (const std::exception& e) {
            std::cerr << "Failed to create Bureaucrat: " << e.what() << std::endl;
        }
        try {
            Bureaucrat charlie("Charlie", 151);
        } catch (const std::exception& e) {
            std::cerr << "Failed to create Bureaucrat: " << e.what() << std::endl;
        }
        Form taxForm("TaxForm", 131, 131);
        std::cout << taxForm << std::endl;
        alice.signForm(taxForm);
        Bureaucrat dave("Dave", 100);
        dave.signForm(taxForm);
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    return 0;
}
