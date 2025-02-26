#pragma once

#include <iostream>

struct Data {
    std::string login;
    double xp;
};

class Serializer {
    private:
        virtual uintptr_t serialize(Data * ptr);
        Serializer();
        ~Serializer();
        Serializer(const Serializer &rhs);
        Serializer &operator=(Serializer &rhs);

};