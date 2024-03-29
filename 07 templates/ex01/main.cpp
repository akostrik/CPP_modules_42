#include "iter.hpp"
#define N 5

// an instantiated function template
template <typename T> void myPrint(T &elt) {
    std::cout << elt << std::endl;
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "arr1: " << std::endl;
    iter(arr1, N, &myPrint<int>);

    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "\narr2: " << std::endl;
    iter(arr2, N, &myPrint<double>);

    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "\narr3: " << std::endl;
    iter(arr3, N, &myPrint<char>);

    std::string arr4[] = {"one", "two", "three", "four", "five"};
    std::cout << "\narr4: " << std::endl;
    iter(arr4, N, &myPrint<std::string>);

    return 0;
}

