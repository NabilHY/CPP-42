#include "../include/Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Default Constructor\n";
}

Intern::~Intern() {
    std::cout << "Intern Default Destructor\n";
}

Intern::Intern(const Intern&) {
    std::cout << "Intern Copy Constructor\n";
}

Intern &Intern::operator=(const Intern&rhs) {
    std::cout << "Intern Copy Assignment Operator\n";
    (void)rhs;
    return *this;
}

AForm*  Intern::createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::createRoboto(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm*  Intern::createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm*  Intern::formSearch(std::string &name, std::string &target) {
    const std::string forms[] = {
        "shrubbery creation",
        "presidential pardon",
        "robotomy request"
    };
    AForm* (Intern::*formCreator[])(const std::string&) = { &Intern::createShrubbery, &Intern::createPardon, &Intern::createRoboto};
    for (int i = 0; i < 3; i++) {
        if (name == forms[i])
            return ((this->*formCreator[i])(target));
    }
    throw FormNotFound();
}

const char*   Intern::FormNotFound::what() const throw () {
    return ("Sorry But No Form Registered\n Try The Following:\n-> shrubbery creation\n-> presidential pardon\n-> robotomy request\n");
};

AForm*  Intern::makeForm(std::string name, std::string target) {
    AForm* form = NULL;
    try {
        form = formSearch(name, target);
        std::cout << "Intern creates " << form->getName() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Intern: " << e.what() << std::endl;
    };
    return form;
}