/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 2
DATE: 1/29/2024

Task D: use an array of integers to compute and print all fibonacci 
        numbers from index F(0) to F(59)
*/


#include<iostream>


int main(){
    int fib[60];

    //fill in first two terms
    fib[0] = 0;
    fib[1] = 1;

    //itertate through array and calculate using fibonacci formula
    for(int i = 2; i < 60; i++){    //start at 2nd index
        fib[i] = fib[i-1] + fib[i-2];
    }

    //iterate through array and print fibonacci numbers
    for (int i = 0; i < 60; i++){
        std::cout << fib[i] << std::endl;
    }

    return 0;
}