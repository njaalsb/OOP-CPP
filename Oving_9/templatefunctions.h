#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>

// BEGIN 4a
template<typename T> T maximum(T lhs, T rhs){
    if(lhs>rhs){
        return lhs;
    } else {
        return rhs;
    }
}
// END 4a

// BEGIN 4b

// END 4b

void testTemplateFunctions();