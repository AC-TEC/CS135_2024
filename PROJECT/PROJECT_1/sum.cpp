/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: PROJECT 1
DATE: 1/24/2024

PART A: read a sequence of integers from cin and report their sum

To print: compile like normal then do ./name_given < numbers.txt
*/

#include <iostream>

int main(){
    int num;
    int counter = 0; //keep track of total amount 
    
    //read numbers and perform addition
    //? NOTE: loop continues until it can no longer read from input file(txt file) 
    while (std::cin >> num){
        counter += num;
    }
    std::cout << "The sum is " << counter << std::endl;
    return 0;
}