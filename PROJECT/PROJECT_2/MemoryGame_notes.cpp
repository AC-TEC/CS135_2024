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
         //!changed so i can see if its an empty string for slot change back to "" before submission
        values[i] = ""; //values[6] & values[7]
    }


    //dynamically allocate an array of booleans with numSlot elements and assign it to data member bShown
    bShown = new bool[numSlots];
    //set each element in array to false
    for(int i = 0; i < numSlots; i++){ //!change numSlots-1 back to numSlots
        bShown[i] = false; //!changed for display() testing have to change back to false
    }
    //!bShown[7] = false; //delete once finished(used to check how program will repsond once entered a card index that is not flipped already)

/*
//?It did work
    //set each element in array to false
    for(int i = 0; i < numSlots-1; i++){ //!change numSlots-1 back to numSlots
        bShown[i] = true; //!changed for display() testing have to change back to false
    }

    bShown[7] = false; //!delete once finished(used to check how program will repsond once entered a card index that is not flipped already)
    //!want to see if my input() function stops once card that is not flipped is entered


*/

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

/*
//?for testing(with default constructor) delete after finished using it
const std::string* MemoryGame::getValues() const {
    return values;
}

const bool*  MemoryGame::get_bshown() const {
    return bShown;
}
*/

void MemoryGame::play(){
    //randomly place several integers and strings into slots
    randomize();

    //display board layout
    display();

    //count how many rounds it took until we found all pairs
    //mo round 0
    int rounds = 1;

    //counter for number of pairs found
    //will use this to see if we have reached the amount of pairs in the game (# of numpairs depends on each constructor default = 3 other constrcutors = user based)
    int number_of_pairs = 0;


    //!ohhhh im fucking up i was looking at rounds in instructions and thinking if user enters the same index twice then it will face up
    //! it was if value not index. so if value is the same then make them both face up (make both shown) else you just dont
    //!also i was fucking up thinking why is round 2 not showing that is bc round 1 and round 2 are connecetd so if round 1 we input valid input then we show
    //!but if we enter a valid index and value of second input does not match that of the first then we wont flip its card 

    //?so think of the rounds as pairs round 1 and 2 are connected then boom for round 3 it refreshes that why when 1 is entered for input it is flipped up and for round 2 its not flipped up

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
        //else unflip first card and display(dont have to do nothing to second card bc its unflippped by default)
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


void MemoryGame::display() const{
    //display array values, if bShown[i] is true,
    //then values[i] is displayed, where i is the index.
    //?When using stew the number will be set at the index that is input. EX: setw(3) =  moves number 2 characters to the right which means it placed at the 3 character/index
    

    //print out labels(top portion of display() function)
    //!problem could be the 5 separation instead do the way it has it (This was the problem-> fixed then worked)
    
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


    //Get user response
    int user_response;
    //?changed it to numSlots-1 bc last index of values array is 7 not 8(7 not 8 is default constructor example)
    std::cout << "Enter a unflipped card in " << "[0, " << numSlots-1 << "]" << ": ";
    std::cin >> user_response;


    //Check if user response enters a valid index
    //If not ask user to re-enter until number entered is not negative or larger than numSlots
    while(user_response < 0 || user_response > numSlots-1 || bShown[user_response]){ //second condition could be: user_response > (numSlots-1) since last index of values array is 7 which is numSlots-1
        //?changed it to numSlots-1 bc last index of values array is 7 not 8(7 not 8 is default constrcutor exmaple)
        if(user_response < 0 || user_response > numSlots-1) {
            std::cout << "Input is not in [0, " << numSlots-1 << "]. ";
        } else {
            std::cout << "The card is flipped already. ";
        }
        std::cout << "Re-enter: ";
        std::cin >> user_response;
    }

/*
    //Check if user response enters a valid index
    //If not ask user to re-enter until number entered is not negative or larger than numSlots
    while(user_response < 0 || user_response > numSlots-1){ //second condition could be: user_response > (numSlots-1) since last index of values array is 7 which is numSlots-1
        //?changed it to numSlots-1 bc last index of values array is 7 not 8(7 not 8 is default constrcutor exmaple)
        std::cout << "input is not in " << "[0, " << numSlots-1 << "]. " << "Re-enter: ";
        std::cin >> user_response;



        //check for valid index and if card is already flipped.Prompt to re-enter
        //while card at index user_response is flipped then re-enter until user inputs an index for a card that is not flipped(aka false in bShown array)
        //using bShown[] array bc that array tells us which cards at which index have already been flipped
        while(bShown[user_response] == true){
            std::cout << "The card is flipped already. Re-enter: ";
            std::cin >> user_response;
        }
    }

    //compare user response with new one to check if we already flipped it(will have to use bShown array)
    //while the card is flipped up already(when bShown is true)
    //ask user to re-enter for a new card that is not flipped
    //while card at index user_response is flipped then re-enter until user inputs an index for a card that is not flipped(aka false in bShown array)
*/

    //passed all checks that would return an invalid input
    return user_response;
}