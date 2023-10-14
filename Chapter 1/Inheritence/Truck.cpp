#include <iostream>
#include <string>
#include "Truck.h"


Truck::Truck(){
    std::cout << "We are in the Truck constructor " << std::endl;
    _bedLength = 6;
    _isFullCab = false;

}

std::ostream &operator<<(std::ostream &outs, const Truck &t){
    outs << "TRUCK INFO: " << std::endl;
    outs << "Fuel: " << t._fuel << std::endl;
    outs << "Odometer: " << t._mileage << std::endl;
    outs << "Bed length: " << t._bedLength << std::endl;
    outs << "Has Full Cab? " << t._isFullCab << std::endl;
    std::cout << std::endl;
    return outs;
}

void Truck::setBedLength(int length){
    _bedLength = length;
}

int Truck::getBedLength(){
    return _bedLength;
}

void Truck::setIsFullCab(bool cab){
    _isFullCab = cab;
}

bool Truck::getIsFullCab(){
    return _isFullCab;
}

Truck::~Truck(){
    std::cout << "We are in Truck destructor " << std::endl;
}