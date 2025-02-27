#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Constructor" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Destructor" << std::endl;
}

Serializer::Serializer(const Serializer &rhs)
{
    (void)rhs;
    std::cout << "Copy constructor" << std::endl;
}

Serializer &Serializer::operator=(Serializer &rhs) {
    std::cout << "Copy assignment operator" << std::endl;
    return rhs;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
