/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 1
DATE: 1/24/2024

Task B: find the smaller of the three integer numbers
*/


#include <iostream>
#include <string>

int main(){

//* Task B

    int first_num;
    int second_num;
    int third_num;

//ask for numbers
    std::cout << "Enter the first number: ";
    std::cin >> first_num;
    std::cout << "Enter the second number: ";
    std::cin >> second_num;
    std::cout << "Enter the third number: ";
    std::cin >> third_num;

//compare numbers and print out the smaller number
    if(first_num < second_num && first_num < third_num){
        std::cout << "The smaller of the three is " << first_num << std::endl;
    } else if (second_num < first_num && second_num < third_num){
        std::cout << "The smaller of the three is " << second_num << std::endl;
    } else if (third_num < second_num && third_num < first_num){
        std::cout << "The smaller of the three is " << third_num << std::endl;
    } else{
        std::cout << "All numbers are equal."<<std::endl;
    }
    
    return 0;

    //other more efficient method(using terany operator)
    //int smallest_num = (first_num < second_num) ? (first_num < third_num ? first_num : third_num) : (second_num < third_num ? second_num : third_num);
    //checks first condition then if true then the condition on the left executes. if first condition false then condition far right executes.
    // int smallest_num will end up containing the number that is true inside of the 2nd conditions so either from (first_num < third_num ? first_num : third_num) : (second_num < third_num ? second_num : third_num);

}