#include "Hare.hpp"
#include <iostream>
#include <vector>


int main(){

//!-----------------TEST DEFAULT HARE--------------------------------------------------------
    std::cout << "TEST DEFAULT" << std::endl;
    //create default hare object
    Hare default_hare_object;

    //get position of default hare object (test our getPosition() function)
    std::cout << "Position: " << default_hare_object.getPosition() << std::endl;

    //set new position of default hare object (test our setPosition() function)
    int new_postion = 3;
    default_hare_object.setPosition(new_postion);
    std::cout << "New position: " << default_hare_object.getPosition() << std::endl;



    //get values from the pattern in default constructor
    std::vector<int> patterns = default_hare_object.getPatterns();


    // Test the move function for default hare
    std::cout << std::endl;
    std::cout << "Default Hare Movement:" << std::endl;
    for (int i = 0; i < patterns.size(); ++i) {
        default_hare_object.move();
        std::cout << "Position after move " << i + 1 << ": " << default_hare_object.getPosition() << std::endl;
    }

    std::cout << std::endl;

    //Print out the numbers in the patterns vector
    std::cout << "Patterns in default constructor: ";
    for(int p : patterns) {
        std::cout << p << " ";
    }
    
    std::cout << std::endl;


//!-----------------1ST PARAMETERIZED HARE--------------------------------------------------------
    std::cout << std::endl;
    std::cout << "TEST 1ST PARAMETERIZED" << std::endl;

    //creater parameterized hare object with a specific pattern
    std::vector<int> first_param_patterns = {1, -2, 6}; 
    
    //create hare
    Hare Hare2(first_param_patterns, 2); //Also sets postion to 2

    //get postion
    std::cout << "Position: " << Hare2.getPosition() << std::endl;

    //get values from the pattern in 1st parameterized constructor
    std::vector<int> patterns_first = Hare2.getPatterns();


    // Test the move function for default hare
    std::cout << std::endl;
    std::cout << "1ST PARAMETERIZED Hare Movement:" << std::endl;
    for (int i = 0; i < patterns_first.size(); ++i) {
        Hare2.move();
        std::cout << "Position after move " << i + 1 << ": " << Hare2.getPosition() << std::endl;
    }

    std::cout << std::endl;

    //check for patterns
    std::cout << "First parameterized patterns: ";
    for(int new_patterns : patterns_first){
        std::cout << new_patterns << " ";
    }

    std::cout << std::endl;

//!-----------------2ND PARAMETERIZED HARE---------------------------------------------------------
    std::cout << std::endl;
    std::cout << "TEST 2ND PARAMETERIZED" << std::endl;

    int arr[] = {1, 1, 2, -3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Hare Hare3(arr, size, 6); //sets postion to 6


    //get new position of Hare
    std::cout << "Position: " << Hare3.getPosition() << std::endl;

    //get values from the pattern in 2nd parameterized constructor
    std::vector<int> patterns_second = Hare3.getPatterns();

    // Test the move function for default hare
    std::cout << std::endl;
    std::cout << "2ND PARAMETERIZED Hare Movement:" << std::endl;
    for (int i = 0; i < patterns_second.size(); ++i) {
        Hare3.move();
        std::cout << "Position after move " << i + 1 << ": " << Hare3.getPosition() << std::endl;
    }

    std::cout << std::endl;


    //check for patterns
    std::cout << "First parameterized patterns: ";
    for(int new_patterns : patterns_second){
        std::cout << new_patterns << " ";
    }
    std::cout << std::endl;


}