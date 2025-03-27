#pragma once

#include <deque>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <time.h>

/*
     - Program use a positive integer sequence as an argument
     - program must use the merge insert sort algo to sort thr positive
     integer sequence
*/

/*
    - The ford johnson algo adapdative sorting technique 
    minimizing comparisons
    - break the list into smaller groups
        sort them recursively and merge them efficiently
*/

/*
    - Sort the larger elements so they form a 
        sorted sequence
        - This sorted sequence with act as the
        foundation
        of the final sorted list (=== Main Chain ===)
*/

/*

    since larger elements are already sorted 
    we will now insert smaller elements
    (pend vector) into correct position
    -> Main chain (sorted larger elements)
    -> pend elements 
    the missing pieces that need to be inserted in order 

*/

class Pmerge {
    public:
        Pmerge();
        ~Pmerge();
        Pmerge(const Pmerge &rhs);
        Pmerge & operator=(const Pmerge &rhs);
        static bool isPositiveNumber(const std::string& );
        static void parseAndValidateInput(const std::string& input, std::vector<unsigned int>&);
        static std::vector<std::string> splitString(const std::string& );
        static void earlyValidation(int, char **, std::vector<unsigned int>&);

        static std::vector<unsigned int> startVectorSort(std::vector<unsigned int>&);
        static std::deque<unsigned int> startDequeSort(std::deque<unsigned int>&);
        
        static void sortPairs(std::vector<unsigned int>&);
        static void sortPairs(std::deque<unsigned int>&);
        
        static void startPairing(std::vector<unsigned int> &, std::vector<unsigned int>&, std::vector<unsigned int>&);
        static void startPairing(std::deque<unsigned int> &, std::deque<unsigned int>&, std::deque<unsigned int>&);
        
        static void mergeSort(std::vector<unsigned int>&, int , int );
        static void mergeSort(std::deque<unsigned int>&, int , int );

        static void merge(std::vector<unsigned int>&, int , int , int );
        static void merge(std::deque<unsigned int>&, int, int, int );

        static std::vector<size_t> generateJacobsthalSequenceVector(size_t);
        static std::deque<size_t> generateJacobsthalSequenceDeque(size_t);

        static int binarySearchInsertPosition(const std::vector<unsigned int>& , unsigned int );
        static int binarySearchInsertPosition(const std::deque<unsigned int>& , unsigned int );

        static void insertElement(std::vector<unsigned int>& , std::vector<unsigned int>& , size_t );
        static void insertElement(std::deque<unsigned int>& , std::deque<unsigned int>& , size_t );

        static void insertRemainingElements(std::vector<unsigned int>& , std::vector<unsigned int>& );
        static void insertRemainingElements(std::deque<unsigned int>& , std::deque<unsigned int>& );

        static void binInsertSort(std::vector<unsigned int>& , std::vector<unsigned int>&);
        static void binInsertSort(std::deque<unsigned int>& , std::deque<unsigned int>& );

        static void printContainer(std::vector<unsigned int>&);
        static void printContainer(std::deque<unsigned int>&);

        class IncorrectArgs : public std::exception {
            const char * what() const throw();
        };
};
