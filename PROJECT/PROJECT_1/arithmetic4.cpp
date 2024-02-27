//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 1
//DATE: 2/26/2024
//Task D: Read csv file containing arithmetic expressions and their answers.
//        Randomly display the questions then calculate the correct percentage and print the corresponding letter grade.
//        Stop if correct rate of 60% or higher is reached.



#include <iostream>
#include <string>
#include <fstream>  //to read csv file
#include <sstream>  //for string stream
#include <cstdlib>  //for close() function to close file at end and for rand()
#include <vector>
#include <ctime>    //for the srand(time(0))


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
    
    double result_of_expression; //user answer


    double csv_given_answer;    //csv given answer


    //track number of times answer is correct
    double correct = 0;


    //track the number of questions
    int num_questions = 0; //(size)


    //seed random number generator 
    srand(time(0));


   //vector to hold the expressions so we can randomize them with random_index
    std::vector<std::string> expressions_storage;


    //vector to hold the csv given answers and use the same index that we used to generate the random expression from the vector
    std::vector <double> csv_answers_storage;


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


        //add expressions to vector
        expressions_storage.push_back(csv_expression);


        //add csv_given_answers to vector
        csv_answers_storage.push_back(csv_given_answer);


        //add to questions counter
        num_questions++;
    }


    //close csv file
    expressions_data.close();


    //iterate until vectors are empty
    while(!expressions_storage.empty()){


        //initialize random index (size of vector bc will be reduced after each iteration)
        int random_index = rand() % expressions_storage.size(); 


        //generate random expression and print out expression and get user input
        std::cout << "What is " << expressions_storage[random_index] << "? ";
        std::cin >> result_of_expression;


        //check if user answer matches with the randomly generated csv given answer for generated expression
        if(result_of_expression == csv_answers_storage[random_index]){
            //print out true and add to correct counter
            std::cout << "true" << std::endl;
            correct++;
        }else{
            std::cout << "false" << std::endl;
        }


        //calculate percentage
        double percent_correct = ((correct/num_questions) * 100);


        //swap the chose problem with the problem in the last index of vector 
        std::swap(expressions_storage[random_index], expressions_storage.back());
        std::swap(csv_answers_storage[random_index], csv_answers_storage.back());  


        //deduce size of vectors (this will also affect the interval of numbers to choose from in random_index)
        expressions_storage.pop_back();
        csv_answers_storage.pop_back();


        //check if percent_correct is >= 60. if it is then print percentage, a message and break out of while loop
        if(percent_correct >= 60){
            std::cout << std::endl; //separation line
            
            std::cout << " percentage: " << percent_correct << std::endl;
            std::cout << "At least 60% is correct Stop.";
            break;
        }

    }

    //following code will happen if correct_percentage remains < 60. will have looped through all questions

    //calculate the percentage of correct answers
    double percent_correct = ((correct / num_questions) * 100);

    //check if percent_correct < 60. if it is then print out the percentage
    if(percent_correct < 60){
    std::cout << std::endl; //separation line
    std::cout << "percentage correct: " << percent_correct << "%";
    }

    return 0;
}

