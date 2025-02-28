#include <cassert>
#include <iostream>

#include "DynamicMemory.h"

// BEGIN: 1a
void fillInFibonacciNumbers(int* result, int length){
    assert(length>0);
    result[0] = 0;
    result[1] = 1; 
    for(int i = 2; i < length; i++){
        result[i] = result[i-1] + result[i-2];
    }
}
// END: 1a

// BEGIN: 1b
void printArray(int* array, int length){
    for(int i = 0; i < length; i++){
        std::cout << array[i] << std::endl;
    }
    std::cout << std::endl;
}
// END: 1b

// BEGIN: 1c
void createFibonacci(){
    int antall;
    assert(antall > 0);
    std::cout << "Hvor mange tall skal genereres" << std::endl;
    std::cin >> antall;

    int* arr = new int[antall];

    fillInFibonacciNumbers(arr, antall);

    printArray(arr, antall);

    delete[] arr;
}
// END: 1c