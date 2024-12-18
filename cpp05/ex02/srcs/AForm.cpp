#include "../include/AForm.hpp"

AForm::AForm()
    : _name("Corrupt Form"), _signed(false), _grade_to_sign(150), _grade_to_exec(150) {
    std::cout << "Form Default Constructor\n";
};

AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_exec)
    :  _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form Constructor\n";
    _signed = false;
};

AForm::~AForm() { std::cout << "Form Destructor\n"; };

AForm::AForm(const AForm& rhs)
    : _name(rhs._name), _signed(rhs._signed), _grade_to_sign(rhs._grade_to_sign), _grade_to_exec(rhs._grade_to_exec){
    std::cout << "Form Copy Contructor\n";
};

AForm&   AForm::operator=(const AForm& rhs) {
    std::cout   << "Form Copy Assignment Operator\n";
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return *this;
};

std::string AForm::getName() const {return (_name);}

bool AForm::getSign() const {return (_signed);}

int AForm::getSignGrade() const {return (_grade_to_sign);}

int AForm::getExecGrade() const {return (_grade_to_exec);}

const char * AForm::GradeTooHighException::what() const throw () {
    return ("Form can't be signed - Grade Too High!");
};

const char * AForm::FormNotSigned::what() const throw () {
    return ("Form Can't Be Executed - Not Signed Yet!");
};

const char * AForm::GradeTooLowException::what() const throw () {
    return ("Form Not Signed To be Executed!");
};

std::ostream& operator << (std::ostream &COUT, const AForm &rhs) {
    COUT << "--------------\n";
    COUT << "Form: " << rhs.getName() << "\nStatus: " 
        << (rhs.getSign() ? "Signed\n" : "Unsigned\n") << "Grade to sign: " << rhs.getSignGrade()
            << "\nGrade to execute: " << rhs.getExecGrade() << std::endl;
    COUT << "--------------\n";
    return COUT;
};

void    AForm::beSigned(const Bureaucrat &ref) {
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
