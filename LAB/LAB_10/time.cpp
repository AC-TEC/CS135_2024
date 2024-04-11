/*
Author: Andy Cocha
Course: CSCI-135
Instructor: Tong Yi
Assignment: LAB 10
DATE: 4/11/2024

Task A: Implement two functions. One that calculates the amount of minutes from midnight. The other calculates the interval between two time inputs.

Task B: Implement the addMinutes() function which takes in a time object and a integer min which adds the minutes to the time object inserted and then generates a new time object with the additional minutes added to it

TASK C: Implement PrintTimeslots() function

TASK D: Implement scheduleAfter() function to produce and return a new TimeSlot for the movie

TASK E: Implement the timeOverlap() function that checks if two time slots overlap

*/
#include <iostream>
#include <string>

//?TASK C
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

//?TASK A
class Time { 
public:
    int h;
    int m;
};

//TASK C
class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};


//?TASK C
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


//?TASK A
//calculates the total minutes 
int minutesSinceMidnight(Time time){
    //convert hour to mins
    int hours_to_min = time.h * 60;

    //add the remaining minutes to the hour
    int total_mins = hours_to_min + time.m;

    //return the total minutes
    return total_mins;
}


//?TASK A
//calculates minutes between two times
int minutesUntil(Time earlier, Time later){
    int early_mins = minutesSinceMidnight(earlier);
    int later_mins = minutesSinceMidnight(later);

    return (later_mins - early_mins);
}


//?TASK B
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


//?TASK C
void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}


//?TASK C
//prints movie details
void printTimeSlot(TimeSlot ts){
    //get title,genre and movie duration
    printMovie(ts.movie);

    //print out starting time and end time of movie
    std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ";
    
    //get end time
    Time end_time = addMinutes(ts.startTime, ts.movie.duration);
    
    //prints out final part
    std::cout << "ends by " << end_time.h << ":" << end_time.m << "]" << std::endl;
}


//?TASK D
// function to produce and return a new TimeSlot for the movie nextMovie, scheduled immediately after the time slot
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    
    // Calculate the end time of the current TimeSlot using the addMinutes function.
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    
    // Create a new TimeSlot for the next movie starting at the endTime of the current TimeSlot.
    TimeSlot nextSlot = {nextMovie, endTime};
    return nextSlot;
}


//?TASK E
// function to check if two time slots overlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    // convert the start time of ts1 to minutes since midnight
    int start1 = minutesSinceMidnight(ts1.startTime);
    
    // calculate the end time of ts1 by adding its duration to its start time
    int end1 = start1 + ts1.movie.duration;
    
    // convert the start time of ts2 to minutes since midnight
    int start2 = minutesSinceMidnight(ts2.startTime);
    
    // calculate the end time of ts2 by adding its duration to its start time
    int end2 = start2 + ts2.movie.duration;
    
    // check if the two time slots overlap, return true if they do and false otherwise
    return !(end1 <= start2 || end2 <= start1);
}


int main(){

    //creating several movies and time slots
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"The Godfather", DRAMA, 175};
    Movie movie4 = {"Inception", THRILLER, 148};
    Movie movie5 = {"La La Land", ROMANCE, 128};

    //Timeslots
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie3, {16, 45}}; 
    TimeSlot time_s1 = {movie4, {17,25}};
    TimeSlot time_s2 = {movie5, {18,25}};

    //print out details of each time slot
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(time_s1);
    printTimeSlot(time_s2);

    std::cout << std::endl;
    std::cout << std::endl;

    //testing the scheduleAfter function
    TimeSlot nextSlot = scheduleAfter(time_s2, movie5);
    printTimeSlot(nextSlot);

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


/*
!TASK B MAIN FUNCTION

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

*/


/*
!TASK C MAIN FUNCTIONS

int main(){

    //creating several movies and time slots
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"The Godfather", DRAMA, 175};
    Movie movie4 = {"Inception", THRILLER, 148};
    Movie movie5 = {"La La Land", ROMANCE, 128};

    //Timeslots
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie3, {16, 45}}; 
    TimeSlot time_s1 = {movie4, {17,25}};
    TimeSlot time_s2 = {movie5, {18,25}};

    //print out details of each time slot
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(time_s1);
    printTimeSlot(time_s2);

    return 0;
}

*/


/*
!TASK D MAIN FUNCTION

int main(){

    //creating several movies and time slots
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"The Godfather", DRAMA, 175};
    Movie movie4 = {"Inception", THRILLER, 148};
    Movie movie5 = {"La La Land", ROMANCE, 128};

    //Timeslots
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie3, {16, 45}}; 
    TimeSlot time_s1 = {movie4, {17,25}};
    TimeSlot time_s2 = {movie5, {18,25}};

    //print out details of each time slot
    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(time_s1);
    printTimeSlot(time_s2);

    std::cout << std::endl;
    std::cout << std::endl;

    //testing the scheduleAfter function
    TimeSlot nextSlot = scheduleAfter(time_s2, movie5);
    printTimeSlot(nextSlot);

    return 0;
}


*/