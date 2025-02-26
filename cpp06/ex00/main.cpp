#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2)
            throw std::invalid_argument("Wrong N Of Args !");
    std::string input = av[1];
    ScalarConverter::convert(input);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}

/*

    Floating point precesion: 
        A float has 7 significant digits of precision so it cannot accurately represent 
        a high precision number . It rounds tot eh closest representable number
        making it a fundamental limitation of floats

*/
