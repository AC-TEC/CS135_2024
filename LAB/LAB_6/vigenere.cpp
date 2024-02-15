/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 6
DATE: 2/15/2024

Task C: create a function that will implement vigenere cipher encryption. 
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



//Vigenere cipher encryption
std::string encryptVigenere(std::string plaintext, std::string keyword){


    std::string vigenere_text = "";
    int keyword_index = 0;

    // loop through each character in the plaintext
    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];

        // check if the character is alphabetic
        if (isalpha(plainChar)) {
            // get the current character in the keyword
            char keyChar = keyword[keyword_index];

            // shift the current character in the plaintext by the corresponding shift value
            vigenere_text += shiftChar(plainChar, keyChar - 'a');

            // update the keyIndex for the next character
            keyword_index = (keyword_index + 1) % keyword.length();
        } else {
            // non-alphabetic characters are not shifted
            vigenere_text += plainChar;
        }
    }

    // return encrypted string
    return vigenere_text;
}



int main(){
    std::string plain_text;
    std::string keyword;


    //get user input
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plain_text);
    std::cout << "Enter keyword  : ";
    std::cin >> keyword;


    //call function and print result
    std::cout << "Ciphertext     : " <<  encryptVigenere(plain_text, keyword) << std::endl;
}