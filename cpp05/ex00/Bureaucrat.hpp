#pragma once

#include <string>
#include <iostream>

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
};  

std::ostream& operator<<(std::ostream &COUT, const Bureaucrat& ref);
