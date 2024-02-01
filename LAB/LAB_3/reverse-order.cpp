/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 3
DATE: 1/31/2024

Task D: ask user for two dates(earlier then later date) & print west basin elevation
        for all days in reverse order (starting from later date to earlier)
*/


#include <iostream>
#include <string> 
#include <fstream> //to read file
#include <cstdlib> //to close() file


int main(){

    //open file
    std::ifstream water_data("Current_Reservoir_Levels.tsv");

    //If file fails to open print error message and exit
    if(water_data.fail()){
        std::cerr << "FILE FAILED TO OPEN!!!" << std::endl;
        exit(1);
    }

    //skip header line
    std::string junk_line;
    getline(water_data, junk_line);

    //get user input for dates
    std::string earlier_date;
    std::string later_date;

    std::cout << "Enter earlier date: ";
    std::cin >> earlier_date;
    std::cout << "Enter later date: ";
    std::cin >> later_date;

    //variables to store tsv file data
    std::string date;
    double westEl;

    //To store into arrays
    const int max_days = 365;  //max days in a year for size of array
    std::string dates[max_days]; //will store the dates data
    double elevation[max_days]; //will store the west basin elevation data
    int num_days = 0;  //track number of days in given date range



    //read each line of tsv file into variables
    while(water_data >> date >> junk_line >> junk_line >> junk_line >> westEl){
        //get date interval range
        if(date >= earlier_date && date <= later_date){
            
            //store date and elevation data in given date intervals (earlier date to later date)
            if (date >= earlier_date){
                dates[num_days] = date; //store the date into array
                elevation[num_days] = westEl; //store west elevation into array
                num_days++; //increment day count
            } else if (date <= later_date){
                dates[num_days] = date; 
                elevation[num_days] = westEl; 
                num_days++; 
            }
        }
    }

    //loop through dates and elevation arrays in reverse order & print
    for(int i = num_days - 1; i >= 0; i--){
        std::cout << dates[i] << " " << elevation[i] << " " << "ft" << std::endl;
    }

    //close the file
    water_data.close();
    return 0;
}
