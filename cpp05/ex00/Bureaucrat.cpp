#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("Corrupt Bureaucrat"), _grade(150)
{ std::cout << "Default Constructor\n"; };

Bureaucrat::Bureaucrat(const std::string &name, int grade) 
    : _name(name), _grade(grade) {
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat Constructor\n";
}
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor\n";
} 

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
    : _name(rhs._name), _grade(rhs._grade){
    std::cout << "Bureaucrat Copy Constructor\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
    std::cout << "Bureaucrat Assignement Operator\n";
    if (this != &rhs)
        _grade = rhs._grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void    Bureaucrat::incrementGrade() {
    if ((_grade - 1) < 1)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    if ((_grade + 1) > 150)
        throw GradeTooLowException();
    _grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw () { return "Grade Too High!\n"; }

const char * Bureaucrat::GradeTooLowException::what() const throw () { return "Grade Too Low!\n"; }

std::ostream& operator << (std::ostream &COUT, const Bureaucrat& obj) {
    COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return COUT;
}