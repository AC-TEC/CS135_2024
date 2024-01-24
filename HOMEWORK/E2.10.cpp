/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E2.10
DATE: 1/24/2024

ask user for # of gallons,gas price, & fuel efficiency then 
print cost per 100 miles and how far car can go with gas in tank
*/

#include <iostream>


int main(){
    //initialize variables
    //using double bc cost per gallon can be given in cents(decimals)
    int gallons_of_gas;
    double gas_price_per_gallon;
    double fuel_efficiency;

    //ask user for # of gallons,gas price, & fuel efficiency
    std::cout << "Number of gallons in the tank: ";
    std::cin >> gallons_of_gas;

    std::cout << "Fuel efficiency: ";
    std::cin >> fuel_efficiency;
    
    std::cout<< "Price of gas per gallon: ";
    std::cin >> gas_price_per_gallon;

    //just a space
    std::cout << std::endl;

    //calculate cost per miles and range of car with the gas in the tank
    //cost_per_miles = gas_price_per_gallon / fuel_efficiency;

    double cost_per_100_miles = ((gas_price_per_gallon / fuel_efficiency) * 100);
    double range = gallons_of_gas * fuel_efficiency;

    //print info
    std::cout << "Cost per 100 miles: $" << cost_per_100_miles << std::endl;
    std::cout << "Range: " << range << " miles" << std::endl;

    return 0;
}