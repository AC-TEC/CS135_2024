//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 3
//DATE: 4/20/2024
//Task B: Implement default constructor, parameterized constructors, move, getPosition and setPosition functions

#include "Tortoise.hpp"
#include <iostream>
#include <cstdlib> //for rand()
#include <vector> //patterns and passed in parameters

//?DEFAULT CONSTRUCTOR
Tortoise::Tortoise(){
    //50% of 3 == five 3's
    //20% of -6 == two -6's
    //30& of 1 == three 1's

    //set default patterns and position
    patterns = {3,3,3,3,3,-6,-6,1,1,1};
    position = 0;
}


//?PARAMETERIZED CONSTRUCTOR
Tortoise::Tortoise(int* arr, int size, int position){
    //add elements from array to our patterns vector
    for(int i = 0; i < size; i++){
        patterns.push_back(arr[i]);
    }

    //set private data member(position) to position passed in parameter
    this->position = position;
}


//?PARAMETERIZED CONSTRUCTOR
Tortoise::Tortoise(std::vector<int> patterns, int position){
    //this->(private data member) = (variable passed in parameter that has the same name)
    this->patterns = patterns;
    this->position = position;
}


void Tortoise::move(){
    //randomly generate the index from 0-9 (to get our position within patterns vector)
    int random_index = rand() % 10;


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


//return position
int Tortoise::getPosition() const{
    return position;
}


//set to new position
void Tortoise::setPosition(int position){
    this->position = position;
}