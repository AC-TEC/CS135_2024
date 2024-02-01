/*
Author: Andy Cocha
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
#include <sstream> // to parse each data(column) from each line (row)

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
    std::string line;
    std::string date;
    double eastEl;
    double westEl;


    //parse through tsv file 
    while(getline(water_data,line)){
        //create a input stream to go through each column data
        std::istringstream column(line);

        //get first column data (date)
        column >> date;
        //skip other column
        column >> junk_line;
        //get east elevation data
        column >> eastEl;
        //skip other column
        column >> junk_line;
        //get west elevation data
        column >> westEl;
    
        //
        if (date >= starting_date && date <= ending_date) {
            //compare the elevation levels and print out the higher one
            if(eastEl < westEl){
                std::cout << date << " " << "West" << std::endl;
            } else if (westEl < eastEl){
                std::cout << date << " " << "East" << std::endl;
            } else {
                std::cout << date << " " << "Equal" << std::endl;
            }
        }
    }

    //close file
    water_data.close();

    return 0;
}










/*

?other easier method (wont need to include sstream library)
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
*/