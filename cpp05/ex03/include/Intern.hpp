#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern&);
        Intern& operator=(const Intern&);
        AForm*   makeForm(std::string name, std::string target);
        AForm*   formSearch(std::string &name, std::string &target);
        static AForm*  createShrubbery(const std::string &);
        static AForm*  createRoboto(const std::string &);
        static AForm*  createPardon(const std::string &);
        class FormNotFound : public std::exception {
            const char * what() const throw();
        };
};