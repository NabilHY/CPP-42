#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>
#include <sstream>

class Helpers {
    public: 
        static void handleSpecials(const std::string &);
        static bool intChecker(const std::string &);
        static bool floatingPointChecker(const std::string &);
        static bool scientificNot(const std::string &);
        static bool isChar(const std::string &);
        static void trim(std::string &str);
        static bool initialChecks(std::string &);
        static bool all_digits(std::string);
        static bool is_valid(std::string);
        static bool in_range(const std::string &);
        static std::string precisionFix(double val, int prec);
        static double stringToDouble(const char* str);
        static int decCount(const std::string &, bool);
        static int digitsBeforeDecimal(const std::string &);
};