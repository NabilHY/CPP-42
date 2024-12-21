#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm &);
        void    execute(Bureaucrat const  &) const;
};