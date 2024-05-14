/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 13
DATE: 5/13/2024

Task A: Write a program that prints all numbers in range left to right, separated by spaces. (Don’t use loops, global or static variables.)

TASK B: Write a program to add the numbers from a given range. From left to right

*/
#include <iostream>

//?TASK A
//function to recursivly call range of given numbers
void printRange(int left, int right){
    
    //base case (used to stop)
    if (left > right){
        //returns nothing. just stops calling function again
        return;
    }

    if(left <= right){
        //call function recursively
        printRange(left,right - 1);
        
        //prints numbers in range
        std::cout << right << " ";
    }
}

//?TASK B
//function to recursivly add the numbers from a given range (left to right)
int sumRange(int left, int right){
    if (left > right){ //Base case
        return 0;
    } else{
        return left + sumRange(left + 1, right); //Recursion(Keeps on going until the base case is true)
    }
}



int main(){
    int left;
    int right;

//Test #1
    int x = sumRange(1, 3);
    std::cout << "This is " << x << std::endl;

//Test #2
    int y = sumRange(-2, 10);
    std::cout << "This is " << y << std::endl;
}


/*
!TASK A MAIN FUNCTION

int main(){
    //call recursive function
    printRange(-2, 10);
}

*/


/*
!TASK B MAIN FUNCTION

int main(){
    int left;
    int right;

//Test #1
    int x = sumRange(1, 3);
    std::cout << "This is " << x << std::endl;

//Test #2
    int y = sumRange(-2, 10);
    std::cout << "This is " << y << std::endl;
}

*/