/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 
DATE: 1/26/2024

Part B: read non-negative integers written to be addded or subtacted and print out sum
*/

#include <iostream>

int main(){
    char read; //read the txt / read the - or + symbols
    int sum = 0; //keep track of sum
    
    //get first number in txt file
    int num;
    std::cin >> num;
    sum += num;

    //iterate through the txt file
    while(std::cin >> read){
        //get the integers
        int number;
        std::cin >> number;

    //Do operation based on + or - characters
        if (read == '+'){
            sum += number;
        } else{
            sum -= number;
        }
    } 

    //print out sum
    std::cout << "SUM: " << sum << std::endl;
    
    return 0;
}
