//
//  ICar.h
//  SingleResponsibilityEDI-III
//
//  Created by Juan Cruz Poli on 27/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#ifndef ICar_h
#define ICar_h
#define interface struct
#include <iostream>

interface ICar {
    virtual std::string getCarBrand() = 0;
};

#endif /* ICar_h */
