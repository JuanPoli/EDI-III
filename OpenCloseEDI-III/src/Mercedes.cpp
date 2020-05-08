//
//  Mercedes.cpp
//  OpenCloseEDI-III
//
//  Created by Juan Cruz Poli on 28/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <stdio.h>
#include "../include/ICar.h"
#include <iostream>


class Mercedes: public ICar {
public:
    
    Mercedes():averagePrice(27000){
        
    }
    
    virtual ~Mercedes(){
        
    }
    
    void carAveragePrice() {
        std::cout << "Mercedes Average price: $" << averagePrice << std::endl;
    }
    
private:
    int averagePrice;
};
