#ifndef SEDAN_H
#define SEDAN_H

#include "Car.h"

class Sedan : public Car {
    public:
        Sedan();
        ~Sedan();
        friend std::ostream &operator<<(std::ostream &outs, const Sedan &s);
        int getNumDoors();
        void setNumDoors(int numDoors);
        bool getIsCompact();
        void setIsCompact(bool isCompact);
    private:
    int _numDoors;
    bool _isCompact;
};

#endif