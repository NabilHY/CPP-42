#include "Span.hpp"

void    print(std::vector<int>& vec) {
    for (unsigned long i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    };
}

int main()
{
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Span sp2 = Span(10);
    try {
        sp2.addNumber(1);
        sp2.addNumber(100);
        sp2.addNumber(50);
        sp2.addNumber(75);
        sp2.addNumber(25);
        sp2.addNumber(10);
        sp2.addNumber(90);
        sp2.addNumber(60);
        sp2.addNumber(30);
        sp2.addNumber(40);
        std::cout << "Span 2 - Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Span 2 - Longest Span: " << sp2.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // print(sp.getRef());

    // std::cout << sp.getRef().size() << std::endl;

    return 0;
}

