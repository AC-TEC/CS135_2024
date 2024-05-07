#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <iostream>

class Sphere{

//(1) Data member is Radius which may conatin decimal numbers

private:
    double radius;


public:

    //(2) default contructor
    Sphere();

    //(3) non-default constructor takes in parameter radius
    Sphere(double r);

    //(4) define setRadius function to set the radius taking in parameter radius
    void setRadius(double r);

    //(5) define getRadius function to get the radius data member
    double getRadius();

    //(6) define getVolume function to get the volume of sphere. Formula: (4/3)pi*r^3
    //can use M_PI in the cmath library to use pi
    double getVolume();


};








#endif