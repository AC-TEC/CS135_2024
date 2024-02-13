/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 5
DATE: 2/12/2024

Task A: write a function that takes in two integers and checks if they are divisible by each other.
        If they are then print yes else print no.
*/
#include <iostream>


bool isDivisibleBy(int n, int d){
    //check for division by 0
    if(d == 0){
        return false;
    }

    //check if n is divisible by d. if it is return true else return false.
    if(n % d == 0){ 
        return true;
    }


    return false;
}

int main(){
    int n;
    int d;

    //get user input
    std::cout << "Enter first number: ";
    std::cin >> n;
    std::cout << "Enter second number: ";
    std::cin >> d;

    //call function
    bool divisible = isDivisibleBy(n,d);

    //print out response (0 = false, 1 = true)
    if(divisible == 0){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }

    return 0;
}