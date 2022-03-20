#include <iostream>
#include <string>
#include "Damage.hpp"

Damage::Damage(double power){
    this->power = power;
}

// getter
double Damage::getPower(){
    return this->power;
}
