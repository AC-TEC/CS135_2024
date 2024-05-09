//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 3
//DATE: 5/8/2024
//Task C: Implement default constructor, parameterized constructor, mark, display and length functions

#include "Road.hpp"
#include <iostream>

//default constructor
//Instantiate data member block with size 70 and each element set to space(' ') char
//Implement constructor using an initializer list
Road::Road() : blocks(70, ' '){}


//non-default contructor
Road::Road(int length){
    //if given length is a negative number change it to 70
    if (length <= 0){
        length = 70;
    }

    //initalize blocks(vector) with size of length parameter and set each element to a space(' ') char
    //using assign(new_size_of_vector, value_to_assign_to_each_element) function
    blocks.assign(length, ' ');
} 


//insert given ch to given index in Blocks(vector) if valid
void Road::mark(int index, char ch){
    // Check if index is within the bounds of the blocks vector
    if (index >= 0 && index < blocks.size()) {
        // Set the element at the specified index to the given character
        blocks[index] = ch;
    }
}

//print all elements of Blocks(vector) in a line followed by a new line character
void Road::display() const{
    for(auto display : blocks){
        std::cout << display;
    }
    std::cout << std::endl;
}

//return number of elements in Blocks(vector)
int Road::length() const{
    return blocks.size();
}