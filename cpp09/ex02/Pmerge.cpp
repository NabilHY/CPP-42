#include "Pmerge.hpp"

Pmerge::Pmerge() {};
// Pmerge::~Pmerge() {};
// Pmerge::Pmerge(const Pmerge &rhs) { *this = rhs; };
// Pmerge & Pmerge::operator=(const Pmerge &rhs) { (void)rhs; return *this; };

const char * Pmerge::IncorrectArgs::what() const throw() {
    return "Input error: Pmerge criteria not matched!";
};

std::vector<std::string> Pmerge::splitString(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);

    while (std::getline(tokenStream, token, ' ')) {
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}

bool Pmerge::isPositiveNumber(const std::string& str) {
    size_t i = 0;
    if (str.empty()) {
        return false;
    }
    if (str[0] == '+')
        i++;
    for (; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void Pmerge::parseAndValidateInput(const std::string& input, std::vector<int>& integers) {
    std::vector<std::string> args = splitString(input);
    std::vector<std::string>::iterator it;

    for (it = args.begin(); it != args.end(); it++) {
        if (!isPositiveNumber(*it)) {
            throw Pmerge::IncorrectArgs();
        }
        integers.push_back(std::stoi(*it));
    }
}

void    Pmerge::earlyValidation(int ac, char **av, std::vector<int>& integers) {
    if (ac != 1) {
        if (ac == 2) {
            parseAndValidateInput(av[1], integers);
            return;
        } else {
            for (int i = 1; i < ac; i++) {
                parseAndValidateInput(av[i], integers);
            };
            return ;
        }
    }
    throw Pmerge::IncorrectArgs();
};

void Pmerge::printVector(std::vector<int>& integers) {
    std::vector<int>::iterator it;

    for (it = integers.begin(); it != integers.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

