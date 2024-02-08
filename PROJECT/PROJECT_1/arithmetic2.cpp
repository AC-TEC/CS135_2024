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


    //!CODE BELOW FROM TASK A (asking questions with random generated integers and operations)

    //track the number of times user gets question correct(use to calculate percentage)
    double correct = 0; //double so i can be able to get decimal for calculating percentage 

    //repeat the code below the amount of times the user inputs for num_of_questions
    for(int i = 0; i < num_of_questions; i++){
        
        //char array to hold the operations
        char operations[] = {'+','-','*','/','%'};

        //seed random number generator with current time
        srand(static_cast<unsigned int>(time(nullptr)));

        //store random index for operations array range: [0,4]
        int random_index = rand() % 5;

        //first random integer range:[0,9]
        int random_num = rand() % 10; 
    
        //variable to store second random integer
        int second_operand;  

        //store the random operation generated (array + random_index)
        char expression_operation = operations[random_index]; 

        //if operation is '/' or '%' 2nd random integer range:[1,9] else range: [0,9]
        if(expression_operation == '/' || expression_operation == '%'){
            second_operand = rand() % 10 + 1; //[1,9]
        } else {
            second_operand = rand() % 10; //[0,9]
        }

        //perform the operations and save the result
        std::string ep; //stores the expression as a string for outputting purposes
        int result;
    
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
        int response;
        std::cout << "what is " << ep << "? ";
        std::cin >> response;


        //track the number of times user gets question correct
        //check if user response is correct
        if(response == result){
            std::cout << "true" << std::endl;
            correct ++; //add to tracker
        } else {
            std::cout << "false" << std::endl;
        }


    }//end of for loop

    //space for separation
    std::cout << std::endl;

    //calculate the percentage
    double percent_correct = ((correct/num_of_questions) * 100);

    //print out percentage
    std::cout << "percentage correct: " << percent_correct << "%" << std::endl;


    //array of letter grade characters
    char grades[] = { 'A', 'B', 'C', 'D', 'F' };

    //give letter grades based on percentage
    if(percent_correct >= 90){
        //letter grade: A
        std::cout << "letter grade: " << grades[0] << std::endl;

    } else if(percent_correct < 90 && percent_correct >= 80){
        //letter grade: B
        std::cout << "letter grade: " << grades[1] << std::endl;

    }else if(percent_correct < 80 && percent_correct >= 70){
        //letter grade: C
        std::cout << "letter grade: " << grades[2] << std::endl;

    } else if(percent_correct < 70 && percent_correct >= 60) {
        //letter grade: D
        std::cout << "letter grade: " << grades[3] << std::endl;
    } else {
        //letter grade: F
        std::cout << "letter grade: " << grades[4] << std::endl;
    }

}