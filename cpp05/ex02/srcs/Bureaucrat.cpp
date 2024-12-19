#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

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
    _grade--;
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

void    Bureaucrat::decrementGrade() {
    _grade++;
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw () { return "Grade Too High!\n"; }

const char * Bureaucrat::GradeTooLowException::what() const throw () { return "Grade Too Low!\n"; }

std::ostream& operator << (std::ostream &COUT, const Bureaucrat& obj) {
    COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return COUT;
};

void    Bureaucrat::signForm(AForm &ref) {
    try {
        ref.beSigned(*this);
        std::cout <<  _name << " signed " << ref.getName() << std::endl;
    } catch (std::exception &e) {
        std::cerr << _name  << " couldn't sign because " << e.what() << std::endl;
    }
};

void    Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName();
    } catch (std::exception &e) {
        std::cerr << "Form Execution Failed: " << e.what() << std::endl;
    }
};