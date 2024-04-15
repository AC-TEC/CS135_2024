/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW

This program 
*/

#include <iostream>
using namespace std;

class Circuit {
public:
  int get_first_switch_state();
  int get_second_switch_state();
  int get_lamp_state();
  void toggle_first_switch();
  void toggle_second_switch();

private:
  int first_switch = 0;
  int second_switch = 0;
  int lamp_state = 0; // Initial state of the lamp (can be off by default)
};

int Circuit::get_first_switch_state() {
  return first_switch;
}

int Circuit::get_second_switch_state() {
  return second_switch;
}

int Circuit::get_lamp_state() {
  return lamp_state;
}

void Circuit::toggle_first_switch() {
  first_switch = !first_switch; // Toggle the state of the first switch
  lamp_state = !(first_switch == second_switch); // Update lamp state (on only if switches differ)
}

void Circuit::toggle_second_switch() {
  second_switch = !second_switch; // Toggle the state of the second switch
  lamp_state = !(first_switch == second_switch); // Update lamp state (on only if switches differ)
}
