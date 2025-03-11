#include "Stopwatch.h"
#include <memory>
#include <array>
#include <iostream>


// BEGIN 1a

double measurePerformanceUnique(){
    Stopwatch s;
    int16_t iterations = 1000000;
    s.start();
    for (int i = 0; i < iterations; i++)
    {
        std::unique_ptr<int> ptr = std::make_unique<int>(5);
    }
    double dur = s.stop();
    return dur/iterations;
}

double measurePerformanceShared(){
    Stopwatch t;
    int16_t iterations = 1000000;
    t.start();
    for (int i = 0; i < iterations; i++)
    {
        std::shared_ptr<int> ptr = std::make_shared<int>(5);
    }
    double dur = t.stop();
    return dur/iterations;
}

double measurePerformanceStack(){
    Stopwatch o;
    int16_t iterations = 10000;
    o.start();
    for (int i = 0; i < iterations; i++)
    {
        constexpr int size = 10000;
        std::array<int, size> arr1;
    }
    double returnVal = o.stop();
    return returnVal/iterations;
}

double measurePerformanceHeap(){
    Stopwatch p;
    int16_t iterations = 10000;
    p.start();
    for (int i = 0; i < iterations; i++)
    {
        constexpr int size = 10000;
        std::array<int, size>* arr2 = new std::array<int, size>;    
        delete arr2;
    }
    double returnVal = p.stop();
    return returnVal/iterations;
}
// END 1a