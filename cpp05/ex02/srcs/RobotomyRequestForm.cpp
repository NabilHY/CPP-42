#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Shrubbery Creation Form", 72, 45), _target("Target") {
    std::cout << "RobotomyRequestForm Default Constuctor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm Parametritized Constuctor\n";
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm Destructor\n"; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) 
    : AForm("Shrubbery Creation Form", 72, 45), _target(rhs._target) {
    std::cout << "RobotomyRequestForm Copy Constructor\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    std::cout << "RobotomyRequestForm Assignmenet Opearator\n";
    if (this != &rhs){
        AForm::operator=(rhs);
    }
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const  &Bureaucrat) const {
    
}