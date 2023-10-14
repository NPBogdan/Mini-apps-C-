#include <iostream>
#include <vector>
#include <string>


#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>


class Car {
    //member functions
    public:
        Car();
        Car(std::string paint, std::string brand, std::string model, int miles); // EMPTY DEFAULT CONSTRUCTOR OR SETTING SOME ARGUMENTS

        Car(Car &obj);   //COPY CONSTRUCTOR
        ~Car(){
            std::cout << "Am sters obiectul alocat stivei!" << std::endl;
        };
        
        
        Car &operator=(const Car &obj);
        Car operator+(const Car &obj);
        Car operator-(const Car &obj);
        bool operator==(const Car &obj);
        friend std::ostream &operator<<(std::ostream &outs, const Car &obj);
        friend std::istream &operator>>(std::istream &ins, Car &obj);


        void driveCar(int miles);
        void setPaint(std::string color);
        std::string getPaint();
        std::string getBrand();
        std::string getModel();
        void addUpgrade(int code);
        void showUpgrades();
        int getOdometer();
        float getFuel();
        void addFuel(int gallons);

    private:
        //private member functions
        bool search(int code);
        //private member variable
        float _fuel;
        std::vector<int> *_upgradeCodes;
        std::string _paintColor;
        std::string _brand;
        std::string _model;
        int _odometer;
};

#endif