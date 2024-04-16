/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: PROJECT 3
DATE: 4/16/2024

Task A: Implement default constructor, parameterized constructors, move, getPosition and setPosition functions

*/



#include "Hare.hpp"
#include <iostream>


//!-----------------TASK A--------------------------------------------------------

//?Default constructor
Hare::Hare(){
       //a typical hare that sleeps 20% of the time,
       //move 9 squares to the right 20% of the time,
       //move 12 squares to the left 10% of the time,
       //move 1 square to the right 30% of the time,
       //move 2 squares to the left 20% of the time.
} 


//?Parameterized constructor
Hare::Hare(std::vector<int> patterns, int position){

}


//?Parameterized constructor
Hare::Hare(int* arr, int size, int position){

}


void Hare::move(){

}


//return current position
int Hare::getPosition() const{
    return position;
} 


void Hare::setPosition(int position){

}