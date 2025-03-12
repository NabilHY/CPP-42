#include "Span.hpp"

Span::Span(size_t n) {
    max_size = n;
    vec = std::vector<int> ();
}

Span::~Span() {};

Span::Span(const Span & rhs) {
    max_size = rhs.max_size;
    vec = std::vector<int> (rhs.vec);
};

Span    &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        max_size = rhs.max_size;
        vec =  std::vector<int> (rhs.vec);
    }
    return *this;
}

void    Span::addNumber(int toAdd) {
    if (getMax() == this->getRef().size()) {
        throw Span::ExceedSize();
    }
    vec.push_back(toAdd);
}


int     Span::shortestSpan() const  {
    if (vec.size() < 2) {
        throw Span::VecEmpty();
    };
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    int min_span = INT_MAX;
    for (size_t i = 1; i < sortedVec.size(); ++i) {
        int currentSpan = sortedVec[i] - sortedVec[i - 1];
        if (currentSpan < min_span) {
            min_span = currentSpan;
        }
    }
    return min_span;
}

int     Span::longestSpan() const {
    if (vec.size() < 2) {
        throw Span::VecEmpty();
    };
    std::vector<int>::const_iterator it;
    int min = INT_MAX;
    int max = INT_MIN;

    for (it = vec.begin(); it != vec.end(); ++it) {
        if (*it < min)
            min = *it;
        if (*it > max)
            max = *it;
    }
    return (max - min);
}

const char *    Span::ExceedSize::what() const throw () {
    return "Span at Max Capacity!";
};

const char *    Span::VecEmpty::what() const throw() {
    return "Vector has little to no elements.";
}