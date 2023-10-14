#include "Car.h"
#include <string>


Car::Car(){
    std::cout << "We are in the Car constructor " << std::endl;
    _fuel = 0;
    _paintColor = "White";
    _mileage = 0.00;
    };

int Car::showFuel(){
    return _fuel;
}

void Car::setFuel(int fuel){
    _fuel = fuel;
}

void Car::setOdometer(float kilo){
    _mileage = kilo;
}

float Car::getOdometer(){
    return _mileage;
}

void Car::setPaint(std::string paint){
    _paintColor = paint;
}

std::string Car::getPaint(){
     return _paintColor ;
}

Car::~Car(){
    std::cout << "We are in Car destructor " << std::endl;
}