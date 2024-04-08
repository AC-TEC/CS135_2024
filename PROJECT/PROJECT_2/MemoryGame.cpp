/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: PROJECT 2
DATE: 4/8/2024

Task A: Implement default constructor, parameterized constructors and deconstructor

Task B: Implement randomize() function

Task C: Implement display() function

Task D: Implement input() and play() function
*/


#include "MemoryGame.hpp"
#include <iostream>
#include <cstdlib> //for rand()
#include <iomanip> //for setw()


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
        bShown[i] = false; //!changed for display() testing have to change back to false
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


//?TASK D
void MemoryGame::play(){
    //randomly place several integers and strings into slots
    randomize();

    //display board layout
    display();

    //count how many rounds it took until we found all pairs
    int rounds = 1;

    //counter for number of pairs found
    //will use this to see if we have reached the amount of pairs in the game (# of pairs depends on each constructor)
    int number_of_pairs = 0;


    //!also i was fucking up thinking why is round 2 not showing that is bc round 1 and round 2 are connecetd so if round 1 we have valid input then we show
    //!but if we enter a valid index of second input and value does not match that of the first then we wont flip its card 

    //?so think of the rounds as pairs round 1 and 2 are connected then boom for round 3 it refreshes

    //loop game until we find pairs
    while(number_of_pairs < numPairs){
        //print out number of round
        std::cout << "Round: " << rounds << std::endl;

        //get input for first card
        int first_card_index = input();

        //flip card
        bShown[first_card_index] = true;

        //display the flipped card on board
        display();

        //move to next round(for second card)
        rounds++;

        //print out next round
        std::cout << "Round: " << rounds << std::endl;

        //get intput for second card
        int second_card_index = input();

        //check if first card and second match
        //if they do then flip second card and display
        //else unflip first card and second card(dont have to for 2nd bc its done by default) then display
        if(values[first_card_index] == values[second_card_index]){
            //flip second card
            bShown[second_card_index] = true;

            //increment counter for number of pairs found
            number_of_pairs++;

            //display both cards
            display();
        }else{
            //unflip first card
            bShown[first_card_index] = false;

            //unflip second card
            bShown[second_card_index] = false;

            //display unflipped cards
            display();
        }

        //increase counter for rounds after we found and displayed the pairs
        rounds++;
    }

    //once all pairs are found print out result message
    std::cout << "Congratulations! Found out all pairs in " << rounds << " rounds" << std::endl;
}


//?TASK C
void MemoryGame::display() const{
    //display array values, if bShown[i] is true,
    //then values[i] is displayed, where i is the index.
    //?When using stew the number will be set at the index that is input. EX: setw(3) =  moves number 2 characters to the right which means it placed at the 3 character/index
    

    //print out labels(top portion of display() function)
    
    //first character separation
    std::cout << " ";
    for(int i = 0; i < numSlots; i++){
        std::cout << std::setw(3) << i << std::setw(3) << " ";
    }

    //next line
    std::cout << std::endl;



    //draw seperation lines(top portion separation)
    //the first '+'
    std::cout << "+";
    
    //draw ------+ for (size) many times
    for(int i = 0; i < numSlots; i++){
        std::cout << "-----+";
    }

    //next line
    std::cout << std::endl;



    //print values (middle portion)
    std::cout << "|";
    for(int i = 0; i < numSlots;i++){
        //if bShown is true display values otherwise dont
        if(bShown[i]){
            std::cout << std::setw(5) << values[i] << "|";
        }else{
            std::cout << "     |";
        }
    }

    //next line
    std::cout << std::endl;



    //draw seperation lines(bottom portion)
    //the first '+'
    std::cout << "+";
    
    //draw ------+ for (size) many times
    for(int i = 0; i < numSlots; i++){
        std::cout << "-----+";
    }

    //next line
    std::cout << std::endl;

}


//?TASK B
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


//?TASK D
int MemoryGame::input() const{
    //input an int that is a valid index and 
    //the corresponding element of values is not shown yet.
    //That is, the input i is in [0, numSlots) and
    //bShown[i] is false.


    //Get user response
    int user_response;
    //?changed it to numSlots-1 bc last index of values array is 7 not 8(7 not 8 is default constructor example)
    std::cout << "Enter a unflipped card in " << "[0, " << numSlots-1 << "]" << ": ";
    std::cin >> user_response;


    //Check if user response enters a valid index
    //If not ask user to re-enter until number entered is not negative or larger than last index of array or already flipped
    while(user_response < 0 || user_response > numSlots-1 || bShown[user_response]){ 

        //if user enters number thats is negative or larger than last index
        if(user_response < 0 || user_response > numSlots-1) {
            std::cout << "Input is not in [0, " << numSlots-1 << "]. ";
        } else {
            //card is already flipped(bShown[user_reponse] == true)
            std::cout << "The card is flipped already. ";
        }

        //get input again
        std::cout << "Re-enter: ";
        std::cin >> user_response;
    }


    //passed all checks. So not invalid input
    return user_response;
}