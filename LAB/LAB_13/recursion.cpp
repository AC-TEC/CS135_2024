/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 13
DATE: 5/13/2024

Task A: Write a program that prints all numbers in range left to right, separated by spaces. (Don’t use loops, global or static variables.)

TASK B: Write a program to add the numbers from a given range. From left to right

TASK C: Write a program to return the sum of all elements in a array.
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


//?TASK C

//helper function
int sumArrayInRange(int *arr, int left, int right){
    if (left > right){ //base case
        return 0; // returns 0 for empty range
    } else{
        return arr[left] + sumArrayInRange(arr, left + 1, right);  // add the leftmost element and recurse on the rest of the range
    }
}

//returns sum of all elements in array
int sumArray(int *arr, int size){
    return sumArrayInRange(arr,0,size - 1); // call the helper function sumArrayInRange on the whole array
}



int main() {

    int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size); // Add all elements
    std::cout << "Sum is " << sum1 << std::endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    std::cout << "Sum is " << sum2 << std::endl;  // Sum is 34

    delete[] arr;         // deallocate it
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