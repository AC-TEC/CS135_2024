#include <iostream>

/*
?Question 1: 
Suppose class Dog is derived from class Animal, which class is a superclass

!Answer: 
Animal is the superclass
*/



/*
?Question 2:
Declare an array pf strings, call is Shapes. Initialize with "Square","Triangle"

!Answer:
Std::string Shapes[] = {"Square", "Triangle"};
*/


/*
?Question 3:
Write code to print 1,4,16,...,4^15, where the next item is four times of the previous one.

!answer:
#include <cmath>
int main(){
    the power raised is what changed
    for(int k = 0; k <= 15; k++){
        std::cout << std::pow(4,k) << " ";
    }
}
*/


/*
?QUESTION 4:
Given function  bool isPrime(n), which return true if n is a prime integer, false otherwise.
write code to find out how many prime integers are in [20,100]

!answer:

int main(){
    //counter
    int prime_counter = 0;

    for(int i = 20; i <= 100; i++){
        if(isPrime(i) == true){
            prime_counter++;
        }
    }
}
prints out 17
*/


/*
?Question 5:
Given int arr[] = {1,2,97}; and *p = arr; what is the value of *(p+1)+2?
Note that dereference operator * has higher precedence than tplus operator

!answer: 4
bc *(p+1) = arr[1] == 2 then + 2 means add element at index 1 in array plus 2. arr[1] + 2 -> 2+2 = 4
*/


/*
?Question 6:
Given a struct called Cat, which includes the following data members: breed as a string and weight as a double.
suppose mew is declared as a variable of Cat. write code to set the breed of mew to be "Ragdoll"

!answer : mew.breed = "Ragdoll"
*/


/*
?Question 7:
What is output for the following code?
    vector<int> nums;
    
    for (int i = 0; i < 10; i++)
        nums.push_back(i);

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] % 3 == 0)
            cout << nums[i] << endl;

!Answer: 
first loop: adds numbers 0-9 to vector means size of vector is 10
second for loop: iterates through vector(size 10) and checks each number to see if divisible by 3. if it is then it prints it in a new line

0
3
6
9
*/


/*
?Question 8:
Read the following code. What is the output?
    int arr[] = {2, 5, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size-1; i++)
        if (arr[i] > arr[i+1])
        swap(arr[i], arr[i+1]); //function to exchange two given parameters

    for (int i = 0; i < size; i++)
    cout << arr[i] << endl;

!answer: 
2
3
5
1
*/


/*
?Question 10:
Declare the header of a function called sort, which takes two float type numbers,
if the first one is larger than the second one, swap them. Return type is void. No
need to define the function, just define the header of the function.

!Answer: 

void sort(float& num1, float& num2);

using & bc we want to directly affect the nums passed in the parameters.
If we dont use & we will end up affecting a copy of them not the actual ones

*NA TOPIC: 2D ARRAYS
?(2)
Declare an int variable called it size and initialize it to be 15. Create a two-dimensional
dynamic allocated memory array, call it data, which has size rows, and row indexed at i
has (i+1) columns, where i is the index of row and starts from 0.

*/


/*
?Question 11
3. Define a class called Date, which includes data members, year and month, both as ints.
    • Data member year is an astronomical year, where year 0 means 1 BC, and counts
        negative years from 2 BC backward (−1 backward), so 100 BC is −99 (per wiki).
        So, year can be negative.
    • Data member month is an integer between 1 and 12.

Define a default constructor, set year to be 1900 and month to be 12


!answer:

class Date{
public:
    functions

private:
    int year;
    int month;
};

!actaul answer
Define a default constructor, set year to be 1900 and month to be 12
Date::Date(){
    year = 1900;
    month = 12;
}



Define method nextTwoMonth, which forward two months from current date. You need
to consider the case when current month is November, December, or other cases.
!answer:
    void nextTwoMonth(){
        increase two months
        month+= 2;

        for case november and december
        if (month > 12){
            month-=12;
            year++; since we will have crossed month 12 which means a new year
        }
    }

    ex: month = 11
        month = 11+2 = 13
        month = 13-12 = 1 and increase year

        month = 12
        month = 12+2 = 14
        month = 14-12 = 2 and increase year 
*/


