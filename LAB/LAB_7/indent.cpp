/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 7
DATE: 3/5/2024

Task B: Program properly indents code according to open and closed curly brackets
*/

#include <iostream>
#include <string>

//function to count how many times a character appears
int countChar(std::string line, char c) {
    //need counter to track number of occurrences
    int counter_char = 0;

     //iterate through the line
    for(int i = 0; i < line.length(); i++) {
        //check if character at current index matches the character given
        if(line[i] == c) {
            //add to counter
            counter_char++;
        }
    }
    //return the amount of occurences
    return counter_char;
}


std::string removeLeadingSpaces(std::string line) {
    //counter
    int remove_index = 0;

    //remove index
    while(isspace(line[remove_index])) {
        remove_index++;
    }
        //return new
    return line.substr(remove_index);
}



int main() {
    std::string unindent_line;
    int counter = 0;

    while(std::getline(std::cin, unindent_line, '\n')) {

        if(removeLeadingSpaces(unindent_line)[0] == '}') {
            for(int i = 0; i < counter - 1; i++) {
                std::cout << "\t"; 
            }
        } else {
            for(int i = 0; i < counter; i++) {
                std::cout << "\t";
            }
        }

        counter -= countChar(unindent_line, '}');
        counter += countChar(unindent_line, '{');
        std::cout << removeLeadingSpaces(unindent_line) << std::endl;
    }

    return 0;
}