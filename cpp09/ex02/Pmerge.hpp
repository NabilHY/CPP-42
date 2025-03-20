#pragma once

#include <deque>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

/*
     - Program use a positive integer sequence as an argument
     - program must use the merge insert sort algo to sort thr positive
     integer sequence
*/

class Pmerge {
    public:
        Pmerge();
        // ~Pmerge();
        // Pmerge(const Pmerge &rhs);
        // Pmerge & operator=(const Pmerge &rhs);
        static void earlyValidation(int, char **, std::vector<int>&);
        static bool isPositiveNumber(const std::string& );
        static void parseAndValidateInput(const std::string& , std::vector<int>&);
        static std::vector<std::string> splitString(const std::string& );
        static void printVector(std::vector<int>&);
        class IncorrectArgs : public std::exception {
            const char * what() const throw();
        };
};