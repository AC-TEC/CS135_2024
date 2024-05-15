//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 3
//DATE: 5/15/2024
//Task D: Implement default constructor, parameterized constructor and play functions

#include "Competition.hpp"
#include <iostream>


//?Default Constructor
//use initilizer list to create each data member as a default object of its class
//when called creates a default hare,tortoise and road
Competition::Competition() : rabbit(), tor(), lane(){}


//?Parameterized Constructor
//use initializer list to create each data member as a non-defeault object of its class (each data member object has parameter object values passed into them)
//default objects to objects with values from parameters passed in
Competition::Competition(Hare coney, Tortoise cooter, int length) : rabbit(coney), tor(cooter), lane(length){}


//?Lets play!!!
void Competition::play(){
    //counter for rounds
    int round = 1;

    //iterate as long as rabbit and tortoise don't reach the last block in lane
    while((rabbit.getPosition() < lane.length() - 1) && (tor.getPosition() < lane.length() - 1)){
        //move rabbit (HARE)
        rabbit.move();

        //check if rabbit goes to the left of first block or beyond last block
        //fix its position when this occurs
        if(rabbit.getPosition() < 0){
            //set position to first block
            rabbit.setPosition(0);
        }

        if(rabbit.getPosition() > lane.length() - 1){
            //set position to last block(last index of lane)
            rabbit.setPosition(lane.length() - 1);
        }


        //mark lane with position of rabbit
        lane.mark(rabbit.getPosition(), 'H');


        //move tor (TORTOISE)
        tor.move();
        
        //check if tor goes to the left of first block or beyond last block
        //fix its position when this occurs
        if(tor.getPosition() < 0){
            //set position to first block
            tor.setPosition(0);
        }

        if(tor.getPosition() > lane.length() - 1){
            //set position to last block(last index of lane)
            tor.setPosition(lane.length() - 1);
        }


        //mark lane with position of tor
        lane.mark(tor.getPosition(), 'T');


        //display round and positions on lane
        std::cout << "Round   " << round << ": ";
        lane.display();


        //edge case: rabbit and tor step on same block
        if(rabbit.getPosition() == tor.getPosition()){
            std::cout << "Ouch! Tortoise bites hare." << std::endl;
        }


        //clear lane for next round
        lane.mark(rabbit.getPosition(), ' ');
        lane.mark(tor.getPosition(), ' ');


        //increase round
        round++;

        //break from loop
        if(rabbit.getPosition() >= lane.length()-1 || tor.getPosition() >= lane.length() - 1){
            break;
        }
    }


    //print competition results
    if(rabbit.getPosition() == tor.getPosition()){
        std::cout << "It is a tie." << std::endl;
    }else if(rabbit.getPosition() == lane.length() - 1){
        std::cout << "Yuck. Hare wins." << std::endl;
    }else{
        std::cout << "Yay! Tortoise wins!" << std::endl;
    }


/*
    if(rabbit.getPosition() == lane.length() - 1){
        std::cout << "Yuck. Hare wins." << std::endl;
    }else if(tor.getPosition() == lane.length() - 1){
        std::cout << "Yay! Tortoise wins!" << std::endl;
    }else{
        std::cout << "It is a tie." << std::endl;
    }
*/

}