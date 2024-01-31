/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 3
DATE: 1/30/2024

Task A: ask user to input a string representing date and print out the East basin storage
        on that day
*/


#include <iostream>
#include <string>
#include <fstream>  //to parse through file
#include <cstdlib>  //for close() function to close file at end


int main(){
    //open file 
    std::ifstream water_data("Current_Reservoir_Levels.tsv");

    //If file fails to open display error message
    if (water_data.fail()){
        std::cerr << "FILE FAILED TO OPEN!!!" << std::endl;
        exit(1); //exit file
    }

    //skip header line (first row in tsv file)
    std::string junk_row;
    std::getline(water_data, junk_row);

    //ask user to input date (format: MM/DD/YYYY)
    std::string user_date;
    std::cout << "Enter date: ";
    std::cin >> user_date;

    //variables to store tsv file data
    std::string date;
    double eastSt;
    double eastEl;
    double westSt;
    double westEl;

    //Read each line of tsv file into variables
    while(water_data >> date >> eastSt >> eastEl >> westSt >> westEl ){  
        //compare user_date and date from file
        //If there is a match print out East basin storage from date given
        if(date == user_date){
            std::cout << "East basin storage: " << eastSt << " billion gallons" << std::endl;
        }
    }

    //close file
    water_data.close();

}
