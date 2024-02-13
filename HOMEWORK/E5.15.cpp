/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.14
DATE: 2/12/2024

Hw: write a function that sorts 3 variables into sorted order(from least to greatest.)
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


void sort3(int &a, int&b, int&c){
    sort2(a,b);     // sort a and b
    sort2(b,c);     // sort b and c
    sort2(a,b);     // sort a and b again (to handle the case where a > c)
}

/*
int main(){
    int a;
    int b;
    int c;

    //ask user for input
    std::cout << "Enter A: ";
    std::cin >> a;
    std::cout << "Enter B: ";
    std::cin >> b;
    std::cout << "Enter C: ";
    std::cin >> c;

    //call function
    sort3(a,b,c);

    //to separate input from outputs
    std::cout << std::endl;

    //print out new a,b,c values
    std::cout << "New A: " << a << std::endl;
    std::cout << "New B: " << b << std::endl;
    std::cout << "New C: " << c << std::endl;
}

*/

