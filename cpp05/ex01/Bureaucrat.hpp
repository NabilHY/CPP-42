#pragma once

#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string&, int);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &);
        Bureaucrat& operator=(const Bureaucrat &);
        const std::string &getName() const;
        int     getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        class GradeTooHighException : public std::exception {
            public:
                const char * what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char * what() const throw();
        };
        void    signForm(Form &);
};

std::ostream& operator << (std::ostream &COUT, const Bureaucrat& ref);
