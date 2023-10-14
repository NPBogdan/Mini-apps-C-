#include "car.h"
#include <string>
#include <memory>

Car::Car(std::string paint, std::string brand, std::string model, int miles){
    _fuel = 12.0;
    _odometer = miles;
    _paintColor = paint;
    _upgradeCodes = new std::vector<int>();
    _upgradeCodes->push_back(1);
    _model = model;
    _brand = brand;
}

Car::Car(){
    _fuel = 0;
    _odometer = 0;
    _upgradeCodes = new std::vector<int>();
    _upgradeCodes->push_back(1);
    _paintColor = "White";
    _model = "";
    _brand = "Random";
}

//SPECIAL COPY CONSTRUCTOR
Car::Car(Car &obj){
    _fuel = obj._fuel;
    _odometer = obj._odometer;
    _paintColor = obj._paintColor; 
    _brand = obj._brand;
    _model = obj._model;
    _upgradeCodes = new std::vector<int>();
    for(int i = 0; i < obj._upgradeCodes->size(); i++){
        auto temp = *(obj._upgradeCodes); //Automatically detect the type,so here it is integer
          _upgradeCodes->push_back(temp[i]);
    }
}

//Assignment Operator
Car &Car::operator=(const Car &obj){
    this->_fuel = obj._fuel;
    this->_odometer = obj._odometer;
    this->_paintColor = obj._paintColor; 
    this->_brand = obj._brand;
    this->_model = obj._model;
    this->_upgradeCodes->clear();
    for(int i = 0; i < obj._upgradeCodes->size(); i++){
        auto temp = *(obj._upgradeCodes); //Automatically detect the type,so here it is integer
          _upgradeCodes->push_back(temp[i]);
    }

    return *this;
}

//Addition operator
Car Car::operator+(const Car &obj){
    std::unique_ptr<Car> newCar(new Car);
    if((this->_model == obj._model) && (this->_brand == obj._brand)){
        if(obj._upgradeCodes->size() > this->_upgradeCodes->size()){
            *newCar = obj;
            return *newCar;
        }
            
    }
       
    return *this;
}

//Subtraction operator
Car Car::operator-(const Car &obj){
    std::unique_ptr<Car> newCar(new Car);
    if((this->_model == obj._model) && (this->_brand == obj._brand)){
        if(obj._upgradeCodes->size() < this->_upgradeCodes->size()){
            *newCar = obj;
            return *newCar;
        }
    }
       
    return *this;
}


//Equality operator
bool Car::operator==(const Car &obj){
    bool theSame = false;
    if((_model == obj._model) && (_brand == obj._brand) && (_paintColor == obj._paintColor) && (_upgradeCodes->size() == obj._upgradeCodes->size())){
        for(int i = 0; i < this->_upgradeCodes->size(); i++){
            int code = (*_upgradeCodes)[i];
            theSame = false;
            for(int j = 0; j < obj._upgradeCodes->size(); i++){
                if((*obj._upgradeCodes)[i] == code){
                    theSame = true;
                }
            }
            if(!theSame){
                return false;
            }
        }
        return true;
    }
    return false;
}

//Output operator
std::ostream &operator<<(std::ostream &outs, const Car &obj){
    outs << "CAR INFO:" <<std::endl;
    outs << "Brand: " << obj._brand << std::endl;
    outs << "Model: " << obj._model << std::endl;
    outs << "Color: " << obj._paintColor << std::endl;

    return outs;
}
//Input operator
std::istream &operator>>(std::istream &ins, Car &obj){
    ins >> obj._brand;
    ins >> obj._model;
    ins >> obj._paintColor;

    return ins;
}


void Car::driveCar(int miles){
    _odometer += miles;
    _fuel -= miles/ 22;
}

std::string Car::getPaint(){
    return _paintColor;
}

std::string Car::getModel(){
    return _model;
}

std::string Car::getBrand(){
    return _brand;
}

void Car::setPaint(std::string color){
    _paintColor = color;
}

int Car::getOdometer(){
    return _odometer;
}

float Car::getFuel(){
    return _fuel;
}

void Car::addFuel(int gallons){
    _fuel += gallons;
}

void Car::showUpgrades(){
    for(auto i : *_upgradeCodes){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void Car::addUpgrade(int code){
    _upgradeCodes->push_back(code); 
}