/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E3.5
DATE: 1/25/2024

Hw: Read 3 numbers and print whether the numbers are in increasing order, decreasing order or neither
*/


#include <iostream>

int main(){

    int num1;
    int num2;
    int num3;

    //get user input
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter third number: ";
    std::cin >> num3;

    //determine whether order is increasing,decreasing or neither
    if (num1 < num2 && num2 < num3){
        std::cout << "Increasing" << std::endl;
    } else if (num1 > num2 && num2 > num3){
        std::cout << "Decreasing" << std::endl;
    } else {
        std::cout << "Neither" << std::endl;
    }

//something 
    return 0;
}