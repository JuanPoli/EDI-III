//
//  Renault.cpp
//  OpenCloseEDI-III
//
//  Created by Juan Cruz Poli on 28/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "../include/ICar.h"

class Renault: public ICar {
public:
    
    Renault():averagePrice(18000){
        
    }
    
    virtual ~Renault(){
        
    }
    
    void carAveragePrice() {
        std::cout << "Renault Average price: $" << averagePrice << std::endl;
    }
    
private:
    int averagePrice;
};
