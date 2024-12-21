#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("Target") {
    std::cout << "RobotomyRequestForm Default Constuctor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm Parametritized Constuctor\n";
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm Destructor\n"; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) 
    : AForm("Robotomy Request Form", 72, 45), _target(rhs._target) {
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

const char  * RobotomyRequestForm::RobotomyRequestFailure::what() const throw () {
    return ("Robotomy operation Failed Due to some technical issues ... ");
}

void    RobotomyRequestForm::execute(Bureaucrat const  &bureaucrat) const {
    if (!getSign())
        throw FormNotSigned();
    if (bureaucrat.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout << "Drilling Noises .......\n";
    std::srand(std::time(0));
    int randomNum = std::rand() % 10;
    if (randomNum % 2)
        throw RobotomyRequestFailure();
    std::cout << "Robotmization of " << _target << " Completed Successefully\n";
}