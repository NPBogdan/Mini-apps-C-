#include <iostream>
#include <string>
#include "SUV.h"

std::ostream &operator<<(std::ostream &outs, const Suv &s){
    outs << "SUV INFO: " << std::endl;
    outs << "Fuel: " << s._fuel << std::endl;
    outs << "Odometer: " << s._mileage << std::endl;
    outs << "Num Seats: " << s._numSeats << std::endl;
    outs << "Is AWD " << s._isAWD<< std::endl;
    std::cout << std::endl;
    return outs;
}

Suv::Suv(){
    std::cout << "We are in the SUV constructor " << std::endl;
    _isAWD = false;
    _numSeats = 5;
}

int Suv::getNumSeats(){
    return _numSeats;
}

void Suv::setNumSeats(int seats){
    _numSeats = seats;
}

bool Suv::getIsAWD(){
    return _isAWD;
}

void Suv::setIsAWD(bool awd){
    _isAWD = awd;
}

Suv::~Suv(){
    std::cout << "We are in SUV destructor " << std::endl;
}