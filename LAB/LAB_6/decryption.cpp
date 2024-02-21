/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 6
DATE: 2/15/2024

Task D: create two functions to decrypt a ceasar and vigenere cipher.
*/


#include <iostream>
#include <string>

//ENCRYPTION FUNCTIONS

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





//DECRYPTION FUNCTIONS

//Caesar decryption
std::string decryptCaesar(std::string ciphertext, int rshift){
    //shift by subtracting original shift by by 26
    return(encryptCaesar(ciphertext, 26 - rshift));
}



//Vigenere decryption
std::string decryptVignere(std::string ciphertext, std::string keyword){

    std::string plaintext = "";
    int keyIndex = 0;

    //loop through each character in the ciphertext
    for (int i = 0; i < ciphertext.length(); i++) {
        char cipherChar = ciphertext[i];
        char keyChar = keyword[keyIndex];

        //check if the character is alphabetic
        if (isalpha(cipherChar)) {
            //get the current character in the keyword
            char shiftedChar = shiftChar(cipherChar, -(keyChar - 'a'));

            //add the shifted character to the plaintext
            plaintext += shiftedChar;

            //update the keyIndex for the next character
            keyIndex = (keyIndex + 1) % keyword.length();
        } else {
            //non-alphabetic characters are not shifted
            plaintext += cipherChar;
        }
    }

    //return decrypted string
    return plaintext;
}





int main(){
    std::string plaintext;
    std::string keyword;
    int shift;

//CAESAR CIPHER

    //get user input
    std::cout << "Enter plaintex: ";
    getline(std::cin, plaintext);
    std::cout << std::endl;
    
    //separation line
    std::cout << "= Caesar =" << std::endl;
    
    std::cout << "Enter shift    : ";
    std::cin >> shift;

    //call and print caesar cipher encryption
    std::string caesar_encryption = encryptCaesar(plaintext, shift);
    std::cout << "Ciphertext     : " << caesar_encryption << std::endl;



    //call and print caesar cipher decryption
    std::string decryption_c = decryptCaesar(caesar_encryption,shift);
    
    //compare produced string with original string. if they match then print it else dont
    if(decryption_c == plaintext){
        std::cout << "Decrypted      : " << decryption_c << std::endl;
    } 


//VIGENERE CIPHER

    //separation line
    std::cout << std::endl;
    std::cout << "= Vigenere =" << std::endl;

    //get user input
    std::cout << "Enter keyword    : ";
    std::cin >> keyword;

    //call and print vigenere cipher encryption
    std::string vigenere_encryption = encryptVigenere(plaintext, keyword);
    std::cout << "Ciphertext       : " << vigenere_encryption << std::endl;

    
    //call and print vigenere cipher decryption
    std::string decryption_v = decryptVignere(vigenere_encryption, keyword);

    //compare produced string with original string. if they match then print it else dont
    if(decryption_v == plaintext) {
        std::cout << "Decrypted        : " << decryption_v << std::endl;
    }

    return 0;
}