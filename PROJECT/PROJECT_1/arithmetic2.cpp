//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 1
//DATE: 2/8/2024
//Task B: Asks the user an amount of randomly generated math questions. 
//        Then calculates and prints the percentage user gets correct and gives the letter grade.


#include <iostream>
#include <cstdlib> // for rand()
#include <string>


int main(){

    //get number of questions to ask
    int num_of_questions;
    std::cout << "Enter the total number of questions to ask: ";
    std::cin >> num_of_questions;

    //if number of questions == negative number ask user to re-enter number
    while(num_of_questions <= 0){
        std::cout << "The number of questions cannot be zero or negative. Re-enter: ";
        std::cin >> num_of_questions;
    }


    //DECLARE VARIABLES

    //track the number of times user gets question correct(use to calculate percentage)
    double correct = 0; //double so i can get decimal for calculating percentage

    //seed random number generator using current time
    srand(time(0));

    //char array to hold the operations
    char operations[] = {'+','-','*','/','%'};

    //store random index for operations
    int random_index;

    //store first random number
    int random_num;

    //store second random number
    int second_operand;

    //store the random expression
    char expression_operation;

    //store expression as a string for outputting purposes
    std::string ep;

    //store result
    int result;
    
    //store user response
    int response;


    //!CODE BELOW FROM TASK A (asking questions with random generated integers and operations)
    //repeat the code below the amount of times the user inputs for num_of_questions
    for(int i = 0; i < num_of_questions; i++){

        //store random index for operations array range: [0,4]
        random_index = rand() % 5; 

        //first random integer range:[0,9]
        random_num = rand() % 10;  

        //store the random operation generated (array + random_index)
        expression_operation = operations[random_index]; 

        //if operation is '/' or '%' 2nd random integer range:[1,9] else range: [0,9]
        if(expression_operation == '/' || expression_operation == '%'){
            second_operand = rand() % 9 + 1; //[1,9] 
        } else {
            second_operand = rand() % 10; //[0,9]
        }

        //perform the operations and save the result
        switch (expression_operation) {
            case '+' :
                //store expression
                ep = std::to_string(random_num) + "+" + std::to_string(second_operand);
            
                //store the result
                result = random_num + second_operand;
                break;
        
            case '-' :
                ep = std::to_string(random_num)+ "-" + std::to_string(second_operand);
                result = random_num - second_operand;
                break;
        
            case '*' :
                ep = std::to_string(random_num)+ "*" + std::to_string(second_operand);
                result = random_num * second_operand;
                break;
        
            case '/' :
                ep = std::to_string(random_num)+ "/" + std::to_string(second_operand);
            
                //check for division by zero
                result = (second_operand != 0) ? (random_num / second_operand) : 0;
                break;
        
            case '%' :
                ep = std::to_string(random_num)+ "%" + std::to_string(second_operand);
            
                //check for division by zero
                result = (second_operand != 0) ? (random_num % second_operand) : 0;
                break;
        }


        //get user response
        std::cout << "what is " << ep << "? ";
        std::cin >> response;


        //track the number of times user gets question correct
        if(response == result){
            std::cout << "true" << std::endl;
            std::cout << std::endl;
            correct ++; //add to tracker
        } else {
            std::cout << "false" << std::endl;
            std::cout << std::endl;
        }

    }//end of for loop


    //calculate the percentage
    double percent_correct = ((correct/num_of_questions) * 100);

    //print out percentage
    std::cout << "percentage correct: " << percent_correct << "%" << std::endl;

    //give letter grades based on percentage
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


    return 0;
}