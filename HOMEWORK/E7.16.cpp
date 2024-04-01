/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.16
DATE: 4/1/2024

HW: Define a Point struct then write function double distance(Point a, Point b) that computes the distance from a to b. 
    Then read the coordinates of the points, calls your function, and displays the result.
*/


#include <iostream>
#include <cmath>

struct Point{
    double x;
    double y;
};

//Computes the distance from a to b
double distance(Point a, Point b){
    //use Euclidean distance formula: sqrt( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )
    double distance = sqrt(std::pow((b.x - a.x),2) + std::pow((b.y - a.y), 2));
    return distance;
}


int main(){
    double x;
    double y;

    //create two point objects
    Point point_A;
    Point point_B;

    //get user input
    //Point A
    std::cout << "Point A" << std::endl;
    std::cout << "Enter x: ";
    std::cin >> point_A.x;
    std::cout << "Enter y: ";
    std::cin >> point_A.y;

    std::cout << std::endl;

    //Point B
    std::cout << "Point B" << std::endl;
    std::cout << "Enter x: ";
    std::cin >> point_B.x;
    std::cout << "Enter y: ";
    std::cin >> point_B.y;

    std::cout << std::endl;

    //call function and print results
    double compute_distance = distance(point_A, point_B);
    std::cout << "Distance from Point A to Point B: " << compute_distance << std::endl;

    return 0;
}