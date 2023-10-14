#include <iostream>
#include <string>

#ifndef CAR_H
#define CAR_H

class Car {
    public:
        Car();
        ~Car();
        
        int showFuel();
        void setFuel(int fuel);
        void setOdometer(float kilo);
        float getOdometer();
        void setPaint(std::string color);
        std::string getPaint();

    protected:
        int _fuel;
        std::string _paintColor;
        float _mileage;
};



#endif