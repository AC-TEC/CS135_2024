/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: PROJECT 1
DATE: 1/24/2024

PART A: read a sequence of integers from cin and report their sum

*/

#include <iostream>

int main(){
    int num;
    int counter = 0; //keep track of total amount 
    
    //read numbers and perform addition
    while (std::cin >> num){
        counter += num;
    }
    std::cout << "The sum is " << counter << std::endl;
    return 0;
}