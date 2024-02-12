/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E8.1
DATE: 2/12/2024

Hw: 
write program that completes the following tasks:
    -Open a file with the name hello.txt.
    -Store the message “Hello, World!” in the file.
    -Close the file.
    -Open the same file again.
    -Read the message into a string variable and print it.
*/

#include <iostream>
#include <string>
#include <fstream>


int main(){

    //open file for writing
    std::ofstream txt_file("hello.txt");

    //store message into file
    txt_file << "Hello, World!";

    //close file
    txt_file.close();

    //open file again and read the file
    std::ifstream message_file("hello.txt");

    //variable to store file message
    std::string message;

    //get message from file 
    std::getline(message_file, message);

    //print message
    std::cout << message << std::endl;

    //close file
    message_file.close();

    return 0;
}

