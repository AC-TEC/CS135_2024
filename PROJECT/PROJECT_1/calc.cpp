/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 
DATE: 1/26/2024

Part B: 
*/

#include <iostream>



int main(){
    char something; //for storing the symbols
    int num;// for storing number
    int track = 0; //where we total everything


    while(std::cin >> num || std::cin >> something){
        if (something == '+'){
            track += num;
            std::cout << "plus: " << track << std::endl;
        } else{
            track -= num;
            std::cout << "subtract: " << track << std::endl;
        }
    }

    std::cout << "Final: " << track << std::endl;
}