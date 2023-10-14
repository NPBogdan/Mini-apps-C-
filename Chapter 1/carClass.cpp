#include <string>
#include <iostream>

class Car {
    //member functions
    public:
        Car(std::string paint, std::string brand, std::string model, int miles); // EMPTY DEFAULT CONSTRUCTOR OR SETTING SOME ARGUMENTS
        void driveCar(int miles);
        void setPaint(std::string color);
        std::string getPaint();
        std::string getBrand();
        std::string getModel();
        int getOdometer();
        float getFuel();
        void addFuel(int gallons);
    //member variables
    private:
        float _fuel;
        std::string _paintColor;
        std::string _brand;
        std::string _model;
        int _odometer;
};

Car::Car(std::string paint, std::string brand, std::string model, int miles){
    _fuel = 12.0;
    _odometer = miles;
    _paintColor = paint;
    _model = model;
    _brand = brand;
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

int main(){
    Car car("blue","Toyota","Corola",20000); 
    std::cout << car.getOdometer() << std::endl;
    std::cout << car.getFuel() << std::endl;
    std::cout << car.getPaint() << std::endl;
    std::cout << car.getModel() << std::endl;
    std::cout << car.getBrand() << std::endl;
    car.setPaint("Black");
    std::cout << car.getPaint() << std::endl;

    return 0;
}