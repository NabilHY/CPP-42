#include "RPN.hpp"

std::string RPN::rpnInput;

//! double output

RPN::RPN() {};
RPN::~RPN() {};
RPN::RPN(const RPN &rhs) { *this = rhs; };
RPN & RPN::operator=(const RPN &rhs) { (void)rhs; return *this; };

const char * RPN::InvalidExpression::what() const throw() { 
    return "Input error: RPN criteria not matched!";
};

bool    RPN::isOperand(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
};

bool    RPN::isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
};

bool RPN::spacingValidation(std::string input) {
    bool lastWasChar = false;

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            if (lastWasChar)
                return false; 
            lastWasChar = true;
        } else {
            lastWasChar = false;
        }
    }
    return true;
}

void   RPN::earlyValidation(int ac, char **av) {
    if (ac == 2 && spacingValidation(av[1])) {
        /* Split Input String */
        std::string input = std::string(av[1]);
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
        size_t  operandsCount = 0;
        size_t  operatorsCount = 0;
        for (size_t i = 0 ; i < input.length(); i++ ) {
            if (isOperand(input[i]))
                operandsCount++;
            else if (isOperator(input[i]))
                operatorsCount++;
            else
                throw RPN::InvalidExpression();
        };
        if (operatorsCount == (operandsCount - 1)) {
            RPN::rpnInput = input;
            return ;
        } else {
            throw RPN::InvalidExpression();
        };
    } else 
        throw RPN::InvalidExpression();
}


void    RPN::startCalc(const std::string &input) {
    std::stack<double> operands;
    for (size_t i = 0 ; i < input.length(); i++) {
        if (isOperator(input[i]) && operands.size() <= 1)
            throw RPN::InvalidExpression();
        else if (isOperand(input[i])) {
            operands.push(input[i] - '0');
        } else if (isOperator(input[i])) {
            /* op2 op op1 */
            double op1 = operands.top(); operands.pop();
            double op2 = operands.top(); operands.pop();
            if (input[i] == '/' && op1 == 0)
                throw std::runtime_error("Error: Division by zero");
            switch(input[i]) {
                case '+': operands.push(op2 + op1); break;
                case '-': operands.push(op2 - op1); break;
                case '*': operands.push(op2 * op1);break;
                case '/': operands.push(op2 / op1); break;
            }
        };
    };
    if (operands.size() == 1) {
        std::cout << operands.top();
        operands.pop();
    } else
        RPN::InvalidExpression();
};

/*
    AV PARSING
        - Too few arguments for operation ( 8 + )
            needing ar least two operands for any
            operation
                - not having enough operands
                to perform the operation results in error
        - Too Many operands left in stack ( 8 9 + 7 )
            If theres more than one operand left on stack
            expreession incorrect
        - Division by Zero (8 0 /)
            - Attempting to divide by zero should result in an error
        - Invalid characters (a b +)
            - The expression should contain only digits (0-9) and 
            valid operators (+, -, *, /) and pther character should 
            result in an error
        - Empty input ()
        - Consecutive operators without sufficient operands in stack
        ( 8 + - )
        - Leading or trailing spaces (8 9 +)
        -single number input (5)
*/

/*

    - Program takes an inverted pplish mathemetical expression as argument
    - The numbers used in operation and passed as arguments
    are always less than 10
        The calculation itself but also the result do not
    - Program must process this expression and output the correct result on
    std out
    - error occurs during the execution of the program an error message should be displayed 
    in cerr
    - program handles ops +-
    - No brackets or decimals handling

    - Penultimate (operation) last

*/
