#include "Car.h"
#include <cassert>

// BEGIN 1b
Car::Car(int freeSeats) : freeSeats(freeSeats) {}
// END 1b

// BEGIN 1c
bool Car::hasFreeSeats() const{
    if (freeSeats > 0)
    {
        return true;
    } else {
        return false;
    }
}

void Car::reserveFreeSeat(){
    assert(freeSeats > 0);
    freeSeats--;
}
// END 1c