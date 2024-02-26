/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 7
DATE: 2/26/2024

Task A: Write a program that reads input from cin and prints out each input line with leading spaces removed.
*/

#include<iostream>
#include <string>
#include <cctype> //for isspace() function


std::string removeLeadingSpaces(std::string line){
    //store the new line
    std::string modified_line;

    //read each line
    while(getline(std::cin, line)){
        //index for characters
        int index = 0;

        //check if character at index is a space
        while(isspace(line[index])){
            //increment until we get to a non space character
            index++;
        }

        //store characters that are not spaces(without indentation) starting from incremented index index
        modified_line = line.substr(index);

        //print out the rest of the string that doesnt include space characters in the beginning
        std::cout << modified_line << std::endl;
    }

    return modified_line;
}


int main(){
    std::string line;

    //call function
    removeLeadingSpaces(line);

    return 0;
}


