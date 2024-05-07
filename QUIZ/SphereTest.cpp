#include "Sphere.hpp"


int main(){

    //default object
    Sphere ball;

    //find out and print radius of the ball
    std::cout << "Default Radius: " << ball.getRadius() << std::endl;

    //non-default ball with radius of 2
    Sphere ball2(2);

    //Change non-default ball radius to 2.5
    ball2.setRadius(2.5);

    //find out and print radiys of ball2
    std::cout << "Non-default Volume: " << ball2.getVolume() << std::endl;

    return 0;

}