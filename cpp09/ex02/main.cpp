#include "Pmerge.hpp"

void processTime(double timeTaken, size_t size, bool isVector) {
    std::cout << "Time to process a range of " << size << " elements with " << (isVector ? "std::vector: " : "std::deque: " ) << std::fixed << timeTaken << " us" << std::endl;
}

int main(int ac, char **av) {
    try {

        std::vector<unsigned int> integersVector;
        Pmerge::earlyValidation(ac, av, integersVector);
        if (integersVector.size() == 1)
            throw Pmerge::IncorrectArgs();
        std::vector<unsigned int> unsortedVector(integersVector.begin(), integersVector.end());
        std::deque<unsigned int> integersDeque(integersVector.begin(), integersVector.end());
        
        /* Start Count */
        clock_t vectorStart = clock();
        std::vector<unsigned int> sortedIntegersVector = Pmerge::startVectorSort(integersVector);
        clock_t vectorEnd = clock();
        
        /* Start Count */
        clock_t dequeStart = clock();
        std::deque<unsigned int> sortedIntegersDeque = Pmerge::startDequeSort(integersDeque);
        clock_t dequeEnd = clock();
        
        
        std::cout << "Before: ";
        Pmerge::printContainer(unsortedVector);
        std::cout << "After: ";
        Pmerge::printContainer(sortedIntegersVector);
        processTime((double)(vectorEnd - vectorStart) / CLOCKS_PER_SEC, integersVector.size(), true);
        processTime((double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC, integersVector.size(), false);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
} 