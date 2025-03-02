#include "Array.hpp"
#include <cstdlib>
#include <unistd.h>

/*template <typename T>
void    fill(T* dataArr ,T data, unsigned int size) {
    for (unsigned int i = 0; i < size; i++)
        dataArr[i] = data;
}

template <typename T>
void printElements(T* arr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}*/


int main() {
    /* Construction with no parameters */
    Array<double> arrayOfDouble;

    /* Construction with uint */
    Array<double> arrayOfDouble1(5);
    // fill(arrayOfDouble1.getArray(), 10.0, arrayOfDouble1.size());
    // printElements(arrayOfDouble1.getArray(), arrayOfDouble1.size());

    /* copy constructor */
    Array<double> arrayOfDouble2(arrayOfDouble1);
    // printElements(arrayOfDouble2.getArray(), arrayOfDouble2.size());
    
    /* copy assig */
    arrayOfDouble = arrayOfDouble2;
    // printElements(arrayOfDouble.getArray(), arrayOfDouble.size());
    try {
        std::cout << arrayOfDouble[1] << std::endl;
        arrayOfDouble[1] = 20;
        std::cout << arrayOfDouble[1] << std::endl;
        std::cout << arrayOfDouble[5] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught out_of_range exception: " << e.what() << std::endl;
    };
    return 0;
}