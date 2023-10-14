#include <iostream>
#include "Truck.h"
#include "Sedan.h"
#include "SUV.h"

int main(){
    Truck Truck;
    Sedan Sedan;
    Suv Suv;

    Truck.setFuel(51);
    Truck.setPaint("Red");
    Truck.setBedLength(8);
    Truck.setIsFullCab(true);

    Sedan.setFuel(10);
    Sedan.setPaint("blue");
    Sedan.setNumDoors(4);

    Suv.setFuel(11);
    Suv.setPaint("black");
    Suv.setNumSeats(4);
    Suv.setIsAWD(true);

    std::cout << Truck << std::endl;
    std::cout << Sedan << std::endl;
    std::cout << Suv << std::endl;
    return 0;
}