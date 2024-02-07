/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 4
DATE: 2/6/2024

Task F: Print an upside down trapezoid using given width and height.
        If height is impossibly large for given width then print "IMPOSSIBLE SHAPE"
*/

#include <iostream>

int main(){
    int width;
    int height;

    //get user input
    std::cout << "Input width: ";
    std::cin >> width;
    std::cout << "Input height: ";
    std::cin >> height;

    //separation line between inputs and outputs
    std::cout << std::endl;
    std::cout << "Shape:" << std::endl;

    //counter to keep track of the stars and spaces
    int spaces = 0;
    int stars = width; 

    //check if shape is possible or not possible
    //so if height is > than half of the base width+1 [+1 = account for extra row] its an impossible shape
    if(height > (width+1)/2){
        std::cout << "Impossible shape!" << std::endl;
        return 1;
    } 

    //iterate through rows
    for(int row = 0; row < height; row++){
        //iterate through column (spaces)
        for(int col = 0; col < spaces; col++){
                std::cout << " ";
        }
        
        //iterate through column (stars)
        for(int col = 0; col < stars; col++){
            std::cout << "*";
        }

        //move to next row(line)
        std::cout << std::endl;

        //update increments
        spaces += 1;
        stars -= 2;
    }

    return 0;
}
