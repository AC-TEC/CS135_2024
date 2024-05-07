#include "Sphere.hpp"
#include <cmath> //for pow() and M_PI (for pi)



//defalut constructor
//set radius to 1
Sphere::Sphere(){
    radius = 1;
}


//non-default contructor
//if param value is positive set radius tp param value else set to 1
Sphere::Sphere(double r){
    if(r > 0){
        radius = r;
    }else{
        radius = 1;
    }
}


void Sphere::setRadius(double r){
    //if positive change radius to param value. Otherwise do nothing
    if(r > 0){
        radius = r;
    }
}


//get radius
double Sphere::getRadius(){
    return radius;
}


//gets volume of sphere using given formula
double Sphere::getVolume(){
    //use formula to get volume of sphere
    return (4/3) * M_PI * std::pow(radius,3);
}

