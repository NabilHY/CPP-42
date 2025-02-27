#include "Serializer.hpp"

int main() {

    struct Data student;
    
    student.xp = 5.32;

    student.login = "johndoe";
    
    uintptr_t intAddress = Serializer::serialize(&student);
    
    Data *hexAddress = Serializer::deserialize(intAddress);
    
    std::cout << "Address returned from deserialize: " << hexAddress << std::endl;
    
    std::cout << "Original Pointer Address: " << &student << std::endl;
    
}