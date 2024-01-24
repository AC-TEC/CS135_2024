/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 1
DATE: 1/24/2024
,.
Task C: print out if input year is a leap or common year

*/
#include <iostream>

int main(){
    //! Task C
    int year;
    //get user input
    std::cout << "Enter year: ";
    std:: cin >> year;

    //determine whether input year is a leap or common year
    //print out leap or common year accordingly

    // 100 to not include years that are divisible 100 therefor exluding century years unless they are divisble by 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){ //test with 400 for century years 
        std::cout << "Leap year" << std::endl;
    } else if ((year % 4 != 0) || (year % 100 == 0)){
        std::cout << "Common year" << std::endl;
    } else {
        std::cout << "Leap year" << std::endl; //used else for leap year bc of way pseudo code or lab is written but dont need it 
    }
    return 0; //to show program executes correctly

}