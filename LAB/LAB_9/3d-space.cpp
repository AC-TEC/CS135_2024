/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 9
DATE: 3/8/2024

Task A: write a program that receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P:

Task B: write a program Which receives the coordinates of two points (passed as pointers), and returns the pointer of the point that is farther away from the origin.

Task C: write a program 
*/

#include <iostream>
#include <cmath>

class Coord3D {
public:
    double x;
    double y;
    double z;
};

//*TASK A
double length(Coord3D *p){
    //returns length of origin to point p using the euclidean distance formula: sqrt(x^2+y^2+z^2)
    // "->" to directly access member in class through a pointer 
    return sqrt(pow(p->x,2) + pow(p->y,2) + pow(p->z,2));
}


//*TASK B
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    //calculate the distance of each point
    double distance1 = length(p1);
    double distance2 = length(p2);

    //compare distance and returns the furthest point
    if(distance1 > distance2){
        return p1;
    }else{
        return p2;
    }
}


//*TASK C
void move(Coord3D *ppos, Coord3D *pvel, double dt){

}

int main() {
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    std::cout << "Address of P: " << &pointP << std::endl;
    std::cout << "Address of Q: " << &pointQ << std::endl << std::endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);

    //prints out the address
    std::cout << "ans = " << ans << std::endl; // So which point is farther?
}



/*

TASK A MAIN FUNCTION

int main() {
    Coord3D pointP = {10, 20, 30};
    std::cout << length(&pointP) << std::endl; // would print 37.4166
}

*/



/*

TASK B MAIN FUNCTION

int main() {
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    std::cout << "Address of P: " << &pointP << std::endl;
    std::cout << "Address of Q: " << &pointQ << std::endl << std::endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);

    //prints out the address
    std::cout << "ans = " << ans << std::endl; // So which point is farther?
}

*/