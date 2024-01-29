/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 2
DATE: 1/29/2024

Task B: ask user to input two integers and print out all integers in the range.
    excluding the upper limit interval
*/

#include <iostream>

int main(){
    int lower_limit;
    int upper_limit;

    //get user input
    std::cout << "Please enter L: ";
    std::cin >> lower_limit;
    std::cout << "Please enter U: ";
    std::cin >> upper_limit;

    //itertate and print numbers in range
    for (int i = lower_limit; i < upper_limit; i++){
        std::cout << i << " ";
    }

    return 0;
}