//*part 1

/*
?Question 1:
Given string greetings[] = {"Hello", "Hi", "How are you"}, what is greetings[0][4]?

!answer: 
'o'
*/



/*
?Question 2:
Given Employee class, declare that class Nurse as subclass of Employee class with public inheritance.

!answer:
class Nurse : public Employee
*/



/*
?Question 3:
Write code to generate a random int between 3 and 10, where both ends are included. No library is needed


!answer:
int random_num = rand() % 8 + 3

bc rand() % 8 = [0,7]
then +3 shifts the interval to [3,10]
*/



/*
?Question 4: 
Given string greeting = "Hello"; What is the value for greeting.substr(2,3)?


!answer:
"llo"

bc starts at index 2 and includes it then it collets 2 more characters to make it 3.
since syntax is string_variable.substr(starting_position,length)

*/



/*
?Question 5:
Write a command to compile and link TestBoard.cpp and Board.cpp to generate a runnable file prog.

!answer:
g++ -std=c++11 TestBoard.cpp Board.cpp -o prog

*/



/*
?Question 6:
What is the value of 1 / 2 * 5.6 in C++?

!answer:
2 * 5.6 = 11.2

1 / 11.2 = 0 (final answer)

test explaination: says from left to right so division first then multiply

my little sample
#include <iostream>
int main(){
    double mult = 2 * 5.6;

    double div = 1 / mult;
    std::cout << div << std::endl;

    double check = 1 / 2 * 5.6;
    std::cout << check << std::endl;
}

*/



/*
?Question 7:
Write header of a function called average to return the average of an array of double numbers with size n.

!answer:
double average(double arr[], int n);

or using a pointer

double average(double *arr, int n);
*/



/*
?Question 8:
Given int arr[] = {4, 3, 2, 1}; What is the value of *(arr + 1)?

!answer:

we know that *(index) means we are accessing the array/vector at the address(index) given

*(arr + 1) -> arr[1] -> array at index 1

value: 3
*/



/*
?Question 9:
*2-Dimensional strings array (prof said no 2-d arrays). But just incase here it is

Declare and initialize a two-dimensional strings array called synonyms with two rows, each row with three
columns. The first row is “kind”, “gentle”, “nice”, the second row is “big”, “large”, “huge”.

!answer:
*prefer the first one
string synonyms[2][3] = { {"kind", "gentle", "nice"}, {"big", "large", "huge"} };

or

string synonyms[][3] = { {"kind", "gentle", "nice"}, {"big", "large", "huge"} };
*/



/*
?Question 10:
What is output for the following code?

std::vector<int> nums;
for(int i = 12; i >= 0; i--){
    nums.push_back(i);
}

for(int i = 0; i < nums.size(); i++){
    if(i % 5 == 0)
        std::cout << nums[i] << " ";
}

std::cout << std::endl;


!answer:
12 7 2

bc first loop = add nums to vector-> {12,11,10,9,8,7,6,5,4,3,2,1,0}
second loop = only if the index is divisible by 5 -> index 0,5,10

index->value
0->12
5->7
10->2
*/



/*
?Question 11:
What is the output of the following code?
#include <iostream>
using namespace std;

int main(){
    int result = 0;
    for(int num = 3; num < 11; num+=4){
        result += num;
    }

    cout << result << endl;
    return 0;
}

!answer:
10


yes -> 0+3 = result:3 num = 7 now
yes(bc 7<11) -> 3+7 = result:10 num = 7+4 = 11 now
no bc 11 ! < 11

*/



/*
?Question 12:
What is output for the following code?

int a = 2;
int *p = &a;
*p += 3;
cout << a << endl;

!answer:
5

*/


/*
?Question 13:
What is the output for the following code?

void foo(int &a);

int main(){
    int num = 1;
    foo(num);
    cout<< num << endl;
    return 0;
}

void foo(int& a){
    if(a % 2 != 0){
        a++;
    }

    else a +=2;
}

!answer:
2

bc 1 % 2 == 1 not 0 so we increase a by 1 (a++) so a = 2 now
*/



/*
?Question 14:
What the output when input is 81?

cout << "Enter a number: ";
double num;
cin >> num;
switch ((int)num / 10) {
    case 10:
    case 9: cout << "excellent" << endl;
        break;
    case 8: cout << "good" << endl;
        break;
    case 7: cout << "ok" << endl;
        break;
    case 6: cout << "work hard" << endl;
        break;
    default: cout << "do not give up" << endl;
}

!answer:
"good"

bc 81/10 = 8 -> case 8 -> "good"
*/







