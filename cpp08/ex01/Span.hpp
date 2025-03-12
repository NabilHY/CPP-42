#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
    private:
        std::vector<int>   vec;
        size_t        max_size;
    public:
        Span(size_t);
        ~Span();
        Span(const Span &);
        Span &operator=(const Span &);
        void    addNumber(int);
        std::vector<int>&   getRef() { return vec; };
        unsigned int   getMax() { return max_size; };
        int     shortestSpan() const;      
        int     longestSpan() const;
        
        class ExceedSize : public std::exception {
            public:
                const char * what() const throw();
        };
        
        class VecEmpty : public std::exception {
            public:
                const char * what() const throw();
        };
};
