#include "RPN.hpp"

int main(int ac, char **av) {
    try {
        RPN::earlyValidation(ac, av);
        RPN::startCalc(RPN::rpnInput);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
    return 0;
}