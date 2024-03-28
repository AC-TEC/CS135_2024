/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 9
DATE: 3/28/2024

Task A: write a program that receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P:

Task B: write a program Which receives the coordinates of two points (passed as pointers), and returns the pointer of the point that is farther away from the origin.

Task C: write a program that gets the position and velocity of an object and then has to compute the objects new coordinates after the time interval, dt(distance traveled)

TASK E: write a program that dynamically creates and deletes coordinate objects
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
//p->x would access the value of the x member of the object pointed to by p
void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}


//*TASK D
//allocate memory and initialize
Coord3D * createCoord3D(double x, double y, double z){
    //dynamically create a Coord3D object
    Coord3D * new_object = new Coord3D();

    //initialize variables of new object
    new_object-> x = x;
    new_object-> y = y;
    new_object-> z = z;

    //return new object
    return new_object;
}

//free memory
void deleteCoord3D(Coord3D *p){
    //free dynamically allocated memory
    delete p;
}

int main() {
    double x;
    double y;
    double z;
    
    //create a position cordinate
    //get user input
    std::cout << "Enter position: ";
    std::cin >> x >> y >> z;
    //Call function to initialize public members and get a pointer to the object
    Coord3D *ppos = createCoord3D(x,y,z);


    //create a velocity coordinate
    //get user input
    std::cout << "Enter velocity: ";
    std::cin >> x >> y >> z;
    //call function to initialize public members and get a pointer to the object
    Coord3D *pvel = createCoord3D(x,y,z);

    //compute objects new coordinate after time interval(use our move function)
    move(ppos, pvel, 10.0);

    //print out new position
    std::cout << "Coordinates after 10 seconds: " << ppos-> x << " " << ppos->y << " " << ppos->z << std::endl;

    //free memory for position and velocity objects
    deleteCoord3D(ppos);
    deleteCoord3D(pvel);

    return 0;
}


/*

?TASK A MAIN FUNCTION

int main() {
    Coord3D pointP = {10, 20, 30};
    std::cout << length(&pointP) << std::endl; // would print 37.4166
}

*/



/*

?TASK B MAIN FUNCTION

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



/*


?TASK C MAIN FUNCTION

int main() {

    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    // prints: 2 -10 100.4

    return 0;
}

*/