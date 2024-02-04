/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 4
DATE: 2/4/2024

Task B: print a rectangular checkerboard using asterisks and spaces from user input
*/

#include <iostream>

int main(){
    int width;
    int height;

    //get user input
    std::cout << "Input width: ";
    std::cin>> width;
    std::cout << "Input heigth: ";
    std::cin >> height;

    //separation line between inputs and output
    std::cout << std::endl;
    std::cout << "Shape:" << std::endl;
    

    //iterate through each row of checkerboard
    for(int row = 0; row < height; row++){
        //iterate through each column
        for(int col = 0; col < width; col++){
            //check if the sum of the row and column indices is even or odd
            if((row+col) % 2 == 0){
                std::cout << "*"; //when sum is even 
            } else {
                std::cout << " "; //when sum is odd
            }
        }
        std::cout << std::endl; //move to next row
    }

    return 0;
}