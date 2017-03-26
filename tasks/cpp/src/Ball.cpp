#include <iostream>
#include <cmath>
#include "../include/Ball.h"

Ball::Ball(void){
    this->name = "\0";
    this->radius = 0;
    this->isHollow = false;
}

Ball::Ball(std::string name = "No name", double radius = 0, bool isHollow = false){
    this->name = name;
    this->radius = radius;
    this->isHollow = isHollow;
}


double Ball::getVolume(void){
    double pi = 3.14159;
    double rad = this->radius;
    double volume = 4/3 * pi * pow(rad, 3);

    return volume;
}

void Ball::toString(void){
    std::cout << "name: " << this->name << ", ";
    std::cout << "radius: " << this->radius << ", ";
    std::cout << "isHollow: " << this->isHollow << std::endl;
}