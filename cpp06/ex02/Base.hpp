#pragma once

#include <ctime>

class Base {
    public:
        virtual ~Base();
};

Base*   generate(void);
void    identify(Base *);
void    identify(Base &);

class A : public Base {};
class B : public Base {};
class C : public Base {};