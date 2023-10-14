#ifndef TRUCK_H
#define TRUCK_H

#include "Car.h"

class Truck : public Car{
    public:
        Truck();
        ~Truck();
        void setBedLength(int length);
        friend std::ostream &operator<<(std::ostream &outs, const Truck &t);
        int getBedLength();
        void setIsFullCab(bool cab);
        bool getIsFullCab();

    private:
        int _bedLength;
        bool _isFullCab;
};

#endif
