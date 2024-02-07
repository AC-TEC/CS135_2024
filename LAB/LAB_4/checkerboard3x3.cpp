/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 4
DATE: 2/6/2024

Task G: print a checkerboard of 3-by-3 squares using given width and height
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

    //loop begins
    //iterate through rows(height)
    for (int row = 0; row < height; row++ ){
        //iterate though columns(width)
        for (int col = 0; col < width; col++){
            //check if row and column are either both at an even or odd position when divided by 3 
            //if (row and column == even || row and column == odd)
            if ((row/3) % 2 == 0  && (col / 3) % 2 == 0 || ((row / 3) % 2 != 0 && (col / 3) % 2 != 0)){
                std::cout << "*";
            } else{
                std::cout << " ";
            }
        }
        //move to next row(line)
        std::cout << std::endl;
    }
    return 0;
}

