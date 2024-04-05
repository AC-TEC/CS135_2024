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


//*MIDETERM OF CS135 V1 OCTOBER 16,2023

//! QUESTION 1

/*
Given int arr[] = {-1,6,5,3}, what is arr[2]?


#include <iostream>
int main(){
    int arr[] = {-1,6,5,3};
    std::cout << "ANSWER: " << arr[2] << std::endl;
    //The value at arr[2] == 5
}

*/


//! QUESTION 2

/*
Declare function foo whose first formal parameter is a double variable named d (pass by reference) and second
formal parameter is an int variable named i (pass by value) and there is no return type. You just need to
write the function header, no implementation is needed.


#include <iostream>
void foo (double& d, int i);

*/


//! QUESTION 3

/*
What does rand() % 3 + 2 produce?

Answer: An interval of numbers from [2,4] this is my response and it is correct

Breakdown: rand() % 3 generates a random integer from 0-3 not including 3 so it would be [0,1,2].
            + 2 would add 2 to each number being generated making them [2,3,4]
*/


//! QEUSTION 4

/*
Given string greeting = "Wonderful"; What is the value for greeting.substr(2, 4)?


#include <iostream>
#include <string>

int main(){
    std::string greeting = "Wonderful";
    std::cout << greeting.substr(2,4) << std::endl;
    //outputs: from 2nd index and 4 characters in length starting from there on(2nd index included) so output is nder
}

*/


//! QUESTION 5

/*
Suppose a runnable file is prog, write command to run it and redirect input from data.txt.
prog < data.txt
*/

//! Question 6

/*

What is the value of 2 + 1 / 2 * 6.0?


#include <iostream>
int main(){
    std::cout << "TOGETHER: " << 2 + 1 / 2 * 6.0 << std::endl;
    ?P.E.M.D.A.S

    2 * 6.0 = 12
    1 / 12 = 0.08333 == 0 bc when doing division we dont count the remainder
    2+0 = 2 

    ?FINAL ANSWER = 2
}

*/


//! QUESTION 7

/*
Suppose n is 234, what the value of digit after the following two statements?

n /= 10;  (x /= y ->  x = x/y )   n = n/10 ->  n = 234/10 --->  n == 23     / we care about quotient not remainder
digit = n % 10;     digit == 3     bc % we care about remainder
final answer: digit is 3
*/


//! QUESTION 8
/*
What is the output of the following code?
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = -6; i < 2; i += 2)
        sum += i;
    cout << sum << endl;
    return 0;
}

sum = 0     i = -6
sum = -6    i = -4
sum = -10   i = -2
sum = -12   i = 0
sum = -12   i = 2 (STOP AND DONT ADD TO SUM BC i == 2 and stops when i < 2)

FINAL ANSWER: -12
*/

//! QUESTION 9
/*

What is output for the following code?
    int a = 5;     //a = 5
    int* p = &a;  // p = 5 bc pointing to a
    *p += 3;       //p = 8 bc 5+3=8
    cout << a << endl;   //a = 8 bc in prev line we manipulated a through the p pointer

Answer: 8
*/

//! QUESTION 10
/*
What is the output for the following code?
#include <iostream>
using namespace std;

void foo(int& a, int& b);

int main() {
    int i = 0;
    int j = 3;

    foo(i, j);

    cout << "i = " << i << ", j = " << j << endl;
    return 0;
}

void foo(int& a, int& b) {
    if (a < b) {
    a++;
    b--;
}

}

ANSWER: i =  1      j = 2

*/


//! QUESTION 11 
/*
Write code to calculate a
b+
√
3c, and put the result to variable c. Assume that a, b, and c are properly defined
and initialized double number. Hints: you may use pow and sqrt function.


#include <iostream>
#include <cmath>

int main(){
    std::cout << pow(3,2) + sqrt((3*6));
}

*/



//! QUESTION 13

/*
Write code in main to read a string (may contain spaces) from console, find out and print out the number of
letter ’a’ in it. For example, suppose we enter “apple orange”, then print out 2.
Here is a sample input/output:
Enter a string: apple orange
appearances of a: 2

#include <iostream>
#include <string>

int main(){
    std::string given_string;

    std::cout << "Enter a string: ";
    std::getline(std::cin, given_string);

    int counter_of_a = 0;

    for(int i = 0; i < given_string.length(); i++){
        if(given_string[i] == 'a'){
            counter_of_a ++;
        }
    }

    std::cout << "Apperances: " << counter_of_a << std::endl;
    return 0;
}
*/

//! QUESTION 14

/*
Define a function, for a given array of integers and its size, find out whether all its elements are even or not.
For example, call the above function on array with values 1, 2, 3, the return is false. Call the above function
on array with values 2, 6, 8, 10, the return is true.


#include <iostream>

bool isEven(int arr[], int size_of_array){
    for(int i = 0; i < size_of_array; i++){
        if(arr[i] % 2 != 0){
            return false;
        }
    }

    return true;
}


int main(){
    int arr[] = {2,6,8,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool check = isEven(arr,size);

    if(check == 1){
        std::cout << "TRUE" << std::endl;
    }else{
        std::cout << "FALSE" << std::endl;
    }

    return 0;
}

*/


//! QUESTION 15

/*
Define a function named range, for a given array of integers and its size, return the difference of its
largest and smallest elements.


#include <iostream>

int difference(int arr[], int size_arr){
    int min = arr[0]; // -2
    int max = arr[0]; // 6 9

    for(int i = 0; i < size_arr; i++){
        if(arr[i] < min){
            min = arr[i];
        }else if(arr[i] > max){
            max = arr[i];
        }
    }

    //get difference
    int diff = max - min; //9-(-2) = 9+2 = 11

    return diff;
}

int main(){
    int arr[] = {1, -2, 6, 9};
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    std::cout << "size of array: " << size_of_array << std::endl;

    int diff = difference(arr,size_of_array);

    std::cout << "DIFFERENCE: " << diff << std::endl;
}

*/


//! QUESTION 16

/*
Define a function, for a given string, return a string without digital letters in the original string.
For example, call the above function on “hello123, h1o2w a3r4e y5ou?”, the return is “hello, how are you?”.
You may use int isdigit ( int c ); to test whether character is a decimal digit or not.


#include <iostream>
#include <string>
#include <cctype>

std::string remove_numbers(std::string given_string){
    std::string no_numbers_string = "";

    //iterate through string and check if not a number
    //if its not then add to no_numbers_string.
    for(int i = 0; i < given_string.length(); i++){
        if(!isdigit(given_string[i])){
            no_numbers_string += given_string[i];
        }
    }

    return no_numbers_string;
}


int main(){
    std::string get_string;
    std::cout << "Enter string: ";
    std::getline(std::cin, get_string);

    //call function and print
    std::string updated = remove_numbers(get_string);

    std::cout << "NEW STRING: " << updated << std::endl;
    return 0;
}

*/


//?DOING AMAZING
