#include "MemoryGame.hpp"
#include <iostream>
#include <string>



int main(){
    //call default constructor

    //create default game object
    MemoryGame def_game;

//!TESTING DEFAULT CONSTRUCTOR
/*
    //!TESTING DEFAULT CONSTRUCTOR
    const std::string* values = def_game.getValues(); 

    //print contents of default array
    for(int i = 0; i < 8; i++){
        std::cout << values[i] << std::endl;
    }

    std::cout << "----------------" << std::endl;

    //print boolean array
    const bool* bShown = def_game.get_bshown();
    for(int i = 0; i < 8; i++){
        std::cout << bShown[i] << std::endl;
    }


    //call randomize function
    def_game.randomize();


    //!Testing after randomize()
    std::cout << "----------------" << std::endl;

    const std::string* r_values = def_game.getValues();

    // Print contents of array after randomization
    for (int i = 0; i < 8; i++) {
        std::cout << r_values[i] << std::endl;
    }
*/

    
    //call display() function
    //def_game.display();


    //call input() function
    //will have to modify the bShown part in default constructor to really test if works
    //def_game.input();

    //play game
    def_game.play();


    //free memory
    def_game.~MemoryGame();
}