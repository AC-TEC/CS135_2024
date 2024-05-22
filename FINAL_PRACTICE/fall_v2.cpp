//*SKIPPING PART 1




//*PART 2 (10 POINTS) Answer the following questions


/*
?Question 1:
Define a function, for an given array of integers with its size, return number of elements that is positive.
For example, call the function with array with values −1, 0, −2, 0, 6, the size of array is 5, then the return is 1.

!answer:
parameters: int arr[] -> array holding integer
            int size -> size of the array

int positiveNums(int arr[], int szie){
    //counter for positive numbers
    int positive_nums = 0;

    //iterate through array and add to counter of element is a positve number
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            positive_nums++;
        }
    }

    //returns amount of positive numbers in the given array
    return positive_nums
}

*/




/*
?Question 2:

Define function void sortByLenRev(string* a, string* b), if the length of ∗a is smaller than the length
of ∗b, swap ∗a with ∗b, otherwise, do nothing. Note that dereference operator * has lower precedence than
dot operator.

!answer:

void sortByLenRev(std::string *a, std::string *b){
    if((*a).length() < (*b).length()){
        std::swap(*a,*b);
    }
}


//could also use .size() but either works for strings

*/



//*part 3 (20 points) programing exercises

/*
?Question 1:

Define a function, for a given string, if it contains at least a letter and a special symbol in $, #,or !, return
true, otherwise, return false.

For example, for string “abc”, the return is false. For string “#!”, the return is false. For “a!”, the return is
true. For “!a”, the return is true.

Hint: you might use isalpha to check whether a charcter is a letter (alphabetic) or not.
int isalpha ( int c ); Check if character is alphabetic

You can count the number of occurrences of letters and number of occurrences of special symbols.



!answer:

bool CharacterAndSpecial(std::string input_string){

    //counter for characters and special characters
    int characters = 0;
    int special_characters = 0;

    //iterate through the string
    for(int i 0; i < input_string.length(); i++){
        //check if we have a character is so then add to character counter
        if(isalpha(input_string[i])){
            characters++;
        }

        //chech if its one of the special characters ($,# or !) if so then add to special_characters counter
        if(input_string[i] == '$' || input_string[i] == '#' || input_string[i] == '!'){
            special_characters++;
        }
    }


    //check if we have both a character and a special character in string
    //return true if string had both
    if(characters > 0 && special_characters > 0){
        return true;
    }

    //return false if string did not have both
    return false;
}

*/


/*
?Question 2:

same as v1

*/



//*part 4 (10 points) write codes of vector

/*
?Question 1:

Define a function, for a given vector of strings, return a vector of all strings with odd length.
For example, call the above function on a vector of strings with values “ab”, “ccd”, “abcd”, the return is a
vector of strings with value “ccd”.

!answer:

//return type is vector so data type for function is vector of strings
//parameter is vector of strings too


std::vector<std::string> oddStrings(std::vector<std::string> input_vector){
    //string vector to hold the odd strings
    std::vector<std::string> onlyOddStrings;

    //iterate through the given vector
    for(int i = 0; i < input_vector.size(); i++){
        //check if the string inside the vector is odd length
        //saying if size is not divisible by 2(aka even) add to onlyOddStrins vector
        if(input_vector[i].size() % 2 != 0){
            onlyOddStrings.push_back(input_vector[i]);
        }
    }

    //returns vectpor with only odd strings
    return onlyOddStrings;
}

*/



//*part 5 (10 points) define a class

/*
?Question 1:

Here is Course.hpp of class Course

!dont mind numbers
#include <string>
2 class Course {
3 public:
4 ...//omitted
5 private:
6 std::string name; //represent course name
7 int credit; //represent number of credit hour
8 };



Your job: define Course.cpp with the following requirement.
1. Include necessary library and header file.

2. Define a default constructor, which sets data member name to be “CS 127” and set data member credit
to be 4.

3. Define a non-default constructor, which takes formal parameters name, a string, and credit, an int. Set data
member name by given parameter name. If given parameter credit is positive, use it to set data member
credit, otherwise, set data member credit to be 3.

4. Define method getName to return the value of data member name.

!answer:

//1. include necessary library and header file
#include "Course.hpp"
#include <iostream>
#include <string>

//2. define default constructor 
Course::Course(){
    name = "CS 127";
    credit = 4;
}

//3. define non-default constructor
Course::Course(std::string name, int credit){
    //set name(private member) to parameter name
    this->name = name;

    //set credit(private member) to paramater if paramter credit is positve else set it to 3
    if(credit > 0){
        this->credit = credit;
    }else{
        this->credit = 3;
    }

//4. Define method getName to return the value of data member name.
std::string Course::getName() const {
    return name;
}



*/




//* part 6 (10 points) define a subclass

/*
?Question 1:

Here are part of Person.hpp of Person class.

!dont mind the numbers

class Person {
2 public:
3 Person(string name, int age); //non-default constructor of Person class
4 virtual string toString() const; //return a textual information of name and age.
5 ...//omit other constructors and methods
6 private:
7 string name;
8 int age;
9 };


Declare Student as a subclass of Person. Each student is a person, with additional data member gpa, which
may contain decimal numbers. Suppose Person.hpp is properly declared. In Student.cpp, do the following:

Part 1:
Define non-default constructor of Student, which takes parameters name (a string), age (an int), and
gpa (a double) to initialize the corresponding data members. This constructor can invoke the corresponding
constructor of its super class, then initialize data member unique to the subclass. Data member gpa should be a
double number in [0, 4]. If parameter gpa is not in [0, 4], set data member gpa to be 0.

Part 2:
Override toString method inherited from Person class to return a string representing the student’s
information like name, age, and gpa. You may use string to_string (double val); from std namespace to
convert double number val to a string. Also, you can call toString method in the superclass.


!answer part 1:

//define non-default constructor of subclass Student from bsae class Person
//says we can invoke the default constructor so we use it to give a default person name and age
//only thing left to do is set the gpa private data member
Student::Student(std::string name, int age, double gpa) : Person(name,age) {
    //set gpa member to parameter gpa if its in given interval [0,4] else set it 0
    if(gpa >= 0 && gpa <= 4){
        this->gpa = gpa;
    }else{
        this->gpa = 0;
    }
}


!answer part 2:
std::string Student::toString() const{
    //use base c;ass textual info since we are using the default name and age for it in Student
    std::string default_textual_info = Person::toString();

    //add gpa as a string to the already provided textual info string
    default_textual_info += "Gpa: " + to_string(gpa) + "\n";

    //return the string with added gpa to it 
    return default_textual_info
}

*/


//*part 7 (10 points) recursive function

/*
?question 1:

same as v1

*/


