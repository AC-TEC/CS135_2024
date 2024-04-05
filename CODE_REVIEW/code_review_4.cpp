/*

CODE REVIEW 4

write code to implement the following requirements to draw a triangle.

1.Enter size from console, ENSURE this number to be a positive odd integer

2.The number of asterisks in any line is an odd number

3.In each line, the asterisks are centered

4.The number of asterisks in the top line is 1, then increase number of asterisks by 2
    when moving down to the next line

5.The last line has size many asterisks

Sample input/Output of

Enter size: 6
size needs to be a positive odd integer. Re-enter: -2
size needs to be a positive odd integer. Re-enter: -3
size needs to be a positive odd integer. Re-enter: 5

  *  
 *** 
*****

*/


#include <iostream>


int main(){
    int size;

    //get user input
    std::cout << "Enter size: ";
    std::cin >> size;

    //ask user to re-enter if size is not a postive odd number
    //check if input num is a negative number or its an even number. if so then ask to re-enter
    while(size < 0 || size % 2 == 0){
        std::cout << "Size needs to be a positive odd integer. Re-enter: ";
        std::cin >> size;
    }

    
    //To print O.G side: for(int row = 1; row <= size; row+=2)
    //This first for loop is the only part we would have to modify to print the triangle upside down or right side up
    //To print upside down: for(int row = size; size >= 1; row -=2)
    
    //rows(creates the 3 rows (1+2 = 3 + 2 = size 5))
    for(int row = 1; row <= size; row+=2){
        //columns
        int stars = 0;
        
        for(int col = 0; col < size; col++){
            //condition to print asterisks and spaces
            //print stars
            if(col >= ((size-row)/2) && stars < row){
                std::cout << "*";
                stars++;
            }else{
                //print spaces
                std::cout << " ";
            }
        }
        //moves to next line
        std::cout << std::endl;
    }

    return 0;
}



//print composite numbers (numbers opposite of prime)
//from interval [1,10]


#include <iostream>

bool isPrime(int n){
    if(n < 2){
        return false;
    }


    //check if divisible by any number other than 2 and itself
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            //if is divisible
            return false;
        }
    }

    //means number is prime
    return true;
}


int main(){
    //loop through given interval and print composite numbers found
    for(int i = 1; i <= 10; i++){
        //if not prime that means its composite and greater than 1(bc 1 is neither prime or composite)
        if(!isPrime(i) && i > 1){
            //print number
            std::cout << i << " ";
        }
    }
    return 0;
}

