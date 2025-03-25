#include "Pmerge.hpp"

Pmerge::Pmerge() {}
// Pmerge::~Pmerge() {};
// Pmerge::Pmerge(const Pmerge &rhs) { *this = rhs; };
// Pmerge & Pmerge::operator=(const Pmerge &rhs) { (void)rhs; return *this; };

const char * Pmerge::IncorrectArgs::what() const throw() {
    return "Input error: Pmerge criteria not matched!";
}

/* Parsing Utilities */
std::vector<std::string> Pmerge::splitString(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);

    while (std::getline(tokenStream, token, ' ')) {
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}

bool Pmerge::isPositiveNumber(const std::string& str) {
    size_t i = 0;
    if (str.empty()) {
        return false;
    }
    if (str[0] == '+')
        i++;
    for (; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void Pmerge::parseAndValidateInput(const std::string& input, std::vector<unsigned int>& integers) {
    std::vector<std::string> args = splitString(input);

    if (args.empty()) {
        throw IncorrectArgs();
    }

    for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); ++it) {
        const std::string& arg = *it;
        if (!isPositiveNumber(arg)) {
            throw IncorrectArgs();
        }

        unsigned int number = static_cast<unsigned int>(std::atoi(arg.c_str()));
        integers.push_back(number);
    }
}

void Pmerge::earlyValidation(int ac, char **av, std::vector<unsigned int> &integers) {
    if (ac < 2) {
        throw Pmerge::IncorrectArgs();
    }
    std::string input;
    for (int i = 1; i < ac; i++) {
        input += av[i];
        if (i < ac - 1) {
            input += " ";
        }
    }

    parseAndValidateInput(input, integers);

    if (integers.empty()) {
        throw Pmerge::IncorrectArgs();
    }
}

/*****************************/


/* Container Print */
void Pmerge::printContainer(std::vector<unsigned int>& integers) {
    std::vector<unsigned int>::const_iterator it;

    for (it = integers.begin(); it != integers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void Pmerge::printContainer(std::deque<unsigned int>& integers) {
    std::deque<unsigned int>::const_iterator it;
    
    for (it = integers.begin(); it != integers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*****************************/

/*
    Sort pairs  of integers 
*/

void    Pmerge::sortPairs(std::vector<unsigned int> &integers){
    std::vector<unsigned int>::iterator it;

    for (it = integers.begin(); it < integers.end(); it += 2) {
        if (*it < *(it + 1)) {
            std::swap(*it, *(it + 1));
        };
    };
};

void    Pmerge::sortPairs(std::deque<unsigned int>& integers) {
    std::deque<unsigned int>::iterator it;

    for (it = integers.begin(); it < integers.end(); it += 2) {
        if (*it < *(it + 1)) {
            std::swap(*it, *(it + 1));
        };
    }
};

/*****************************/
/*
    Merge two sorted arrays
*/

void Pmerge::merge(std::vector<unsigned int>& vector, int l, int mid, int r) {
    std::vector<unsigned int> leftVec(vector.begin() + l, vector.begin() + mid + 1);
    std::vector<unsigned int> rightVec(vector.begin() + mid + 1, vector.begin() + r + 1);
    size_t i = 0, j = 0, k = l;
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) {
            vector[k] = leftVec[i++];
        } else {
            vector[k] = rightVec[j++];
        }
        k++;
    }
    while (i < leftVec.size()) {
        vector[k] = leftVec[i];
        i++; k++;
    }
    while (j < rightVec.size()) {
        vector[k] = rightVec[j];
        j++; k++;
    }
}

void Pmerge::merge(std::deque<unsigned int>& deque, int l, int mid, int r) {
    std::deque<unsigned int> leftVec(deque.begin() + l, deque.begin() + mid + 1);
    std::deque<unsigned int> rightVec(deque.begin() + mid + 1, deque.begin() + r + 1);
    size_t i = 0, j = 0, k = l;
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) {
            deque[k] = leftVec[i++];
        } else {
            deque[k] = rightVec[j++];
        }
        k++;
    }
    while (i < leftVec.size()) {
        deque[k] = leftVec[i];
        i++; k++;
    }
    while (j < rightVec.size()) {
        deque[k] = rightVec[j];
        j++; k++;
    }
}

/*****************************/

/*
    Merge Sort
*/

void    Pmerge::mergeSort(std::vector<unsigned int>&vector, int l, int r) {
    if (l >= r)  return;
    int mid = (r + l) / 2;
    Pmerge::mergeSort(vector, l, mid);
    Pmerge::mergeSort(vector, mid + 1, r);
    Pmerge::merge(vector, l, mid ,r);
}

void    Pmerge::mergeSort(std::deque<unsigned int>&deque, int l, int r) {
    if (l >= r)  return;
    int mid = (r + l) / 2;
    Pmerge::mergeSort(deque, l, mid);
    Pmerge::mergeSort(deque, mid + 1, r);
    Pmerge::merge(deque, l, mid ,r);
};

/*****************************/

/*
    Jacobsthal Sequence
*/

std::vector<size_t> Pmerge::generateJacobsthalSequenceVector(size_t limit) {
    std::vector<size_t> jacobsthal;
    if (limit >= 1) jacobsthal.push_back(0);
    if (limit >= 2) jacobsthal.push_back(1);

    for (size_t i = 2; ; i++) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next >= limit) break;
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

std::deque<size_t> Pmerge::generateJacobsthalSequenceDeque(size_t limit) {
    std::deque<size_t> jacobsthal;
    if (limit >= 1) jacobsthal.push_back(0);
    if (limit >= 2) jacobsthal.push_back(1);

    for (size_t i = 2; ; i++) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next >= limit) break;
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

