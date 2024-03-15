//*REDOING MY SPRING 2023 CS135 MIDTERM

//? QUESTION 1

/*
write a function double foo(double n, double k) that calculates (1+n)^k/sqrt(k+1)

#include <iostream>
#include <cmath>

double foo(double n, double k){
    return std::pow((1+n),k)/std::sqrt(k+1);
}


int main(){
    double exponent; //k
    double number; //n

    std::cout << "Enter number: ";
    std::cin >> number;

    std::cout << "Enter exponent: ";
    std::cin >> exponent;


    //call funtion
    std::cout << "RESULT: " << foo(number,exponent) << std::endl;
}

*/

//? QUESTION 2  (A-E) terminal questions


//? QUESTION 3
/*
    What is the output of the following code snippet
    int my_int = 5;
    int* my_ptr = & my_int;         my_ptr hold 5
    my_int = 20;                    my_int is now 20 which means my_ptr holds 20
    *my_ptr = 15;                   my_ptr now hold 15
    int* another_ptr = my_ptr;      another_pointer now holds my_ptr which holds the value 15
    cout << *another_ptr << endl;  

    !OUTPUT = 15
*/


//? QUESTION 4 (makign conditions based off given variables)


//? QUESTION 5

/*


write a function : string remove_e(string & text) that removes all occurences of the letter 'e'
from string text.

#include <iostream>
#include <string>
using namespace std;


string remove_e(string& text){
    string new_string = "";

    //loop through given text and look for e
    for(int i = 0; i < text.length(); i++){
        //if caracter is not e then add to new string. If it is 'e' then it just wont add it to new string.
        //essentially removing all occurances of 'e' from the string
        if(text[i] != 'e'){
            new_string += text[i];
        }
    }
    //returns string without e
    return new_string;
}



int main(){
    string my_text = "Hello Universe.";
    cout << remove_e(my_text) << endl;
    return 0;
}

*/



//? QUESTION 6

/*
Write a program that asks the user for a positive integer height. If they enter an illegal value, they must
be prompted to enter a good one until they do. It then prints an equalateral right triangle of stars
of that height. If the height is 6, the program should print.
        *
       **
      ***
     ****
    *****
   ******


#include <iostream>


int main(){
    int height; //rows

    std::cout << "Enter height: ";
    std::cin >> height;
    while(height <= 0){
        std::cout << "Enter height: ";
        std::cin >> height;
    }
    
    
    OTHER WAY TO REPEAT WHEN INVALID HEIGHT
    repeat asking for height if number entered is illegal
    do{
        std::cout << "Enter height: ";
        std::cin >> height;
    }
    while(height <= 0);
    
    
    int width = height; //will iterate through col 
    
    int dummy_width = width-1;
    //loop though height
    for(int row = 0; row < height; row++){
        //loop though the columns(width)
        for(int col = 0; col < width; col++){
            //condition to print only at the ends a asterisks
                if(col >= dummy_width){
                    std::cout << "*";
                }else{
                    std::cout << " ";
                }
        }
        dummy_width--;
        //move to next line
        std::cout << std::endl;
    }
    
    return 0;
}

*/

