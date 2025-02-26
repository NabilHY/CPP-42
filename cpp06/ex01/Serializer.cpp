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
