/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E3.1
DATE: 1/24/2024

read an integer and print whether it is negative, zero, or positive
*/

#include <iostream>
#include <string>

int main(){
    int num;

    //ask for user input
    std::cout << "Enter number: ";
    std::cin >> num;

    //determine whether given number is negative, zero or positive
    if (num > 0){
        std::cout << "Positive" << std::endl;
    } else if (num < 0){
        std::cout << "Negative" << std::endl;
    } else{
        std::cout << "Zero" << std::endl;
    }

    //Other way (TERANY OPERATOR)
    //nested terany operation
                           //(condition) ? (expression_if_true) : (expression if false)
    std::string determine = ((num > 0) ? ("Positive") : ((num < 0) ? "Negative" : "Zero"));
    std::cout << determine << std::endl;

    return 0;
}