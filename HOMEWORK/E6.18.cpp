/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.18
DATE: 5/1/2024

HW: Write a function vector<int> append(vector<int> a, vector<int> b) that appends one vector after another
*/

#include <iostream>
#include <vector>


std::vector<int> append(std::vector<int> a, std::vector<int> b){
    //vector to store all elements from both vectors
    std::vector<int> combo;

    //loop through vector a and add to combo vector
    for(auto nums_a : a){
        combo.push_back(nums_a);
    }

    //loop through vector b and add to combo vector
    for(auto nums_b : b){
        combo.push_back(nums_b);
    }

    //return the combined vector of all elements
    return combo;
}


//test
int main(){

    //declare example vectors
    std::vector<int> first = {1,4,9,16};
    std::vector<int> second = {9,7,4,9,11};

    //call function
    std::vector<int> result = append(first,second);

    //print result
    for(auto r : result){
        std::cout << r << " ";
    }

    return 0;
}