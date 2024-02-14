/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 6
DATE: 2/14/2024

Task A: print out the ascii value of each character in the user given line of text.
*/

#include <iostream>
#include <string>

int main(){

    std::string text_line;

    //get user input
    std::cout << "Input: ";
    std::getline(std::cin, text_line); //gets entire line (including spaces)

    //iterate through string and print the ascii value of each character
    for(int i = 0; i < text_line.length();i++){
        std::cout << text_line[i] << " " << (int)text_line[i] << std::endl;
    }

    return 0;
}