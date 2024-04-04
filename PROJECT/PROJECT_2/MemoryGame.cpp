/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: PROJECT 2
DATE: 4/2/2024

Task A: Write default constructor, parameterized constructors and deconstructor

Task B: Write code for randomize() function
*/


#include "MemoryGame.hpp"
#include <iostream>
#include <cstdlib> //for rand()

//!Warning: remove all instances of srand(time(NULL)); statement before submitting to gradescope.

//?TASK A
//Default constructor
MemoryGame::MemoryGame() {
    //default constructor, with 3 pairs of random integers in range [0, 999] 
    //placed in 8 blocks (two blocks are empty).

    //set data members to 3 and 8
    numPairs = 3;
    numSlots = 8;


    //dynamically allocate an array of strings with numSlots elements and assign it to data member values
    values = new std::string[numSlots];


    //generate 3 random integers from range [0,999]
    
    //array of 3 to hold these integers
    int random_int_storage[3];
    //loop through array and add randomly generated numbers
    for(int i = 0; i < 3; i++){
        random_int_storage[i] = rand() % 1000;
    }


    //place randomly generated integers into values array
    values[0] = std::to_string(random_int_storage[0]);
    values[1] = std::to_string(random_int_storage[0]);

    values[2] = std::to_string(random_int_storage[1]);
    values[3] = std::to_string(random_int_storage[1]);

    values[4] = std::to_string(random_int_storage[2]);
    values[5] = std::to_string(random_int_storage[2]);

    //add empty string to remaining positions of values array
    for(int i = 6; i < numSlots; i++){
        values[i] = ""; //values[6] & values[7]
    }


    //dynamically allocate an array of booleans with numSlot elements and assign it to data member bShown
    bShown = new bool[numSlots];
    //set each element in array to false
    for(int i = 0; i < numSlots; i++){
        bShown[i] = false;
    }
}


//Parameterized constructor
MemoryGame::MemoryGame(int numPairs, int numSlots){
    //Place numPairs pairs of random integers in range [0, 999] in numSlots space, need numPairs > 0, numSlots > 0, and numSlots >= 2 * numPairs
    //need numPairs > 0, numSlots > 0, and numSlots >= 2 * numPairs

    //check if numPairs and numSlots is negative or numSlots is smaller than twice of numPairs
    //If yes, set the value of numPairs and numSlots
    if(numPairs <= 0 || numSlots <= 0 || numSlots < 2 * numPairs){
        numPairs = 3;
        numSlots = 8;
    }

    //When condition above is not satisfied
    //set private member value to the one passed in the parameter
    this->numPairs = numPairs;
    this->numSlots = numSlots;


    //dynamically allocate an array of strings with numSlots elements & assign it to data member values
    values = new std::string[numSlots];

    //generate 3 random integers from range [0,999]    
    //array of 3 to hold these integers
    int random_int_storage[3];
    //loop through array and add randomly generated numbers
    for(int i = 0; i < 3; i++){
        random_int_storage[i] = rand() % 1000;
    }


    //place randomly generated integers into values array
    values[0] = std::to_string(random_int_storage[0]);
    values[1] = std::to_string(random_int_storage[0]);

    values[2] = std::to_string(random_int_storage[1]);
    values[3] = std::to_string(random_int_storage[1]);

    values[4] = std::to_string(random_int_storage[2]);
    values[5] = std::to_string(random_int_storage[2]);

    //add empty string to remaining positions of values array
    for(int i = 6; i < numSlots; i++){
        values[i] = ""; //values[6] & values[7]
    }


    //dynamically allocate an array of booleans with numSlot elements and assign it to data member bShown
    bShown = new bool[numSlots];
    //set each element in array to false
    for(int i = 0; i < numSlots; i++){
        bShown[i] = false;
    }

}

//Parameterized constructor
MemoryGame::MemoryGame(std::string *words, int size, int numSlots){
    //instead of randomly generated integers,
    //use words as data

    //check if size or numSlots is a negative or numSlots is smaller than twice of size
    //if yes, set numSlots to be twice of size
    if(size <= 0 || numSlots <= 0 || numSlots < 2 * size){
        numSlots = 2 * size;
    }

    //set data members numPairs to size and numSlots to numSlots (private data member to the one in parameter)
    numPairs = size;
    this->numSlots = numSlots;

    //dynamically allocate an array of strings with numSlots and assign it to data member values
    values = new std::string[numSlots];

    //index for words
    //size represents the amount of words
    int words_index = 0;

    //loop through values array and place one word into 2 slots until all words are used up then fill rest with empty strings
    for(int i = 0; i < numSlots; i+=2){
        //check if we have words to input into slots
        if(words_index < size){
            //place words into slots
            values[i] = words[words_index];
            values[i+1] = words[words_index];
            
            //move to next word
            words_index++;
        }else{
            //when reach limit of words(all words have been placed -> words_index > size) fill rest of slots with empty strings
            values[i] = "";
            values[i+1] = "";
        }
    }


    //dynamically allocate an array of booleans with numSlot elements and assign it to data member bShown
    bShown = new bool[numSlots];
    //set each element in array to false
    for(int i = 0; i < numSlots; i++){
        bShown[i] = false;
    }
}



//Deconstructor
MemoryGame::~MemoryGame(){
    //free memory from all dynamically allocated arrays
    delete[] values;
    values = nullptr;
    delete[] bShown;
    bShown = nullptr;
}


//?for testing(with default constructor) delete after finished using it
const std::string* MemoryGame::getValues() const {
    return values;
}

const bool*  MemoryGame::get_bshown() const {
    return bShown;
}


void MemoryGame::play(){
    std::cout << "filler" << std::endl;
}


void MemoryGame::display() const{
    //display array values, if bShown[i] is true,
    //then values[i] is displayed, where i is the index.
    std::cout << "filler" << std::endl;
}


void MemoryGame::randomize(){
    //randomize the layout of elements in values.

    //Get size of values array(will use this to randomize)
    int size = numSlots;
    
    //seed random number generator(for better randomization)
    //srand(time(0));

    //Repeat while size greater than 1 (randomization)
    while(size > 1){
        //generate random index from interval [0,size]
        int random_index = rand() % size;

        //swap the chosen random element with the last element in values array
        std::swap(values[random_index], values[size - 1]);

        //reduce size by 1
        size--;
    }
}

int MemoryGame::input() const{
    //input an int that is a valid index and 
    //the corresponding element of values is not shown yet.
    //That is, the input i is in [0, numSlots) and
    //bShown[i] is false.
    int filler = 1;
    return filler;
}