//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 3
//DATE: 5/15/2024
//Task D: Implement default constructor, parameterized constructor and play functions



#include "Competition.hpp"
#include <iostream>
#include <vector>
#include <string>


int main(){

    //?TEST DEFAULT COMPETITION
    Competition race;
    race.play();


    //?TEST PARAMETERIZED COMPETITION(NON-DEFAULT)
    std::vector<int> harePattern{-3, 2, 0, 0, 6};
    Hare hare(harePattern, 0);

    std::vector<int> torPattern{1, 1, 2, -2, 3};
    Tortoise tor(torPattern, 5);
    
    //CREATE PARAMETERIZED COMPETITION OBJECT
    Competition race2(hare,tor,30);
    race2.play();

    return 0;
}
