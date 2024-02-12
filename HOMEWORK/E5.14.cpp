/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.14
DATE: 2/12/2024

Hw: write a function that swaps values of two variables depending on which of the two is greater.
    otherwise, it leaves them unchanged.
*/

#include <iostream>

void sort2(int &a, int&b){
    //check if a > b. if it is then swap values else dont swap values
    if(a > b){
        int temporary = a; //temp holds (a) value
        a = b;             // (a) now holds (b) value
        b = temporary;     //(b) now holds (a) value
    }
}

int main(){
    int u;
    int v;

    //get user input
    std::cout << "Enter 1st number: ";
    std::cin >> u;
    std::cout << "Enter 2nd number: ";
    std::cin >> v;

    //call function 
    sort2(u,v);
    
    //just a space
    std::cout << std::endl;
    
    //print out the new numbers
    std::cout << "new 1st: " << u << std::endl;
    std::cout << "new 2nd: " << v << std::endl;

    return 0;

}