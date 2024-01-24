/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 1
DATE 1/23/2024

Task A: compare two input numbers and output smaller of the two
*/

#include <iostream>
#include <string>

int main(){

//? Task A

    int first_number;
    int second_number;

//ask for numbers
    std::cout << "Enter the first number: ";
    std::cin >> first_number;
    std::cout << "Enter the second number: ";
    std::cin >> second_number;

//compare given numbers and print out the smaller number
    if (first_number < second_number){
        std::cout << "The smaller of the two is " << first_number << std::endl;
    } else if (second_number < first_number){
        std::cout << "The smaller of the two is " << second_number << std::endl;
    } else {
        std::cout << "All numbers are equal!!!" << std::endl;
    }
    return 0;
}