/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 4
DATE: 2/5/2024

Task E: print top right half of a square, using user input length
*/

#include <iostream>

int main(){
    int length;

    //get user input
    std::cout << "Input side length: ";
    std::cin >> length;

    //separation line between inputs and outputs
    std::cout << std::endl;
    std::cout << "Shape:" << std::endl;

    //int length; (our height)
    int width = length; //column

    //itertate and print each row accordingly
    for(int row = 0; row < length; row++){
        //iterate though the column and print asterisks or spaces accordingly
        for(int col = 0; col < width; col++){
            if(col < row){
                std::cout << " ";
            } else {
                std::cout << "*";
            }
        }

        //move to next row(line)
        std::cout << std::endl;
    }

    return 0;
}