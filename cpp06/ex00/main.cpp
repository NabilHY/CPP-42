#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    try {
        if (ac != 2)
            throw std::invalid_argument("Wrong N Of Args !");
        ScalarConverter::convert(av[1]);
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}