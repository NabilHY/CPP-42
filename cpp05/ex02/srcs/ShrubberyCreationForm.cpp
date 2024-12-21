#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("Target") {
    std::cout << "ShrubberyCreationForm Default Constuctor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm Parametritized Constuctor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm Destructor\n"; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(rhs._target) {
    std::cout << "ShrubberyCreationForm Copy Constructor\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    std::cout << "ShrubberyCreationForm Assignmenet Opearator\n";
    if (this != &rhs){
        AForm::operator=(rhs);
    }
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const  &bureaucrat) const {
    if (!getSign())
        throw FormNotSigned();
    if (bureaucrat.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::ofstream shrubb((_target+"_shrubbery").c_str());
    shrubb << "       ###" << std::endl;
    shrubb << "      #o###" << std::endl;
    shrubb << "    #####o###" << std::endl;
    shrubb << "   #o#\\#|#/###" << std::endl;
    shrubb << "    ###\\|/#o#" << std::endl;
    shrubb << "     # }|{  #" << std::endl;
    shrubb << "       }|{" << std::endl;
    shrubb.close();
}