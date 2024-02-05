/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 4
DATE: 2/4/2024

Task C: ask user to input shape size and prints a diagonal cross
*/

#include <iostream>

int main(){

    int size;

    //ask for user input
    std::cout << "Input size: ";
    std::cin >> size; //technically the height

    //separation line between inputs and output
    std::cout << std::endl;
    std::cout << "Shape: " << std::endl;

    //int size; //height (row)
    int width = size;  //column

    //plan
    //print one side diagonally(left to right) other one anti diagonally so from (right to left) creating the cross
    
    //iterate through each row
    for(int row = 0; row < size; row++){
        //iterate through each column 
        for(int col = 0; col < width; col++){
            //print diagonal and anti diagonal
            if(col == row || col ==  width - row - 1){
                std::cout << "*";
            }else{
                std::cout << " ";
            }
        }
            //move to next row(line)
            std::cout << std::endl;
    }

    return 0;
}