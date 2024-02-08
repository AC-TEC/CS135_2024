
//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 1
//DATE: 2/7/2024
//Task A: Generate two random integers and a random operator. The user will then be prompted to give a response to the randomly generated expression.
//        Then we check if the user response to the expression is correct and prompt to the user true or false based on their answer. 


#include <iostream>
#include <cstdlib> //for rand() 
#include <string>

int main(){

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


    //check if user response is correct
    if(response == result){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}


