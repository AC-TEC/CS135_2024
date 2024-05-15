//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 3
//DATE: 5/14/2024
//Task D: Implement default constructor, parameterized constructor and play functions

#include "Competition.hpp"
#include <iostream>

//?Default Constructor
//use initilizer list to create each data member as a default object of its class
//when called creates a default hare,tortoise and roacoo
Competition::Competition() : rabbit(), tor(), lane(){}


//?Parameterized Constructor
//set private data members to value of parameters
Competition::Competition(Hare coney, Tortoise cooter, int length) : rabbit(coney), tor(cooter), lane(length){}




void Competition::play(){
    std::cout << "TEST" << std::endl;
}