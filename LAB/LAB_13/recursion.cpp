/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 13
DATE: 5/09/2024

Task A: Write a program that prints all numbers in range left to right, separated by spaces. (Don’t use loops, global or static variables.)
*/
#include <iostream>

//function to recursivly call range of given numbers
void printRange(int left, int right){
    
    //base case (used to stop)
    if (left > right){
        //returns nothing. just stops calling function again
        return;
    }

    if(left <= right){
        //call function recursively
        printRange(left,right - 1);
        
        //prints numbers in range
        std::cout << right << " ";
    }
}


int main(){
    //call recursive function
    printRange(-2, 10);
}