//*PART 2 (10 points) Answer the following questions.


/*
?Question 1:
Define a function, for an given array of integers with its size, return number of elements that is not zero.
For example, call the function with array with values 1, 0, 2, 0, 1, the size of array is 5, then the return is 3.

!answer:

im using arr[] and int size for parameters since i will have to iterate through an array

int numZeros(int arr[], int n){
    counter for elements that are not zero in array
    int not_zero = 0;

    iterate through array,check if not zero,add to counter 
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            not_zero++;
        }
    }

    return not_zero;
}
*/


/*
?Question 2:
Define function void sortByLen(string* a, string* b), if the length of *a is larger than the length of *b, 
swap *a with *b, otherwise, do nothing. Note that dereference operator * has lower precedence than dot operator.


!answer:

void sortByLen(std::string *a, std::string *b){
    if((*a).length() > (*b).length()){
        std::swap(*a,*b);
    }
}

did (*a) bc we need to derefernce it by using * so we can access the actual value and not the address
since when we pass the variables to the parameters it will be the address of it
*/







//*PART 3 (20 points) Programming exercises

/*
?Question 1:
Define a function, for a given string, if it contains at least a letter and a digit, return true, otherwise, return
false.

For example, for string “abc”, the return is false. For string “12”, the return is false. For “a2”, the return is
true. For “2ab”, the return is true.

Hint: you might use isalpha to check whether a charcter is a letter (alphabetic) or not. Use isdigit to check
whether a character is in [’0’, ’9’].

int isalpha ( int c ); Check if character is alphabetic
int isdigit ( int c ); Check if character is decimal digit

You can count the number of occurrences of letters and number of occurrences of digits.


!answer:

bool isStringandDigit(std::string input_string){
    //counters for letter and digits
    int character = 0;
    int digit = 0;

    //iterate through string
    for(int i = 0; i < input_string.length();i++){
        //check if we have a string and a digit
        if(isalpha(input_string[i])){
            character++;
        }

        if(isdigit(input_string[i])){
            digit++;
        }
    }


    //check if string has both a character and digit
    if(character > 0 && digit > 0){
        return true;
    }

    //return false if string does not have both
    return false;
}
*/


/*
?Question 2:

Define panel to be int** type.


!Answer: int** panel;

?part b
*2-d array not on test
Allocate memory of panel to be a two-dimensional array with 3 rows, each row has 2 columns.

!answer:
int numRows = 3;
int numCols = 2;

panel = new int*[numRows];

for (int row = 0; row < numRows; row++)
    panel[row] = new int[numCols];
}


?part c:
Initialize the element of panel indexed at (row)th row and (col)th column to be row * col, where row and
col are indices and 0 <= row < 3 and 0 <= col < 2.

!answer:
for (int row = 0; row < numRows; row++)         //numRows can be written as 3
     for (int col = 0; col < numCols; col++)    //numCols can be written as 2
            panel[row][col] = row * col;


?part d:
Release the dynamically allocated memory and avoid dangling pointer problem.

!answer:
for (int row = 0; row < numRows; row++) { //numRows can be written as 3
    delete[] panel[row];
    panel[row] = nullptr;
}

delete[] panel;
panel = nullptr;
*/





//*part 4 (10 points) write codes of vector

/*
?Question 1:

Define a function, for a given vector of strings, return a vector of all strings with even length.
For example, call the above function on a vector of strings with values “ab”, “ccd”, “abcd”, the return is a
vector of strings with values “ab” and “abcd”.


!answer:

//return type is vector and its of strings so thats the data type we use for making the function

std::vector<std::string> evenVectors(std::vector<std::string> input_vector){
    //vector to hold even strings
    std::vector<std::string> onlyEvenStrings;

    //itertate through given vector
    for(int i = 0; i < input_vector.size();i++){
        //check if the length of each sting in vector is even
        if(input_vector[i].size() % 2 == 0){
            //add to even strings vector
            onlyEvenStrings.push_back(input_vector[i]);
        }
    }

    //return vector with even strings
    return onlyEvenStrings
}
*/






//*part 5 (10 points) Define a class

