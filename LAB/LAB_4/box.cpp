/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 4
DATE: 2/4/2024

Task A: Print a rectangular box shape using user input for width and height 
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
    
    //separation line between inputs and output
    std::cout << std::endl;
    std::cout << "Shape:" << std::endl;
    
    //iterate through each row of the rectangle
    for (int i = 0; i < height; i++){
        for (int i =0; i < width; i++){
            std::cout << "*"; //print an asterisk for each column in the current row
        }
        std::cout << std::endl; //move to next row after iteration
    }

    return 0;
}