/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.8
DATE: 2/20/2024

HW: write a function that checks whether two arrays have the same elements in the same order
*/

#include <iostream>

bool equals(int a[], int a_size, int b[], int b_size){
    //check if the arrays have same size. If not then they will not have the same elements
    if(a_size != b_size){
        return false;
    }

    //loop through arrays and compare elements at each index
    for(int i = 0; i < a_size; i++){
        //check for similar elements. if they are not then return false.
        if(a[i] != b[i]){
            return false;
        }
    }

    //All elements are in the same order. retrun true
    return true;
}



int main(){
    int a_size;
    int b_size;


    //get user input
    std::cout << "Enter array A size: ";
    std::cin >> a_size;
    std::cout << "Enter array B size: ";
    std::cin >> b_size;

    //form arrays
    int a[a_size];
    int b[b_size];

    //separation line
    std::cout << std::endl;

    //fill arrays with user input;
    std::cout << "Enter elements of array A: ";
    for(int i = 0; i < a_size; i++){
        std::cin >> a[i];
    }

    std::cout << "Enter elements of array B: ";
    for(int i = 0; i < b_size; i++){
        std::cin >> b[i];
    }

    //separate
    std::cout << std::endl;

    //call function 
    bool call_function = equals(a, a_size, b, b_size);


    //print out true or false
    if(call_function == 1){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }

    return 0;
}

























/*

    //print out elements of each array
    std::cout << "Array A: ";
    for(int i = 0; i < a_size; i++){
        std::cout << a[i] << " ";
    }

    //separate
    std::cout << std::endl;

    std::cout << "Array B: ";
    for(int i = 0; i < b_size; i++){
        std::cout << b[i] << " ";
    }

*/