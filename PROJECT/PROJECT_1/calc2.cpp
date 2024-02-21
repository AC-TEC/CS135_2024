//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 1
//DATE: 2/13/2024
//Task C: Read csv file containing arithmetic expressions and their answers.
//        Then calculate the correct percentage and print the corresponding letter grade


#include <iostream>
#include <string>
#include <fstream>  //to read csv file
#include <sstream>  //for string stream
#include <cstdlib>  //for close() function to close file at end

int main(){

    //Open csv file
    std::ifstream expressions_data("arithmetic_expressions.csv");

    //If file fails to open display error message
    if(expressions_data.fail()){
        std::cerr << "FILE FAILED TO OPEN!!!!" << std::endl;
        exit(1); //exit file
    }

    //Variables to store data from csv file
    std::string csv_expression;  //store the expression
    double result_of_expression; //actual answer
    double csv_given_answer;    //csv given answer

    //track number of times answer is correct
    double correct = 0;

    //track the number of questions
    int num_questions = 0;


    //will be used to store each line(row) from file
    std::string line;


    //read each line(row) individually from csv file
    while(std::getline(expressions_data,line)){
        
        //extract data from each column in each line(row) from csv file
        std::istringstream column(line);

        //read the expression as a whole line until we reach the comma (delimiter: ',')
        std::getline(column, csv_expression, ',');

        //read the csv given answer 
        column >> csv_given_answer;


        //print out the expression and get user input
        std::cout << "What is " << csv_expression << "? ";
        std::cin >> result_of_expression;


        //if user input matches csv given answer, then print out true and add to counter else print false
        if(result_of_expression == csv_given_answer){
            std::cout << "true" << std::endl;
            correct++;
            num_questions++; //add to questions counter
        }else{
            std::cout << "false" << std::endl;
            num_questions++; //add to questions counter 
        }
    }


    //calculate the percentage of correct answers
    double percent_correct = ((correct / num_questions) * 100);

    //print out percentage
    std::cout << "percentage correct: " << percent_correct << "%" << std::endl;

    //calculate letter grade based off percentage
    char grade;
    if (percent_correct >= 90) {
        grade = 'A';
    } else if (percent_correct >= 80) {
        grade = 'B';
    } else if (percent_correct >= 70) {
        grade = 'C';
    } else if (percent_correct >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    std::cout << "letter grade: " << grade << std::endl;

    //close csv file
    expressions_data.close();

    return 0;
}

