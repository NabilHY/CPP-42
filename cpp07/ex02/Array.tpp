#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
Array<T>::Array() {
    this->array = new T[0]();
    this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->_size = n;
    this->array = new T[n]();
}

template <typename T>
Array<T>::Array(Array const &rhs) {
    this->array = new T[rhs._size]();
    this->_size = rhs._size;
    for (unsigned int i= 0; i < rhs._size; i++) {
        this->array[i] = rhs.array[i];
    }
}


template <typename T>
T*  Array<T>::getArray() const {
    return array;
};

template <typename T>
unsigned int    Array<T>::size() const {
    return _size;
};

//!
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if (this != &rhs) {
        delete[] array;    
        _size = rhs._size;
        array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            array[i] = rhs.array[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Invalid Index");
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Invalid Index");
    return array[index];
}

