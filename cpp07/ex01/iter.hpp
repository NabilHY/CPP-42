#include <iostream>
#include <stdexcept>

template<typename T>
void    display(T arr) {
    std::cout << arr << " ";
}

template<typename T1>
void    iter(T1* addr, int len, void (* f)(T1)) {
    try {
        if (len <= 0 || addr == NULL)
            throw std::invalid_argument("");
        for (int i = 0; i < len; i++) {
            f(addr[i]);
        };
    } catch (std::exception &e) {
        std::cerr << "Invalid Array!\n";
    }
};
