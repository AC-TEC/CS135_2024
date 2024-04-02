#include "MemoryGame.hpp"


//Default constructor
MemoryGame::MemoryGame() {
    //default constructor, with 3 pairs of random integers in range [0, 999] 
    //placed in 8 blocks (two blocks are empty).
}

//Parameterized constructor
MemoryGame::MemoryGame(int numPairs, int numSlots){
    //Place numPairs pairs of random integers in range [0, 999] in numSlots space, need numPairs > 0, numSlots > 0, and numSlots >= 2 * numPairs

}

//Parameterized constructor
MemoryGame::MemoryGame(string *words, int size, int numSlots){
    //instead of randomly generated integers,
    //use words as data
}


//Deconstructor
MemoryGame::~MemoryGame(){

}


void MemoryGame::play(){

}


void MemoryGame::display() const{
    //display array values, if bShown[i] is true,
    //then values[i] is displayed, where i is the index.
}


void MemoryGame::randomize(){
    //randomize the layout of elements in values.
}

int MemoryGame::input() const{
    //input an int that is a valid index and 
    //the corresponding element of values is not shown yet.
    //That is, the input i is in [0, numSlots) and
    //bShown[i] is false. 
}