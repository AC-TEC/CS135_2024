/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 7
DATE: 2/26/2024

Task B:
*/

#include <iostream>
#include <string>

//function to count how many times a character appears
int countChar(std::string line, char c){
    //need counter to track number of occurrences
    int counter = 0;

    //iterate through the line
    for(int i = 0; i < line.length(); i++){
        //check if character at current index matches the character given
        if(line[i] == c){
            //add to counter
            counter++;
        }
    }

    //return the amount of occurences
    return counter;
}


int main(){
    std::string line;

    //go through each line
    while(getline(std::cin,line)){
        std::cout << countChar(line,'{') << " " << line << std::endl;
    }
}