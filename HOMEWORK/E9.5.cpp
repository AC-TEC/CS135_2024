
/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW 

This program Implement a class Rectangle
*/

#include <iostream>

class Rectangle {
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double get_perimeter() const {
        return 2 * (width + height);
    }
    
    double get_area() const {
        return width * height;
    }
    
    void resize(double factor) {
        width *= factor;
        height *= factor;
    }
    
private:
    double width;
    double height;
};
