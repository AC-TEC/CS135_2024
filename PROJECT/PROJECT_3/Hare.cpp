//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 3
//DATE: 4/16/2024
//Task A: Implement default constructor, parameterized constructors, move, getPosition and setPosition functions

#include "Hare.hpp"
#include <iostream>
#include <cstdlib> //for rand() function
#include <vector>


//!-----------------TASK A--------------------------------------------------------

//?Default constructor
Hare::Hare(){
    //a typical hare that sleeps 20% of the time,
    //move 9 squares to the right 20% of the time,
    //move 12 squares to the left 10% of the time,
    //move 1 square to the right 30% of the time,
    //move 2 squares to the left 20% of the time.


    //20% of 10 is 2, so 2 zeros for sleep.
    //20% of 10 is 2, so 2 nines for big hop.
    //10% of 10 is 1, so 1 negative twelve for big slip.
    //30% of 10 is 3, so 3 ones for small hop.
    //20% of 10 is 2, so 2 negative twos for small slip.


    //default patterns
    patterns = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};

    //default position
    position = 0;
} 


//?Parameterized constructor
Hare::Hare(std::vector<int> patterns, int position){
    //assign's parameter values to private data members
    //set private member value to the one passed in the parameter

    //this->(private data member) = (variable passed in parameter that has the same name)
    this->patterns = patterns;
    this->position = position;
}


//?Parameterized constructor
Hare::Hare(int* arr, int size, int position){
    //add elements from array to our patterns vector
    for(int i = 0; i < size; i++){
        patterns.push_back(arr[i]);
    }

    //set private data member(position) to position passed in parameter
    this->position = position;
}


void Hare::move(){

    //randomly generate the index from 0-9 (to get our position within patterns vector)
    int random_index = rand() % 10;

    //!for testing(remove before submit to gradescope)
    //std::cout << "Randomly generated index: " << random_index << std::endl;


    //get new position from pattern vector using our randomly generated index
    //doing this gets us how many sqaures we need to move forward or backward
    int new_position = patterns[random_index];

    //update our position
    position += new_position;

    //check if new position makes animal slip left before block zero(go negative in position)
    //If so set position to 0
    if(position < 0){
        position = 0;
    }

    //check if new position makes animal move beyond the last block(past last index of road)
    //If so set position to the last index of road
    if(position >= patterns.size()){
        //set to last index
        position = patterns.size()-1;
    }
}


//return current position
int Hare::getPosition() const{
    return position;
} 


//set new position
void Hare::setPosition(int position){
    this->position = position;
}



//!Function to get values from patterns vector (for testing purposes)

std::vector<int> Hare::getPatterns() const {
    return patterns;
}
