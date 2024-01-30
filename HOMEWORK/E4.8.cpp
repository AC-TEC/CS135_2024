/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E4.8
DATE: 1/29/2024

Hw: reads a word and prints each character on a separate line
*/

#include <iostream>
#include <string>


int main(){
    std::string word;

    //ask user for input
    std::cout << "Enter word: ";
    std::cin >> word;

    
    //print each character from word on a separate line
    for (int i = 0; i < word.length(); i++){ //iterate & print each character
        std::cout << word[i] << std::endl;
    }

    return 0;
}