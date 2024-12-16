#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _grade_to_sign;
        const int _grade_to_exec;
    public :
        Form();
        Form(std::string, const int, const int);
        ~Form();
        Form(const Form&);
        Form &operator=(const Form&);
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
        void    beSigned(const Bureaucrat &);
};

std::ostream&   operator << (std::ostream &COUT, const Form &rhs);

// Grades of Form follow same Rules (exceptions)
// Two Grades 
// Getters for all attributes and an overload of the insertion << (prints form info)
// beSigned() member function to the Form that takes a Bureaucrat as param
    // Changes the form status to signed if bureucr grade is high or equal to required