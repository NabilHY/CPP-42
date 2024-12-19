#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 25, 5), _target("Target") {
    std::cout << "PresidentialPardonForm Default Constuctor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm Parametritized Constuctor\n";
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm Destructor\n"; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) 
    : AForm("Presidential Pardon Form", 25, 5), _target(rhs._target) {
    std::cout << "PresidentialPardonForm Copy Constructor\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    std::cout << "Presidential Pardon Form Assignmenet Opearator\n";
    if (this != &rhs){
        AForm::operator=(rhs);
    }
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const  &bureaucrat) const {
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw GradeTooLowException();
    if (!getSign())
        throw FormNotSigned();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}