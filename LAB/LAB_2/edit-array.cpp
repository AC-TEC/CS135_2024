/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 2
DATE: 1/29/2024

Task C: create an array of 10 integers, 
    and provide the user with an interface to edit any of its elements.
*/

#include <iostream>

int main(){

    int index;      //index for array
    int value;      //value for array
    int myData[10]; //create array

    //fill array with value of 1
    for(int i = 0; i < 10; i++){
        myData[i] = 1;
        std::cout << myData[i] << " ";
    }

    do{
        std::cout << std::endl;
        std::cout << std::endl;
        
        //get user input
        std::cout << "Input index: ";
        std::cin >> index;
        std::cout << "Input value: ";
        std::cin >> value;

        //check if index is in range and replace value with user input value
        if(index >= 0 && index <= 9){
            myData[index] = value;
            //iterate through array and print new array(contains user value at index)
            for(int i = 0; i < 10; i++){
                std::cout << myData[i] << " ";
            }
        } else { //when out of bounds
            std::cout << "Index out of range. Exit." << std::endl;
            break;  //break out of loop when not in range
        }


    } while (index >= 0 && index <= 9); //will keep program running as long as index is in range

    return 0;
}