/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 7
DATE: 2/26/2024

Task B:
*/

#include <iostream>
#include <string>

//function to count how many times a character appears
int countChar(std::string line, char c){
    //need counter to track number of occurrences
    int counter = 0;

    //iterate through the line
    for(int i = 0; i < line.length(); i++){
        //check if character at current index matches the character given
        if(line[i] == c){
            //add to counter
            counter++;
        }
    }

    //return the amount of occurences
    return counter;
}


//we need to enhance this part from the last task apparently 
std::string removeLeadingSpaces(std::string line){
    //store the new line
    std::string modified_line;

    //counter to track indentations
    int open_curly_brace = 0;

    //read each line
    while(getline(std::cin, line)){

        //index for characters
        int index = 0;

        //check if character at index is a space
        while(isspace(line[index])){
            //increment until we get to a non space character
            index++;
        }

        //update indentation tracker based on the count of '{' and '}' characters
        open_curly_brace += countChar(line,'{') - countChar(line, '}');

        //print number of tabs based off open curly braces
        for(int i = 0; i < open_curly_brace; i++){
            std::cout << "\t";
        }


        //Adjust indent when line ends with '}'
        if(line[line.length() - 1] == '}'){
            open_curly_brace--;
        }

        //store characters that are not spaces(without indentation) starting from incremented index index
        modified_line = line.substr(index);

        //print out the rest of the string that doesnt include space characters in the beginning
        std::cout << modified_line << std::endl;

    }

    return modified_line;
}


int main(){
    std::string line;

    removeLeadingSpaces(line);
}


/*
    std::string line;

    //go through each line
    while(getline(std::cin,line)){
        //prints out character count and the line
        std::cout << countChar(line,'{') << " " << line << std::endl;
    }
*/