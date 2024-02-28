/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.1
DATE: 2/27/2024

Hw: make a function that recieve two pointers and sorts the values to which they point to.
    callling function would have first_input <= second_input
*/

#include <iostream>

void sort2(double* p, double* q){
    //dereference pointers to compare actual value being pointed to 
    if(*p > *q){
        //temporary variable
        double temp_value = *p;

        //switch the values that p and q point to
        *p = *q; //make p the smaller one
        *q = temp_value;  //make q the larger one
    }
}


int main(){
    double first_input;
    double second_input;

    //get user input
    std::cout << "Enter first number: ";
    std::cin >> first_input;
    std::cout << "Enter second number: ";
    std::cin >> second_input;


    //call function (result: first_pointer <= second_pointer)
    sort2(&first_input, &second_input); 

    //print new values
    std::cout << "(first_input , second_input) -> " << "(" << first_input << " , " << second_input << ")" << std::endl;

    return 0;
}