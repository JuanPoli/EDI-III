//
//  main.cpp
//  SingleResponsibilityEDI-III
//
//  Created by Juan Cruz Poli on 27/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <iostream>
#include "src/Car.cpp"
#include "src/DatabaseCar.cpp"
#include "include/Smart_pointer.h"

int main(int argc, const char * argv[]) {
    
    Smart_ptr<ICar> car (new Car("Chevrolet"));
    
    Smart_ptr<IDatabaseCar> databaseCar (new DatabaseCar(&*car));
    
    databaseCar->saveCarDB();
    databaseCar->deleteCarDB();
    
    return 0;
}