/*****************************/

/*
    Binary Search Insert Position
*/

int Pmerge::binarySearchInsertPosition(const std::vector<unsigned int>& arr, unsigned int value) {
    int left = 0;
    int right = arr.size() - 1;
    int insertPos = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
            insertPos = left;
        } else {
            right = mid - 1;
        }
    }

    return insertPos;
}

int Pmerge::binarySearchInsertPosition(const std::deque<unsigned int>& arr, unsigned int value) {
    int left = 0;
    int right = arr.size() - 1;
    int insertPos = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value) {
            left = mid + 1;
            insertPos = left;
        } else {
            right = mid - 1;
        }
    }

    return insertPos;
}

/*****************************/

/*
    Insert element in main chain
    and remove from pend chain
*/

void Pmerge::insertElement(std::deque<unsigned int>& main, std::deque<unsigned int>& pend, size_t index) {
    unsigned int toInsert = pend[index];
    int insertPos = binarySearchInsertPosition(main, toInsert);
    main.insert(main.begin() + insertPos, toInsert);
    pend.erase(pend.begin() + index);
}

void Pmerge::insertElement(std::vector<unsigned int>& main, std::vector<unsigned int>& pend, size_t index) {
    unsigned int toInsert = pend[index];
    int insertPos = binarySearchInsertPosition(main, toInsert);
    main.insert(main.begin() + insertPos, toInsert);
    pend.erase(pend.begin() + index);
}

/*****************************/
/*
    Inserts remaining elements from pend vector
*/

void Pmerge::insertRemainingElements(std::vector<unsigned int>& main, std::vector<unsigned int>& pend) {
    while (!pend.empty()) {
        insertElement(main, pend, 0);
    }
}

void Pmerge::insertRemainingElements(std::deque<unsigned int>& main, std::deque<unsigned int>& pend) {
    while (!pend.empty()) {
        insertElement(main, pend, 0);
    }
}

/*****************************/

/*****************************/
/*
    Binary Insertion Sort : 
*/
void Pmerge::binInsertSort(std::vector<unsigned int>& main, std::vector<unsigned int>& pend) {
    std::vector<size_t> jacobsthal = generateJacobsthalSequenceVector(pend.size() + 1);

    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t index = jacobsthal[i];
        if (index >= pend.size()) continue;
        insertElement(main, pend, index);
    }
    insertRemainingElements(main, pend);
}

void Pmerge::binInsertSort(std::deque<unsigned int>& main, std::deque<unsigned int>& pend) {
    std::deque<size_t> jacobsthal = Pmerge::generateJacobsthalSequenceDeque(pend.size() + 1);

    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t index = jacobsthal[i];
        if (index >= pend.size()) continue;
        insertElement(main, pend, index);
    }
    insertRemainingElements(main, pend);
}
/*****************************/
/*
    Pairing of elements
*/

void Pmerge::startPairing(std::deque<unsigned int> &vec, std::deque<unsigned int>&l, std::deque<unsigned int>&s) {
    std::deque<unsigned int>::iterator it;

    for (it = vec.begin(); it < vec.end(); it += 2) {
        int first = *it;
        int second = *(it + 1);
        l.push_back(std::max(first, second));
        s.push_back(std::min(first, second));
    }
}

void    Pmerge::startPairing(std::vector<unsigned int> &vec, std::vector<unsigned int>&l, std::vector<unsigned int>&s) {
    
    std::vector<unsigned int>::iterator it;

    for (it = vec.begin(); it < vec.end(); it += 2){
        int first = *it;
        int second = *(it + 1);
        l.push_back(std::max(first, second));
        s.push_back(std::min(first, second));
    }
};


/*****************************/

std::vector<unsigned int> Pmerge::startVectorSort(std::vector<unsigned int>&integers) {
    int straggler = -1;
    if (integers.size() % 2 != 0)
    {
        straggler = integers.back();
        integers.pop_back();
    };
    std::vector<unsigned int> mainChain;
    std::vector<unsigned int> pendChain;

    Pmerge::sortPairs(integers);
    Pmerge::startPairing(integers, mainChain, pendChain);
    Pmerge::mergeSort(mainChain, 0, mainChain.size() - 1);
    if (mainChain.at(0) >= pendChain.at(0)) {
        mainChain.insert(mainChain.begin(), pendChain[0]);
        pendChain.erase(pendChain.begin());
    };
    Pmerge::binInsertSort(mainChain, pendChain);
    if (straggler != -1) {
        int insertPos = Pmerge::binarySearchInsertPosition(mainChain, static_cast<unsigned int>(straggler));
        mainChain.insert(mainChain.begin() + insertPos, straggler);
    }
    return mainChain;
}

std::deque<unsigned int> Pmerge::startDequeSort(std::deque<unsigned int> &integers) {
    int straggler = -1;

    if (integers.size() % 2 != 0)
    {
        straggler = integers.back();
        integers.pop_back();
    };

    std::deque<unsigned int> mainChain;
    std::deque<unsigned int> pendChain;

    Pmerge::sortPairs(integers);
    Pmerge::startPairing(integers, mainChain, pendChain);
    Pmerge::mergeSort(mainChain, 0, mainChain.size() - 1);
    if (mainChain.at(0) >= pendChain.at(0)) {
        mainChain.insert(mainChain.begin(), pendChain[0]);
        pendChain.erase(pendChain.begin());
    };
    Pmerge::binInsertSort(mainChain, pendChain);
    if (straggler != -1) {
        int insertPos = Pmerge::binarySearchInsertPosition(mainChain, static_cast<unsigned int>(straggler));
        mainChain.insert(mainChain.begin() + insertPos, straggler);
    }
    return (mainChain);
};
