#include "easyfind.hpp"

int main() {

    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    
    try {
        easyfind(vec1, 4);
    } catch (std::exception &e) {
        std::cerr << "vector: " << e.what() << std::endl;
    }
}
    