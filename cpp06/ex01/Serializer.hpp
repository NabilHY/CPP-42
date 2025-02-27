#pragma once

#include <iostream>
#include <cstdint>

struct Data {
    std::string login;
    double xp;
};

class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &rhs);
        Serializer &operator=(Serializer &rhs);
    public:
        static uintptr_t serialize(Data * ptr);
        static Data *deserialize(uintptr_t raw);
};