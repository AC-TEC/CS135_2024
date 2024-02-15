/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 6
DATE: 2/14/2024

Task B: create a function that will implement caesar cipher encryption. 
        Also create a helper function to assist you
*/

#include <iostream>
#include <string>


//helper function to shift one character by rshift
char shiftChar(char c, int rshift){
    //check if character is alphabetic
    if (isalpha(c)) {
        //determine whether to start with uppercase or lowercase alphabet range ascii numbers
        char base = isupper(c) ? 'A' : 'a';
        //calculate the shifted character
        return ((c - base + rshift + 26) % 26) + base;
    } else {
        // Leave non-alphabetic characters unchanged
        return c;
    }
}



//Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift){
    //create empty string to store encrypted message
    std::string cipher_text = "";

    //loop through each character in string
    for(int i = 0; i < plaintext.length(); i++){
        //shift each character and add them to new string
        cipher_text += shiftChar(plaintext[i], rshift);
    }

    //return encrypted string
    return cipher_text;
}


int main(){

    std::string plain_text;
    int shift;

    //get user input
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plain_text);
    std::cout << "Enter shift    : ";
    std::cin >> shift;


    //call function and print
    std::cout << "Ciphertext     : " << encryptCaesar(plain_text,shift) << std::endl;
    return 0;
}








/*
calculate shift of character

    1. c- base: calc position of original character

    2. + rshift: add the right shift

    3. + 26: this ensures that result is not negative.
        just incase additon and subtraction of o.g character,base and shift is negative this will ensure that its not

    4. % 26: to ensure result is in range of alphabet.(this wraps it around).
        handles case where shift goes beyond the end of alphabet

    5. + base: after previous operations this will get the new position.
        ensuring we get the correct character in the correct base range(uppercase or lowercase)

*/









/*
        //check if character is alphabetic
        if(isalpha(plaintext[i])){
            //if yes, add it to cipher text after being shifted
            cipher_text += shiftChar(plaintext[i], rshift);
        } else{
            cipher_text += plaintext[i];
        }
    }
*/