/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 10
DATE: 4/11/2024

Task A: Implement two functions. One that calculates the amount of minutes from midnight. The other calculates the interval between two time inputs.

Task B: Implement the addMinutes() function which takes in a time object and a integer min which adds the minutes to the time object inserted and then generates a new time object with the additional minutes added to it


*/

#include <iostream>

class Time { 
public:
    int h;
    int m;
};

//calculates the total minutes 
int minutesSinceMidnight(Time time){
    //convert hour to mins
    int hours_to_min = time.h * 60;

    //add the remaining minutes to the hour
    int total_mins = hours_to_min + time.m;

    //return the total minutes
    return total_mins;
}


//calculates minutes between two times
int minutesUntil(Time earlier, Time later){
    int early_mins = minutesSinceMidnight(earlier);
    int later_mins = minutesSinceMidnight(later);

    return (later_mins - early_mins);
}



Time addMinutes(Time time0, int min){
    //convert time0 object hours to mins
    int time_to_mins = minutesSinceMidnight(time0);

    //add additional given minutes
    int additional_mintes = time_to_mins + min;

    //get the hours after we added extra minutes
    int new_hours = additional_mintes / 60;

    //get the minutes after we added extra minutes
    int new_minutes = additional_mintes % 60;


    //create a new time object after additional minutes added. If hours are valid(hours < 24) 
    if(new_hours < 24){
        Time new_time;
        new_time.h = new_hours;
        new_time.m = new_minutes;

        //return the new time
        return new_time;
    }else{
        //time is invalid
        Time invalid_time;
        invalid_time.h = -1;
        invalid_time.m = -1;

        //return invalid time
        return invalid_time;
    }
}


int main(){
    //create a time object
    Time original_time;

    //get user input
    std::cout << "Enter hour: ";
    std::cin >> original_time.h;
    std::cout << "Enter minutes: ";
    std::cin >> original_time.m;


    std::cout << std::endl;

    //ask user for extra minutes
    int extra_mins;
    std::cout << "Add extra minutes: ";
    std::cin >> extra_mins;

    //create new time object and call the addMinutes function to generate the new time after additional minutes have been added
    Time new_time = addMinutes(original_time,extra_mins);

    //print out new time
    std::cout << "New time is: " << new_time.h << ":" << new_time.m << std::endl;

    return 0;
}


/*
!TASK A MAIN FUNCTION

int main(){
    //create object for first time
    Time time_1;

    //get user input 
    std::cout << "Enter first time: " << std::endl;
    std::cout << "Enter hour: ";
    std::cin >> time_1.h;
    std::cout << "Enter minutes: ";
    std::cin >> time_1.m;


    std::cout << std::endl;


    //create object for second time
    Time time_2;

    //get user input
    std::cout << "Enter second time: " << std::endl;
    std::cout << "Enter hour: ";
    std::cin >> time_2.h;
    std::cout << "Enter minutes: ";
    std::cin >> time_2.m;


    std::cout << std::endl;


    //call minutesSinceMidnight() function
    std::cout << "The first time is " << minutesSinceMidnight(time_1) << " minutes after midnight." << std::endl;
    std::cout << "The second time is " << minutesSinceMidnight(time_2) << " minutes after midnight." << std::endl;

    std::cout << std::endl;

    //call minutesUntil() function
    std::cout << "The minutes between them are " << minutesUntil(time_1,time_2) << " minutes." << std::endl;

    return 0;
}

*/