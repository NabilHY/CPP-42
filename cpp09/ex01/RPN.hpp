#pragma once

#include <iostream>
#include <stdexcept>
#include <stack>
#include <string>
#include <algorithm>

class RPN {
    public:
        RPN();
        ~RPN();
        RPN(const RPN &rhs);
        RPN &operator=(const RPN &rhs);
        static std::string rpnInput;
        static bool isOperand(char c);
        static bool isOperator(char c);
        static bool spacingValidation(std::string input);
        static void earlyValidation(int ac, char **av);
        static void startCalc(const std::string &input);
        static int  topAndPop(std::stack<char> &ref);
    class InvalidExpression : public std::exception {
        const char * what() const throw();
    };
};