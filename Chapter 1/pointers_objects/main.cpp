#include <iostream>
#include "Car.h"
#include <memory>

int main(){
    Car *car = new Car("red","BMW","Seria3",178000);// BASIC POINTER
    Car car2("blue","Toyota","Corola",20000); 
    std::unique_ptr<Car> car3(new Car); // SMART POINTER
    Car car4 = *car;
    car4 = car2;
    Car car5("White","Ford","Fiesta",2000);
    std::cout << car2 << std::endl;
    car4.showUpgrades();
    car2.addUpgrade(20);
    car2.addUpgrade(40);
    car2.showUpgrades();
    car4 = car2+car4;
    std::cout<< "SHOWING CAR 4 UPGRADES BELOW" << std::endl;
    car4.showUpgrades();
    car5.addUpgrade(4);
    if(car5 == car2){
        std::cout << "CAR 4 AND CAR 2 ARE THE SAME" << std::endl;
    }
    else{
        std::cout << "THE CARS ARE NOT THE SAME" << std::endl;
    }
    car4 = car4-car5;
    std::cout<< "SHOWING CAR 4 UPGRADES BELOW" << std::endl;
    car4.showUpgrades();





    std::cout << "-----------------------------------------------" << std::endl;
    car4.addUpgrade(2);
    std::cout << "Car 4 model" << car4.getModel() << car4.getBrand() << std::endl;
    std::cout << car2.getOdometer() << std::endl;
    std::cout << car2.getFuel() << std::endl;
    std::cout << car2.getPaint() << std::endl;
    std::cout << car2.getModel() << std::endl;
    std::cout << car2.getBrand() << std::endl;
    car2.setPaint("Black");
    std::cout << car2.getPaint() << std::endl;
    std::cout << car3->getBrand() << std::endl;

    std::cout << "Input make/model/color for car: ";
    std::cin >> car2;
    std::cout << "New Car2 info below" << std::endl;
    std::cout << car2 << std::endl;
    delete car;
    return 0;
}