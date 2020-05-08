//
//  DatabaseCar.cpp
//  SingleResponsibilityEDI-III
//
//  Created by Juan Cruz Poli on 27/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <stdio.h>
#include "../include/IDatabaseCar.h"
#include "../include/ICar.h"

class DatabaseCar: public IDatabaseCar {
public:
    
    DatabaseCar(ICar* car){
        std::cout << "DatabsaeCar::DatabaseCar" << std::endl;
        this->car = car;
    }
    
    virtual ~DatabaseCar(){
        std::cout << "DatabsaeCar::~DatabaseCar" << std::endl;
    }
    
    void saveCarDB(){
        std::cout << "Saving " << car->getCarBrand() << " car in database ..." << std::endl;
    }
    
    void deleteCarDB(){
        std::cout << "Deleting " << car->getCarBrand() << " car from database ..." << std::endl;
    }
    
private:
    ICar* car;
};
