//Author: Andy Cocha
//Course: CSCI-135
//Instructor: Tong Yi
//Assignment: PROJECT 1
//DATE: 2/21/2024
//Task D: Read csv file containing arithmetic expressions and their answers.
//        Randomly display the questions then calculate the correct percentage and print the corresponding letter grade.
//        Stop if correct rate of 60% or higher is reached.



#include <iostream>
#include <string>
#include <fstream>  //to read csv file
#include <sstream>  //for string stream
#include <cstdlib>  //for close() function to close file at end and for rand()
#include <vector>
#include <ctime> // for the srand(time(0))

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


    //?seed random number generator using current time (new code)
    srand(time(0));


    //?set random index for expressions 
    int random_index; 


    //?vector to hold the expressions so we can randomize them with random_index
    std::vector<std::string> expressions_storage;


    //?vector to hold the csv given answers and use the same index that we used to generate the random expression from the vector
    //?which gets us the csv answer that matches that expression. EX: random_index = 3 -> use that as index to get the expression from the vector at index 3 and use that same random_index number to also get the csv given answer from the vector at index 3. which now solves the problem of not getting the answer that corresponds to the expression 
    std::vector <double> csv_answers_storage;


    //?variable to hold the current random expression
    std::string random_expression;


    //?variable to hold the current random answer
    double random_answer;


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

        //?add expressions to vector
        expressions_storage.push_back(csv_expression);

        //?add csv_given_answers to vector
        csv_answers_storage.push_back(csv_given_answer);

        //add to questions counter
        num_questions++;
    }
/*
im thinking what if we change the while loop to only read the data in the csv file
and then also store the expression into a vector

bc then we will have the vector filled with the questions plus we will also have the number of questions
without doing every other operation that we had before so we can do that after. 

by having the number of questions in while loop we can then use that number for our random index generator
since it will be different according to the csv file that the code will be tested with on gradescope

in order to keep it generating a new random index until we are done with questions. we can use a for loop
to keep on going until we reached the amount of questions in the csv file so for(int i = 0; i < num_questions; i++)
inside the for loop we can initialize the random_index variable and then also ask the questions and put the rest of the code inside it 
*/

    //?To randomize the questions order until we have reached the amount of questions found in csv file. Essentially giving us the amount of questions found in csv file but each one is a random one found in csv file
    //?EX: csv = 9 expressions. so for loop gonna iterate 9 times and give us 9 expressions in random order.
    for(int i = 0; i < num_questions; i++){
        //initialize random_index 
        random_index = rand() % num_questions;

        //?initialize the random expression and random answer variables to the same generated index
        random_expression = expressions_storage[random_index];
        random_answer = csv_answers_storage[random_index];

        //print out the expression and get user input
        std::cout << "What is " << random_expression << "? ";
        std::cin >> result_of_expression;

        //if user input matches generated random_answer(csv given answer), then print out true and add to counter else print false
        if(result_of_expression == random_answer){
            std::cout << "true" << std::endl;
            correct++;
        }else{
            std::cout << "false" << std::endl;
        }
        
        
        //calculate the percentage of correct answers
        double percent_correct = ((correct / num_questions) * 100);

        //check if percent_correct >= 60. If it is then print out statement and break from loop. else kepp on looping
        //close csv file too since we wont loop through other questions anymore
        if(percent_correct >= 60){
            //separation line
            std::cout << std::endl; 

            std::cout << "At least 60% is correct. " << "Stop.";
            break; 

            //close csv file
            //expressions_data.close();
        }

    }   
    //following code will happen if correct_percentage remains < 60. will have looped through all questions

    //serparation line
    std::cout << std::endl; 

    //calculate the percentage of correct answers
    double percent_correct = ((correct / num_questions) * 100);

    //check if percent_correct < 60. if it is then print out the percentage
    //we do this if statement so that it doesnt also print out the percentage when correct_percent is >= 60 only when its less.
    if(percent_correct < 60){
    //print out percentage
    std::cout << "percentage correct: " << percent_correct << "%";
    }



    //close csv file
    expressions_data.close();

    return 0;
}





/*

!worked(UPDATED 2/23/2024)

plan to generate a random expression from the csv file

    -seed random number generator

    -set a random index for expressions (but we need to use the amount of questions we wont know how many there are though)

    -read the expression and store it into an array or vector

    -then use random_index to get a random expression that is stored in the array or vector

* I believe a vector would be best to use since we wont have to specify the size of it. since in the gradescope test we can see that the csv test files will have different amount of questions in them


!worked(UPDATED 2/23/2024)
*IDEA CAME TO ME WHILE GETTING OFF THE TRAIN ON MY WAY TO COLLEGE
plan to generate the csv_given answer that corresponds to the generated random expression
    -make a vector to store the csv_given_answer

    -in the while loop that reads csv data keep on adding the csv_given_answer to the vector

    -use the random_index to get the csv_given_answer that is stored in the vector which is the same one that also is used to get the expression that is stored in its own vector
        essentially getting the correct answer for each randomly generated expression

    

*/


