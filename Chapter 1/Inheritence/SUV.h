#ifndef SUV_H
#define SUV_H

#include "Car.h"

class Suv : public Car {
    public:
        Suv();
        ~Suv();
        friend std::ostream &operator<<(std::ostream &outs, const Suv &suv);
        int getNumSeats();
        void setNumSeats(int seats);
        bool getIsAWD();
        void setIsAWD(bool awd);
    private:
    int  _numSeats;
    bool _isAWD;
};

#endif