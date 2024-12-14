#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat Parameretized Constructor\n";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Default Destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs): _name(rhs._name), _grade(rhs._grade){
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
    _grade--;
}

void    Bureaucrat::decrementGrade() {
    _grade++;
}

GradeTooHighException::GradeTooHighException() {}

const char * GradeTooHighException::what() const throw () { return "Grade Too High!\n"; }

GradeTooLowException::GradeTooLowException() {}

const char * GradeTooLowException::what() const throw () { return "Grade Too Low!\n"; }

std::ostream& operator << (std::ostream &COUT, const Bureaucrat& obj) {
    COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return COUT;
}