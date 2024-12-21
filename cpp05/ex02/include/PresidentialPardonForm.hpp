#pragma once

#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm &);
        void    execute(Bureaucrat const  &) const;
};