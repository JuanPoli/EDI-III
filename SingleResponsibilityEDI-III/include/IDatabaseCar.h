//
//  IDatabaseCar.h
//  SingleResponsibilityEDI-III
//
//  Created by Juan Cruz Poli on 27/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#ifndef IDatabaseCar_h
#define IDatabaseCar_h
#define interface struct

interface IDatabaseCar {
    virtual void saveCarDB() = 0;
    virtual void deleteCarDB() = 0;
};

#endif /* IDatabaseCar_h */
