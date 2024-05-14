/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 13
DATE: 5/13/2024

Task A: Write a program that prints all numbers in range left to right, separated by spaces. (Don’t use loops, global or static variables.)

TASK B: Write a program to add the numbers from a given range. From left to right

TASK C: Write a program to return the sum of all elements in a array.

TASK D: Write a program which returns true if all characters in the string are letters and digits, otherwise returns false.

TASK E: Write a program which returns true if the string is a sequence of nested parentheses: strings "", "()", "(())", "((()))"  are all correct sequences and should return true. 
        Any other symbols or mismatching parenthesis should make the function return false.

TASK F: uses the function divisible which takes an array of prices and the size of the array as arguments, and returns true if the collection can be divided into two equal halves, and false otherwise.

        divisibleHelper function is a recursive helper function that takes additional arguments leftSum, rightSum, and index, 
        which keep track of the current sums of Alice's and Bob's shares, and the current index of the array.
        The function returns true if a solution exists, and false otherwise.

*/
#include <iostream>
#include <string> //TASK D 

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



//?TASK D
bool isAlphanumeric(std::string s){
    if (s.size() == 0) { // base case
        return true;
    } else if (!isalnum(s[0])) { // if first character is not alphanumeric(character or #)
        return false;
    } else { // recursive case
        return isAlphanumeric(s.substr(1)); //calls it self shorter(index - 1) each time until reaches last character whcih at that point return true bc size is 0
    }
}


//?TASK E (BONUS)
bool nestedParens(std::string s) {
    if (s.empty()) { // base case: empty string is valid
        return true;
    } else if (s[0] != '(' || s[s.length()-1] != ')') { // base case: string does not start and end with parentheses
        return false;
    } else { // recursive case: check if inner substring is nested
        return nestedParens(s.substr(1, s.length()-2));
    }
}


//?TASK F (BONUS)
bool divisibleHelper(int *prices, int size, int leftSum, int rightSum, int index) {
    // Base case: If we have reached the end of the array, check if the sums are equal
    if (index == size) {
        return leftSum == rightSum;
    }

    // Recursive case: Try adding the current price to Alice's share and see if it is divisible
    if (divisibleHelper(prices, size, leftSum + prices[index], rightSum, index + 1)) {
        std::cout << "Alice gets item " << index << std::endl;
        return true;
    }

    // Recursive case: Try adding the current price to Bob's share and see if it is divisible
    if (divisibleHelper(prices, size, leftSum, rightSum + prices[index], index + 1)) {
        std::cout << "Bob gets item " << index << std::endl;
        return true;
    }

    // If neither of the above cases is successful, then there is no solution
    return false;
}

int computeTotalSum(int *prices, int size, int index) {
    // Base case: If we have reached the end of the array, return 0
    if (index == size) {
        return 0;
    }

    // Recursive case: Compute the sum by adding the current element to the sum of the remaining elements
    return prices[index] + computeTotalSum(prices, size, index + 1);
}

bool divisible(int *prices, int size) {
    // Compute the total sum of the prices recursively
    int total = computeTotalSum(prices, size, 0);

    // If the total sum is not even, then there is no solution
    if (total % 2 != 0) {
        return false;
    }

    // Call the recursive helper function
    return divisibleHelper(prices, size, 0, 0, 0);
}


//!TASK F MAIN FUNCTION
int main() {
    int prices[] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    int size = sizeof(prices) / sizeof(prices[0]);

    if (divisible(prices, size)) {
        std::cout << "The collection can be divided into two equal halves." << std::endl;
    } else {
        std::cout << "The collection cannot be divided into two equal halves." << std::endl;
    }

    return 0;
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



/*
!TASK C MAIN FUNCTION

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

*/


/*
!TASK D MAIN FUNCTION

int main(){
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

//calls function
    std::cout << isAlphanumeric(s) << std::endl;
}

*/


/*
!TASK E MAIN FUNCTION

int main(){
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

//calls function
    std::cout << nestedParens(s) << std::endl;
}
*/