/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 2
DATE: 1/29/2024

Task A: get an integer that is greater than 0 & less than 100 & print this number squared. If integer not in range ask user to re-enter 
    until we get a valid input
*/

#include <iostream>
#include <cmath>


int main(){
    int num;

    //get user input
    std::cout << "Enter an integer: ";
    std::cin >> num;

    //determine if input is in range
    //(when not in range)
    while (num <= 0 || num >= 100){
        std::cout << "Please re-enter: ";
        std::cin >> num;
    } 

    //calculate number squared
    //(when number is greater than 0 and less than 100)
    int num_squared = pow(num,2);
    
    //print out number squared
    std::cout << "Number squared is " << num_squared << std::endl;

    return 0;
}