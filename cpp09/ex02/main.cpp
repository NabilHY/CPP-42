#include "Pmerge.hpp"

int main(int ac, char **av) {
    try {

        std::vector<unsigned int> integersVector;
        Pmerge::earlyValidation(ac, av, integersVector);


        /* Start Count */
        clock_t start = clock();
        std::cout << "Before: ";
        Pmerge::printContainer(integersVector);
        std::vector<unsigned int> sortedIntegersVector = Pmerge::startVectorSort(integersVector);
        clock_t end = clock();
        double time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << integersVector.size() << "elements with std::vector : " << std::fixed << time_taken << std::endl;

        std::deque<unsigned int> integersDeque(integersVector.begin(), integersVector.end());

        /* Start Count */
        start = clock();
        std::deque<unsigned int> sortedIntegersDeque = Pmerge::startDequeSort(integersDeque);
        end = clock();
        time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << integersDeque.size() << "elements with std::deque : " << std::fixed << time_taken << std::endl;


        std::cout << "After: ";
        Pmerge::printContainer(sortedIntegersVector);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
} 