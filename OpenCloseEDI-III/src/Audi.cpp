//
//  Audi.cpp
//  OpenCloseEDI-III
//
//  Created by Juan Cruz Poli on 28/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "../include/ICar.h"

class Audi: public ICar {
public:
    
    Audi():averagePrice(25000){
        
    }
    
    virtual ~Audi(){
        
    }
    
    void carAveragePrice() {
        std::cout << "Audi Average price: $" << averagePrice << std::endl;
    }
    
private:
    int averagePrice;
};
