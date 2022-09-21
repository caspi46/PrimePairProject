//
//  main.cpp
//  PrimeProject
//
//  Created by Kenny Kim on 9/20/22.
//

#include "PrimeCalc.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    PrimeCalc ppCalculator = PrimeCalc();
    ppCalculator.setPrivates();
    ppCalculator.calc();
    ppCalculator.display();
}
