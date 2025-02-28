#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    this->array = new T[0]();
    this->size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->size = n;
    this->array = new T[n]();
    for (unsigned int i = 0; i < n; i++) {
        std::cout << this->array[i] << std::endl;
    }
}

template <typename T>
Array<T>::Array(Array const &rhs) {
    if (this != &rhs) {
        this->array = new T[this->size]();
        this->size = rhs.size;
        for (unsigned int = 0; i < rhs.size; i++) {
            this->array[i] = rhs.array[i];
        }
    }
    return *this;
}

template <typename T>
T*  Array::getArray() const {
    return array;
};
