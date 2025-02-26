#pragma once

#include <stdexcept>
#include <iostream>
#include "Helpers.hpp"

class ScalarConverter {
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter& operator=(ScalarConverter&);
    public :
        static void convert(std::string& literal);
        class NonDisplayable : public std::exception {
            public:
                const char * what() const throw();
        };
        class ImpossibleConversion : public std::exception {
            public:
                const char * what() const throw();
        };
        class OutOfRange : public std::exception {
            public:
                const char * what() const throw();
        };
};