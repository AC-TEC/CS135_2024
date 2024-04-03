#include "MemoryGame.hpp"
#include <iostream>
#include <string>



int main(){
    //call default constructor

    //create default game object
    MemoryGame def_game;
/*
    !TESTING DEFAULT CONSTRUCTOR
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
*/
    //free memory
    def_game.~MemoryGame();
}