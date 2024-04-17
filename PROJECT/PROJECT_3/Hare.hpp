#ifndef Hare_H
#define Hare_H
#include <vector> 


class Hare {
public:
    //?Default constructor
    Hare(); 
       //a typical hare that sleeps 20% of the time,
       //move 9 squares to the right 20% of the time,
       //move 12 squares to the left 10% of the time,
       //move 1 square to the right 30% of the time,
       //move 2 squares to the left 20% of the time.
    
    
    //?Parameterized constructor
    Hare(std::vector<int> patterns, int position);
    
    
    //?Parameterized constructor
    Hare(int* arr, int size, int position);
    
    
    void move();
    
    
    int getPosition() const; 
    
    
    void setPosition(int position);


    //!Function to get value from patterns vector (for testing purposes)
    std::vector<int> getPatterns() const;

private:
    std::vector<int> patterns;
    
    int position;
};
#endif
