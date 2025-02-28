#include "Array.hpp"

template <typename T>
void    fill(T* dataArr ,T data, unsigned int size) {
    for (unsigned int i = 0; i < size; i++)
        dataArr[i] = data;
}

int main() {
    /* Construction with no paramters */
    Array<int> arrayOfInts;

    fill(arrayOfInts.array, 10, arrayOfInts.size);
    /* Construction with uint */
    Array<double> arrayOfInts1(5);


    return 0;
}