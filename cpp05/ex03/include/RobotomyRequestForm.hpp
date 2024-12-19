#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm&  operator=(const RobotomyRequestForm &);
        void    execute(Bureaucrat const  &) const;
        class RobotomyRequestFailure : public std::exception {
            public:
                const char * what() const throw();
        };
};