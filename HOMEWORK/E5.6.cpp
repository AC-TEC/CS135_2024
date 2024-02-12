/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.6
DATE: 2/12/2024

Hw: Create a function that returns the middle character of a string.
    Will return two characters if the string is even or one if the string is odd
*/


#include <iostream>
#include <string>

//function that returns middle characters
std::string middle(std::string str){
    //new string containing only middle characters
    std::string new_str;

    //check if length of string is even or odd
    if(str.length() % 2 == 0){ //even
        //half length of string and get 2 middle characters
        new_str = str.substr((str.length()/2)-1, 2);

    } else{ 
        //get 1 middle character
        new_str = str.substr(str.length()/2, 1);

    }

    //return new string
    return new_str;
}


int main(){
    std::string user_string;
    std::string new_string;

    //get user input
    std::cout << "Enter string: ";
    std::cin >> user_string;

    //call function
    new_string = middle(user_string);

    //print new string
    std::cout << new_string << std::endl;

    return 0;
}