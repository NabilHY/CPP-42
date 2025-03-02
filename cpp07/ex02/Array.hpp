#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
    private:
        T *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int);
        Array(const Array<T>  &);
        ~Array();
        Array<T>& operator=(const Array<T>  &);
        T* getArray() const;
        unsigned int size() const;
        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
};

#include "Array.tpp"

/* Construction by copy and assignement operator
                modifying either the original array
                or its copy after copying must not affect the other array
 */

/* Must use the operator new[] to allocate memory, Preventive allocation 
(allocating in advance) is forbidden, program must never access non allocated memory */

/* Elements to be accessed through the subscript operator [] */

/* When accessing an element with the [] operator, if its index is out of bounds
an std::Exception is thrown */
 
/* A member function size()  that returns the num */