/*
?Question 1:

Here is Course.hpp of class Course.

#include <string>

class Course{
public:
    omitted (for you to do)

private:
    std::string name; //represent course name
    int credit; //represents number of credit hour

};


Your job: define Course.cpp with the following requirement.
1. Include necessary library and header file.

2. Define a default constructor, which sets data member name to be “CS 135” and set data member credit
to be 4.

3. Define a non-default constructor, which takes formal parameters name, a string, and credit, an int. Set data
member name by given parameter name. If given parameter credit is positive, use it to set data member
credit, otherwise, set data member credit to be 3.

4. Define method getCredit to return the value of data member credit.



!answer:
//1.add neccessay library and header file
#include "Course.hpp"
#inlclude <iostream>
#include <string>

//2.default contructor
Course::Course(){
    name = "CS 135";
    credit = 4;
}

//3.non-default constructor
Course::Course(std::string name, int credit){
    //set name(private data member) to parameter name
    this->name = name;

    //set credit(private data member) to parameter credit if its positive else set to 3;
    if(credit > 0){
        this->credit = credit;
    }else{
        credit = 3;
    }
}

//4.define getCredit function which returns value of data member credit
int Course::getCredit() const{
    return credit;
}

*/





//*part 6 (10 points) Define subclass

/*
?Question 1:

*Remeber: when we have VIRTUAL before a function in base class it means we can create a different impementation of that function in our subclass.
* dont forget you will need to put override after the function name/parameters in the subclass to then create your own implementation

Here are part of Person.hpp of Person class.

class Person{
public:
    Person(std::string name, int age) //non default contructor of Person class

    virtual std::string toString() const; //returns a textual information of name and age

    omit other constructors and methods 

private:
    std::string name;
    int age;
};


*part 1
Declare Employee as a subclass of Person. Each employee is a person, with additional data member salary,
which may contain decimal numbers. Suppose Employee.hpp is declared. In Employee.cpp, do the following:

Define non-default constructor of Employee, which takes parameters name (a string), age (an int), and
salary (a double) to initialize the corresponding data members. This constructor can invoke the corresponding
constructor of its super class, then initialize data member unique to the subclass. Data member salary should be
positive. If parameter salary is not positive, set data member salary to be 1000.


!answer:

//non default constructor of Employee class (subclass to Person class)
//additional private data member is double salary (in subclass not in base class)
//parameters: name(string) and age (int) and salary(double)

//whwen says can invoke corresponding constructor of its super class means to use the default constructor when creating the non-default of Employee
//the thing above makes it so that we have already a name and age set which would be a default person age and name so we only have to set the salary data member
Employee::Employee(std::string name, int age, double salary) : Person(name,age) {
    //the name and age are set due to invoking the default constructor of base class person
    //so the name and age of non-default of employee class will be that of a default name and age set in Person class (base class)

    //now set the salary private data member

    //if not positive num set data member to 1000 else set it to parameter
    if(salary <= 0){
        this->salary = 1000;
    }else{
        this->salary = salary;
    }
}


*part 2

Override toString method inherited from Person class to return a string representing the employee’s
information like name, age, and salary. You may use string to_string (double val); from std namespace to
convert double number val to a string. Also, you can call toString method in the superclass.

//const bc we dont want to change the name and age only add salary and print: name,age,salary as a string
std::string Employee::toString() const{
    //using deafult name and age bc earlier it is said that we use that for employee subclass
    std::string default_name_age = Person::toString();  //makes it so we have a string with the name and age as a string stored in this variable

    //add salary as a string to the string that already has name and age as a string
    str += "Salary: " + to_string(salary) + "\n"; //to_string to convert number to string

    //returns the string with name,age,salary()new

    return str;
}

*/





//*part 7 (10 points) define recursive function

/*
?Question 1:

Define a recursive function to check whether an array of strings is palindrome or not. An array of strings is
palindrome if the elements read from left to right and from right to left are the same.

For example, array of strings with values “hi”, “how are you”, “hi” is palindrome, but array of strings wth
values “hi”, “how are you” is not palindrome.

Hint: an array is a palindrome if and only the leftmost element equals the rightmost element and the subarray
from the second element to the second-to-last element is palindrome. Think what are the initial address and size
of that subarray?

Warning: If you do not use recursion, you will not get any point. No repetition statement is
allowed in this function.

!answer:

bool isPalindrome(string* arr, int size) {
    if (size <= 1){
        return true;
    }

    return arr[0] == arr[size-1] && isPalindrome(arr+1, size-2);
}

*/