#ifndef ROAD_H
#define ROAD_H
#include <vector>

class Road{
public:
    //default constructor
    Road();

    //non-default contructor
    Road(int length);

    //insert given ch to given index in Blocks(vector) if valid
    void mark(int index, char ch);

    //print all elements of Blocks(vector)
    void display() const;

    //return number of elements in Blocks(vector)
    int length() const;

private:
    std::vector<char> blocks;
};

#endif