#include <iostream>
#include <cctype> //for isalpha()
#include <string>

//CODE REVIEW 5: IMPLEMENT THE ENCRYPTVIGENERE(string plaintext, string keywords) function.
//               Assume that shiftChar(char c, int rshift) is already implemented
//               Also Assume that keyword contains only big letters (A-Z)




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


std::string encryptVigenere(std::string plaintext, std::string keyword){
    //string to hold the encrypted string
    std::string encrypted_string = "";

    //index for keyword (since we want to go through each letter in keyword to shift)
    int keyword_index = 0;

    //loop through the plaintext(given string)
    for(int i = 0; i < plaintext.length(); i++){
        //index for the plaintext(so we can go through each letter and shift it with the keyword letter(keyword_index))
        //char plaintext_letter = plaintext[i];

        //check if the character is a letter else just dont shift and just add to new encrypted string
        if(isalpha(plaintext[i])){
            //add and shift it characters then move to next keyword character
            //-'a' to convert the numerical value
            encrypted_string += shiftChar(plaintext[i], keyword[keyword_index % keyword.length()] - 'A'); //if small character for keyword use 'a' instead

            //move to next character in keyword so add to its index
            keyword_index++;
        }else{
            //not alphabet character
            //just add to new string
            encrypted_string += plaintext[i];
        }
    }

    //return encrypted string
    return encrypted_string;
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

    //expected if keywords all small (a-z): Jevpq, Wyvnd!
}
