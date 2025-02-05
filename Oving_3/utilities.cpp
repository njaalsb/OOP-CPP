#include "utilities.h"
#include <random>

// BEGIN: 5a
int randomWithLimits(int lowerL, int upperL){
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(lowerL, upperL);
    int number = distribution(generator);
    return number;
// END: 5a
