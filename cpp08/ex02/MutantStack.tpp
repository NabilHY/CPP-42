#include "MutantStack.hpp"

template <typename T>
void    printStack(std::stack<T> &ref) {
    std::stack <int> tmpStack = ref;

    while (!tmpStack.empty()) {
        std::cout << tmpStack.top() << std::endl;
        tmpStack.pop();
    }
}

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        MutantStack() : std::stack<T>() {};
        typename Container::iterator begin() { return this->c.begin(); } ;
        typename Container::iterator end() { return this->c.end(); };

        typename Container::const_iterator begin() const { return this->c.begin(); };
        typename Container::const_iterator end() const { return this->c.end(); };
};

// this->c[0];