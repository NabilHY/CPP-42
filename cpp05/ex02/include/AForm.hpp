#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
    public :
        AForm();
        AForm(std::string, const int, const int);
        virtual ~AForm();
        AForm(const AForm&);
        AForm &operator=(const AForm&);
        std::string getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecGrade()const ;
        class GradeTooHighException : public std::exception {
            public:
                const char * what() const throw ();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char * what() const throw ();
        };
        class FormNotSigned : public std::exception {
            public:
                const char * what() const throw ();
        };
        void    beSigned(Bureaucrat const  &);
        virtual void execute(Bureaucrat const  &) const = 0;
};

std::ostream&   operator << (std::ostream &COUT, const AForm &rhs);
