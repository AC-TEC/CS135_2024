/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 3
DATE: 1/30/2024

Task B: find the minimum and maximum storage in East Basin in 2018

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream> //help extract data from a string


int main(){
    //open file
    std::ifstream water_data("Current_Reservoir_Levels.tsv");

    //If file does not open print error message and exit
    if(water_data.fail()){
        std::cerr << "FILE FAILED TO OPEN!!!!" << std::endl;
        exit(1);
    }

    //skip header line (first row in tsv file)
    std::string junk;
    std::getline(water_data,junk);


    //variables to store tsv file data
    std::string date;
    double eastSt; 


    //Variables to track min & max value as we read file line by line
    double min_value = 99999999999999999.0;
    double max_value = -99999999999999999.0;


    std::string line; //will be used to store line(row) from file
    
    //read each line(row) individually from file
    while(std::getline(water_data, line)){  

        //create a input stream to go through each column data
        std::istringstream column(line);

        //read first column data (date) & not use it
        column >> date;

        //read next column data (east storage numbers)
        if(column >> eastSt){
            //compare value and replace the min and max values
            if(eastSt < min_value){
                min_value = eastSt;
            } 
            
            if(eastSt > max_value) {
                max_value = eastSt;
            }
        }
    }

    //print out max and min
    std::cout << "minimum storage in East basin: " << min_value << " billion gallons" << std::endl;
    std::cout << "MAXimum storage in East basin: " << max_value << " billion gallons"<< std::endl;

    //close file
    water_data.close();

    return 0;
}

