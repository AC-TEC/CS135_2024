/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.20
DATE: 5/1/2024

HW: Write a function vector<int> merge_sorted(vector<int> a, vector<int> b) that merges two sorted vectors, producing a new sorted vector
*/

#include <iostream>
#include <vector>


std::vector<int> merge_sorted(std::vector<int> a, std::vector<int> b){
    //vector to hold the merged and sorted elements from both vectors
    std::vector<int> merge_and_sorted;

    //indexes for vectors
    int i = 0;  //vector a
    int j = 0;  //vector b

    //loop through vectors
    for(int k = 0; k < a.size() + b.size(); k++){
        //check if vector a has been completely processed
        if(i >= a.size()){
            merge_and_sorted.push_back(b[j]);
            j++;
        }else if (j >= b.size()){
            //check if vector b has been completely processed
            merge_and_sorted.push_back(a[i]);
            i++;
        }else if(a[i] <= b[j]){
            //append element from vector a
            merge_and_sorted.push_back(a[i]);
            i++;
        }else{
            merge_and_sorted.push_back(b[j]);
            j++;
        }
    }

    //return merged and sorted vector
    return merge_and_sorted;
}



int main(){

    //declare example vectors
    std::vector<int> vector_1 = {1,4,9,16};
    std::vector<int> vector_2 = {4,7,9,9,11};

    //call function 
    std::vector<int> vector_merge = merge_sorted(vector_1,vector_2);

    //print out result
    for(auto nums : vector_merge){
        std::cout << nums << " ";
    }

    return 0;
}