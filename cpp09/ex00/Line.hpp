#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <iomanip>

class Line {
    // Static members to hold the date and value
    public:
        static std::string date;
        static std::string value;

        Line(std::string line);  // Constructor declaration
        ~Line();
        Line(const Line &);
        Line&  operator =(const Line &);

        static  size_t digitsAfterDecimal(const std::string &);
        static  bool    doublePointChecker(const std::string &);

        // Exception classes
        class BadInput : public std::exception {
            const char* what() const throw() {
                return (("Error: bad input => " + Line::date).c_str());
            }
        };

        class NegativeVal : public std::exception {
            const char* what() const throw() {
                return "Error: not a positive number.";
            }
        };

        class LargeVal : public std::exception {
            const char* what() const throw() {
                return "Error: too large a number.";
            }
        };

        class InvalidLine : public std::exception {
            const char* what() const throw() {
                return "Error: Bad format.";
            }
        };

        // Member functions to validate values
        void setValue(long value);
        void setYear(int y);
        void setMonth(int m);
        void setDay(int y, int m, int d);
};