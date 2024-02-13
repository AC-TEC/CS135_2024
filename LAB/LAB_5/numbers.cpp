/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 5
DATE: 2/13/2024

Task F: make a function that returns the smallest twin prime greater than n
*/
#include <iostream>

//TASK A
bool isDivisibleBy(int n, int d){
    //check for division by 0
    if(d == 0){
        return false;
    }

    //check if n is divisible by d. if it is return true else return false.
    if(n % d == 0){ 
        return true;
    }


    return false;
}



//TASK B
bool isPrime(int n){

    //check if number is less than 2
    if(n < 2){
        return false;
    }

    //check if number is able to be divided evenly by other than 2 and itself. if it is able to be divided then not a prime number
    for(int i = 2; i < n; i++){
        if(isDivisibleBy(n,i) == true){
            return false;
        }
    }

    //number can only be divided by 1 and itself. NO other numbers
    return true; //prime number
}




//TASK C
int nextPrime(int n){
    //starting point (bc next prime number has to be greater than the one being passed into parameter)
    int next_number = n+1;

    //if next_number is false then keep on going until we get a prime number
    while(isPrime(next_number) == false){
        next_number++;
    }

    //returns the next prime number
    return next_number;
}




//TASK D
int countPrimes(int a, int b){
    //counter to keep track of prime numbers
    int prime_numbers = 0;

    //iterate from point a to b
    for(int i = a; i <= b; i++){
        //check if number is prime. if it is increase counter
        if(isPrime(i)){
            prime_numbers++;
        }
    }

    //return amount of primes found in range a-b
    return prime_numbers;

}



//TASK E
bool isTwinPrime(int n){
    //if n is a prime number and either n-2 or n+2 is a prime number then return true else return false
    if(isPrime(n) == true && (isPrime(n-2) == true || isPrime(n+2) == true)){
        return true;
    } else{
        return false;
    }
}



//TASK F
int nextTwinPrime(int n){
    //start at a number greater than n
    int starting_point = n+1;

    //if number is not a twin prime then increase starting_point to next number
    while(isTwinPrime(starting_point) == false){
        starting_point++;
    }

    //returns the smallest twin prime greater than n
    return starting_point;
}


int main(){
    int number;

    //get user input
    std::cout << "Enter number: ";
    std::cin >> number;

    //call function
    int twin_prime = nextTwinPrime(number);

    //print result
    std::cout << "NEXT SMALLEST TWIN PRIME: " << twin_prime << std::endl;
}





/*

TASK A MAIN FUNCTION BELOW:

int main(){
    int n;
    int d;

    //get user input
    std::cout << "Enter first number: ";
    std::cin >> n;
    std::cout << "Enter second number: ";
    std::cin >> d;

    //call function
    bool divisible = isDivisibleBy(n,d);

    //print out response (0 = false, 1 = true)
    if(divisible == 0){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }

    return 0;
}

*/




/*
TASK B MAIN FUNCTION BELOW:

    int number;

    //get user input
    std::cout << "Enter number: ";
    std::cin >> number;

    //call function
    bool is_prime = isPrime(number);

    //print if number is prime
    if(is_prime == 1){    //(1) == true
        std::cout << "true" << std::endl;
    }else{                //(0) == false
        std::cout << "false" << std::endl;
    }

    return 0;

*/



/*
TASK C MAIN FUNCTION BELOW:

int main(){

    int number;

    //get user input
    std::cout << "Enter number: ";
    std::cin >> number;

    //call function
    int new_number = nextPrime(number);

    //print out number after calling function
    std::cout << new_number << std::endl;

    return 0;
}
*/


/*
TASK D MAIN FUNCTION BELOW:

int main(){
    int starting_number;
    int end_number;

    //get user input
    std::cout << "Enter starting number: ";
    std::cin >> starting_number;
    std::cout << "Enter end number: ";
    std::cin >> end_number;

    //call function
    int number_of_primes = countPrimes(starting_number,end_number);

    //print out result
    std::cout << "Number of primes numbers in interval: " << number_of_primes << std::endl;

    return 0;
}
*/


/*

TASK E MAIN FUNCTION BELOW:


int main(){
    int number;

    //get user input
    std::cout << "Enter number: ";
    std::cin >> number;

    //call function
    bool twin_prime = isTwinPrime(number);

    //print result
    if(twin_prime == 1){
        std::cout << "True" << std::endl;
    }else{
        std::cout << "False" << std::endl;
    }

    return 0;
}



*/
