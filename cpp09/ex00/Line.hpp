#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>

class Line {
    public:
        static std::string date;
        static std::string value;

        Line();
        Line(std::string line);
        ~Line();
        Line(const Line &rhs);
        Line &operator=(const Line &rhs);

        static  size_t digitsAfterDecimal(const std::string &);
        static  bool    doublePointChecker(const std::string &);

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

        void setValue(int value);
        void setYear(int y);
        void setMonth(int m);
        void setDay(int y, int m, int d);
};