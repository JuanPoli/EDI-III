//
//  main.cpp
//  OpenCloseEDI-III
//
//  Created by Juan Cruz Poli on 28/04/2020.
//  Copyright © 2020 Juan Cruz Poli. All rights reserved.
//

#include <iostream>
#include "src/Renault.cpp"
#include "src/Mercedes.cpp"
#include "src/Audi.cpp"

int main(int argc, const char * argv[]) {
    
    ICar* renault = new Renault();
    ICar* audi = new Audi();
    ICar* mercedes = new Mercedes();
    
    renault->carAveragePrice();
    audi->carAveragePrice();
    mercedes->carAveragePrice();
    
    return 0;
}
