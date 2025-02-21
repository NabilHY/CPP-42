#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Constructor" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs) {
    (void)rhs;
    std::cout << "Copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs)
{
    std::cout << "Copy assignment operator" << std::endl;
    return rhs;
}

const char * ScalarConverter::ImpossibleConversion::what() const throw () { return "Impossible conversion."; };

const char * ScalarConverter::NonDisplayable::what() const throw () { return "Non Displayable."; };

bool intChecker(const std::string& literal) {
    unsigned int i = 0;
    unsigned int len = literal.length();

    if (literal[0] == '+' || literal[0] == '-') {
        i++;
    }

    if (i >= len || !isdigit(literal[i])) {
        return false;
    }

    while (i < len && isdigit(literal[i])) {
        i++;
    }

    return i == len;
};

bool floatChecker(const std::string& literal) {
    unsigned int i = 0;
    unsigned int len = literal.length();

    if (len == 0) return false;

    if (literal[i] == '+' || literal[i] == '-') {
        i++;
    }

    bool hasDigits = false;
    while (i < len && isdigit(literal[i])) {
        hasDigits = true;
        i++;
    }

    if (i < len && literal[i] == '.') {
        i++;
        while (i < len && isdigit(literal[i])) {
            hasDigits = true;
            i++;
        }
    }

    if (i < len && literal[i] == 'f') {
        i++;
    }

    return hasDigits && i == len;

}

bool charChecker( const std::string& literal) {
    return literal.length() == 1 && std::isprint(literal[0]);
}

/*
    --> single char (displayable)
*/
std::ostream&   toChar(std::ostream &os, const std::string &literal) {
    if (literal.length() == 1 && isprint(literal[0])) {
        os << literal[0] << std::endl;
    } else {
        throw ScalarConverter::NonDisplayable();
    }
    return os;
}

void    ScalarConverter::convert(const std::string& literal) {
    try {
        std::cout << "char: "; 
        toChar(std::cout, literal); 
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


