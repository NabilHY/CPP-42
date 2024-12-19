#include "Form.hpp"

Form::Form()
    : _name("Corrupt Form"), _signed(false), _grade_to_sign(150), _grade_to_exec(150) {
    std::cout << "Form Default Constructor\n";
};

Form::Form(std::string name, const int grade_to_sign, const int grade_to_exec)
    :  _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form Constructor\n";
    _signed = false;
};

Form::~Form() { std::cout << "Form Destructor\n"; };

Form::Form(const Form& rhs)
    : _name(rhs._name), _signed(rhs._signed), _grade_to_sign(rhs._grade_to_sign), _grade_to_exec(rhs._grade_to_exec){
    std::cout << "Form Copy Contructor\n";
};

Form&   Form::operator=(const Form& rhs) {
    std::cout   << "Form Copy Assignment Operator\n";
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
};

std::string Form::getName() const {return (_name);}

bool Form::getSign() const {return (_signed);}

int Form::getSignGrade() const {return (_grade_to_sign);}

int Form::getExecGrade() const {return (_grade_to_exec);}

const char * Form::GradeTooHighException::what() const throw () {
    return ("Form can't be signed - Grade Too High!");
};

const char * Form::GradeTooLowException::what() const throw () {
    return ("Form can't be signed - Grade Too Low!");
};

std::ostream& operator << (std::ostream &COUT, const Form &rhs) {
    COUT << "--------------\n";
    COUT << "Form: " << rhs.getName() << "\nStatus: " 
        << (rhs.getSign() ? "Signed\n" : "Not signed\n") << "Grade to sign: " << rhs.getSignGrade()
            << "\nGrade to execute: " << rhs.getExecGrade() << std::endl;
    COUT << "--------------\n";
    return COUT;
};

void    Form::beSigned(const Bureaucrat &ref) {
    if (_signed)
    {
        std::cout << "Form " << _name << " Already signed!\n";
        return ;
    }
    if (ref.getGrade() > _grade_to_sign)
        throw GradeTooLowException();
    else
        _signed = true;
}

