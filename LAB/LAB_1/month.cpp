/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 1
DATE: 1/24/2024

Task D: ask user to input year and month and prints number of days in that month (account with leap years) (no swicth case or arrays)
*/


#include <iostream>

int main(){
//?  Task D
    int input_year;
    int month;

    //get user input
    std::cout << "Enter year: ";
    std::cin >> input_year;
    std::cout << "Enter month: ";
    std::cin >> month;
    

    //determine number of days in a given month according to year
    if ((input_year % 4 == 0 && input_year % 100 != 0) || (input_year % 400 == 0)){   //leap year 
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){ //knuckle bump months
            std::cout << "31 days" << std::endl;
        } else if (month == 4 || month == 6 || month == 9 || month == 11){ //knuckle gap months
            std::cout << "30 days" << std::endl;
        } else{
            std::cout << "29 days" << std::endl; //exception month (FEBRUARY)
        }
    } else{ //common year
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){ //knuckle bump months
            std::cout << "31 days" << std::endl;
        } else if (month == 4 || month == 6 || month == 9 || month == 11){ //knuckle gap months
            std::cout << "30 days" << std::endl;
        } else{
            std::cout << "28 days" << std::endl; //exception month (FEBRUARY)
        }
    } 

    return 0;
}