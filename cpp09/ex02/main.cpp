#include "Pmerge.hpp"

int main(int ac, char **av) {
    try {
        std::vector<int> integers;
        Pmerge::earlyValidation(ac, av, integers);
        Pmerge::printVector(integers);
        // Pmerge::startSort();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
    return 0;
}