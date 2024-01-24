/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E1.7
DATE: 1/24/2024

print three items(3 names or 3 movies) on three separate lines
*/

#include <iostream>
#include <string>


int main(){
    
    std::string name_1;
    std::string name_2;
    std::string name_3;

    //ask for 3 names
    std::cout << "Enter name 1: ";
    std::cin >> name_1;
    std::cout << "Enter name 2: ";
    std::cin >> name_2;
    std::cout << "Enter name 3: ";
    std::cin >> name_3;

    std::cout << std::endl; //just a space

    //print all names on separate lines;
    std::cout << name_1 << std::endl;
    std::cout << name_2 << std::endl;
    std::cout << name_3 << std::endl;

/*
OTHER WAY I HAD
    std::string names[3] = {"ANDY", "ANTHONY", "LESLY"}; //array of strings to store 3 names

    !!!itertate through array and print
    for (int i = 0; i <= 2 ; i++){
        std::cout << names[i] << std::endl;
    }
*/
//JI
    return 0;
}

