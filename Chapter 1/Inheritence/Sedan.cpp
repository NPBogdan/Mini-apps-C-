#include <string>
#include "Sedan.h"

std::ostream &operator<<(std::ostream &outs, const Sedan &s){
    outs << "SEDAN INFO: " << std::endl;
    outs << "Fuel: " << s._fuel << std::endl;
    outs << "Odometer: " << s._mileage << std::endl;
    outs << "Num Doors: " << s._numDoors << std::endl;
    outs << "Is Compact " << s._isCompact << std::endl;
    std::cout << std::endl;
    return outs;
}

Sedan::Sedan(){
    std::cout << "We are in the Sedan constructor " << std::endl;
    _isCompact = false;
    _numDoors = 2;
}

int Sedan::getNumDoors(){
    return _numDoors;
}

void Sedan::setNumDoors(int doors){
    _numDoors = doors;
}

bool Sedan::getIsCompact(){
    return _isCompact;
}

void Sedan::setIsCompact(bool compact){
    _isCompact = compact;
}

Sedan::~Sedan(){
    std::cout << "We are in Sedan destructor " << std::endl;
}