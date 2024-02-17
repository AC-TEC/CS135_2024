/*
Author: 
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 3
DATE: 1/31/2024

Task C: ask user for two dates(beginning and end) then check each day in the interval
        and print which basin had higher elevation by printing (EAST,WEST or EQUAL)
*/

#include <iostream>
#include <string>
#include <fstream> //read file
#include <cstdlib> //close() file

int main(){

    //open file
    std::ifstream water_data("Current_Reservoir_Levels.tsv");

    //If file fails to open print error message and close
    if(water_data.fail()){
        std::cerr << "FILE FAILED TO OPEN!!!" << std::endl;
        exit(1);
    }

    //skip header line
    std::string junk_line;
    std::getline(water_data,junk_line);

    //ask for user starting and end dates (format: MM/DD/YYYY)
    std::string starting_date;
    std::string ending_date;

    std::cout << "Enter starting date: ";
    std::cin >> starting_date;
    std::cout << "Enter ending date: ";
    std::cin >> ending_date;


    //variables to store tsv data
    std::string date;
    double eastEl;
    double westEl;

    //read each line(row) individually from file
    while(water_data >> date >> junk_line >> eastEl >> junk_line >> westEl){
        //get date interval range
        if (date >= starting_date && date <= ending_date){
            if(eastEl > westEl){
                std::cout << date << " " << "East" << std::endl;
            } else if (westEl > eastEl){
                std::cout << date << " " << "West" << std::endl;
            } else {
                std::cout << date << " " << "Equal" << std::endl;
            }
        }
    }

    //close file
    water_data.close();

    return 0;
}