/*
PLAN TO STOP GENERATING QUESTIONS WHEN WE REACH CORRECT RATE OF 60% OR HIGHER

    -change for loop that generates the random expressions a do while loop

    -make a counter and initialize to zero and keep on adding to it everytime we loop. so that we can stop once we reach the amount of questions found in csv file

    -condition of do-while loop: counter < num_questions && stop once correct percentage reaches 60%. 




-ohhhhhhhh yeah since the amount of questions is not in the same loop of the code that calulates the percentage we can now put the calculation of percentage in the loop and keep it going until we reach 60% or higher
    so we can keep on calculating the percentage over and over again and if it reaches 60% we can use break to stop and end the loop


    -move code to calculate percentage into for loop

    -if statment to check if correct percentage is 60% or greater.

    -if so print a statment saying we reached that correct rate

    -use break to stop for loop.

    -if dont reach that percentage loop is going to keep on going
*/


/*

!I believe the reason why its not accepting on gradescope is bc when i print the expressions some keep on repeating. I believe that gradescope does not want any repeat randomly generated expressions.
!so make an expression on appear once. no repeats. i believe if i do this then it might gert fixed. 2/23/2024 10:20pm

*/





/*
*TASK D PROJECT 1 CODE WITH ALL NOTES MADE WHEN FINALLY GETTING IT (VERSION ON GRADESCOPE IS CLEANED UP VERSION SO THAT ONE DOESNT HAVE ALL NOTES OF MY THINKING BUT IT DOES HAVE GOOD AMOUNT)
*THE FOLLOWING WILL BE A MORE DETAIL EXPLAINATION ALSO THE ONE ABOVE IS ALSO SHOWING MORE OF MY THINKING PROCESS. WHICH HELPED ME ALOT TO BUILD OFF THIS PROJECT. AND THOSE NOTES ARE FROMM BEFORE PROFESSOR SAID IT TO SPECIFICALLY DO IT HER WAY


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
#include <ctime> // for the srand(time(0))


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
    
    //double result_of_expression; //actual answer
    
    double csv_given_answer;    //csv given answer

    //track number of times answer is correct
    double correct = 0;

    //track the number of questions
    int num_questions = 0; //(size)


    //?seed random number generator using current time (new code)
    srand(time(0));


   //?vector to hold the expressions so we can randomize them with random_index
    std::vector<std::string> expressions_storage;


    //?vector to hold the csv given answers and use the same index that we used to generate the random expression from the vector
    //?which gets us the csv answer that matches that expression. EX: random_index = 3 -> use that as index to get the expression from the vector at index 3 and use that same random_index number to also get the csv given answer from the vector at index 3. which now solves the problem of not getting the answer that corresponds to the expression 
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

        //?add expressions to vector
        expressions_storage.push_back(csv_expression);

        //?add csv_given_answers to vector
        csv_answers_storage.push_back(csv_given_answer);

        //add to questions counter
        num_questions++;
    }

    //close csv file
    expressions_data.close();


    //iterate until vectors are empty
    while(!expressions_storage.empty()){
        //initialize random index (do it by vector since we gonna reduce it each time prof hint: size is deducted by 1)
        int random_index = rand() % expressions_storage.size(); ///not doing it for answers vector since that will match the expressions one so dont matter

        //initialize the random_expression and random_answer with random_index to generate the randomized expression and answer that goes with it
        
        double result_of_expression; //hold user input

        //print out expression and get user input
        std::cout << "What is " << expressions_storage[random_index] << "? ";
        std::cin >> result_of_expression;

        //check if user answer matches with the csv given answer for generated expression
        if(result_of_expression == csv_answers_storage[random_index]){
            //print out true and add to correct counter
            std::cout << "true" << std::endl;
            correct++;
        }else{
            std::cout << "false" << std::endl;
        }


        //calculate percentage
        double percent_correct = ((correct/num_questions) * 100);


        //swap the chose problem with the problem in the last index of vector and deduce size of vectors(this will also affect the interval of numbers to choose from in random_index)
        std::swap(expressions_storage[random_index], expressions_storage.back());
        std::swap(csv_answers_storage[random_index], csv_answers_storage.back());  

        //will deduce size of vectors
        expressions_storage.pop_back();
        csv_answers_storage.pop_back();


        //check if percent_correct is >= 60. if it is then break out of while loop and print message
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
    //we do this if statement so that it doesnt also print out the percentage when correct_percent is >= 60 only when its less.
    if(percent_correct < 60){
    std::cout << std::endl; //separation line
    //print out percentage
    std::cout << "percentage correct: " << percent_correct << "%";
    }

    return 0;
}



*/








