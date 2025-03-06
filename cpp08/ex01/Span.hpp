#include <iostream>
#include <vector>
#include <stdexcept>

/*
    Span class
        - can store a max of N intergers
            n is an unsiged int variable (only param passed to const)
        - This class has function called add number
            - adds a single number to the span
            - will be used in order to fill it
        - Any attempt to add a new element
            if there are already N elements stored thtow an exception
        - Next omplement two member functions
            - shortestSpan()
            - logestSpan()
                they will respictively fund out the shortest span or the longest span
                    - distance between all the mebers stored and return it
                    - if not memebrs stored or only one 
                        - no span is found -- throw an exception
                        
            - fill the span using a range of iterators
                making thougsands class to addNumber()
                - Implmenet a memebr funciton to add many numbers to the span
                    in one call
*/

class Span {
    private:
        std::vector<int>*   vec;
        unsigned int        max_size;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &);
        Span &operator=(const Span &);
        void    addNumber();
        int     shortestSpan();      
        int     longestSpan();
        
        class ExceedSize : public std::exception {
            public:
                const char * what() const throw();
        };
        
        class NewElementException : public std::exception {
            const char * what() const throw();
        };
};
