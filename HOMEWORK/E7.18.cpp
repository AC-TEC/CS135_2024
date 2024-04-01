/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.18
DATE: 4/1/2024

HW: Write a function that computes the perimeter of a Triangle. 
    Then reads the coordinates of the points, calls your function, and displays the result.

*/

#include <iostream>
#include <cmath>

struct Point{
    double x;
    double y;
};

struct Triangle{
    Point A;
    Point B;
    Point C;
};


//Computes the distance from a to b
double distance(Point a, Point b){
    //use Euclidean distance formula: sqrt( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
    double distance = sqrt(std::pow((b.x - a.x),2) + std::pow((b.y - a.y), 2));
    return distance;
}


//Compute perimeter of triangle
double perimeter(Triangle t){
    //distance A-B
    double AB = distance(t.A, t.B);
    //distance B-C
    double BC = distance(t.B, t.C);
    //distance C-A
    double CA = distance(t.C, t.A);

    //Add all 3 distances
    double perimeter = AB+BC+CA;

    //return the sum
    return perimeter;
}

int main(){
    double x;
    double y;

    //create 3 point objects
    Point A;
    Point B;
    Point C;

    //get user input for coordinates of each point
    //Point A
    std::cout << "Point A" << std::endl;
    std::cout << "Enter x: ";
    std::cin >> A.x;
    std::cout << "Enter y: ";
    std::cin >> A.y;

    std::cout << std::endl;

    //Point B
    std::cout << "Point B" << std::endl;
    std::cout << "Enter x: ";
    std::cin >> B.x;
    std::cout << "Enter y: ";
    std::cin >> B.y;

    std::cout << std::endl;

    //Point C
    std::cout << "Point C" << std::endl;
    std::cout << "Enter x: ";
    std::cin >> C.x;
    std::cout << "Enter y: ";
    std::cin >> C.y;

    //create Triangle object
    Triangle p = {A,B,C};

    std::cout << std::endl;

    //call function and print perimeter
    double perimeter_triangle = perimeter(p);
    std::cout << "TRIANGLE PERIMETER: " << perimeter_triangle << std::endl;
    return 0;
}