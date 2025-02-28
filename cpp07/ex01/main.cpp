#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3};
    iter(arr, 4, display);
    
    char strs[3][7] = {"Vis", "Et", "Honor"};
    iter(strs, 3, display);
    return 0;
}