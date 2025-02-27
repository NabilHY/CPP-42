#include "Base.hpp"

int main() {

    Base *baseClass = generate();
    
    Base &ref = *baseClass;
    
    identify(baseClass);
    
    identify(ref);
    
    delete baseClass;
}