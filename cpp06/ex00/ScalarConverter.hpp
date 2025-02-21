#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class ScalarConverter {
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter& operator=(ScalarConverter&);
    public :
        static void convert(const std::string& literal);
        class NonDisplayable : public std::exception {
            public:
                const char * what() const throw();
        };
        class ImpossibleConversion : public std::exception {
            public:
                const char * what() const throw();
        };
};

