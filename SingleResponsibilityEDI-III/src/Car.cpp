//
//  Car.cpp
//  SingleResponsibilityEDI-III
//
//  Created by Juan Cruz Poli on 27/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <stdio.h>
#include "../include/ICar.h"

class Car: public ICar {
public:
    
    Car(std::string brand) {
        std::cout << "Car::Car" << std::endl;
        this->brand = brand;
    }
    
    virtual ~Car(){
        std::cout << "Car::~Car" << std::endl;
    }
    
    std::string getCarBrand(){
        return brand;
    }
    
private:
    std::string brand;
};


