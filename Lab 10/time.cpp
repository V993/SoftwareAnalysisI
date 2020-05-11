/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 10 A

Description:

*/

#include <iostream>
using namespace std;

class Time {
public:
    int h;
    int m;
}h,m;

//Enum types work as sets of names values. A variable of type Genre can assume any of
//the values listed below. ex: Genre myFavorite = COMEDY;
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
public:
    string title;
    Genre genre;
    int duration;
}title, genre, duration;

class TimeSlot {
public:
    Movie movie;
    Time startTime;
}movie, startTime;


//returns true if the two timeslots overlap, otherwise false. 
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);

//produces and returns a new TimeSlot for the movie nextMovie, scheduled immediately after ts timeslot.
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

//prints timeslot
void printTimeSlot(TimeSlot ts);

//prints the title and duration of a movie
void printMovie(Movie mv);

//adds minutes to inputted time and returns new Time
Time addMinutes(Time time0, int min);

//reads time and gives minutes since midnight
int minutesSinceMidnight(Time time);

//reads an earlier and later time and determines how long between the two
int minutesUntil(Time earlier, Time later);

//prints inputted time
void printTime(Time time);

int main()
{
    //movie declaration
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Blade Runner", DRAMA, 126};
    Movie movie4 = {"Blazin' Saddles", COMEDY, 131};

    //time declaration
    Time morn = {9, 15};
    Time noon = {12, 15};
    Time afterN = {14, 15};
    Time eve = {16, 45};
    Time mid = {21, 45};

    //timeslot definition
    TimeSlot morning = {movie1, morn};
    TimeSlot daytime = {movie2, noon};
    TimeSlot evening = {movie2, eve};
    TimeSlot afternoon = {movie4, afterN};
    TimeSlot midnight = {movie3, mid};

    TimeSlot nextMovie = scheduleAfter(morning, movie2);
    printTimeSlot(nextMovie);
    cout << endl;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    bool test;
    Time start1 = ts1.startTime;
    Time start2 = ts2.startTime;
    Time earlier, later;

    if (start1.h > start2.h) {
        Time earlier = start1;
        Time later = start2;
        bool test = true;
    }
    else if (start2.h > start1.h){
        Time earlier = start2;
        Time later = start1;
        bool test = false;
    }
    else if (start1.h == start2.h)
    {
        if (start1.m > start2.m)
        {
            Time earlier = start1;
            Time later = start2;
            bool test = true;
        }
        else
        {
            Time earlier = start2;
            Time later = start1;
            bool test = false;
        }
    }
    bool result;
    int timeBetween = minutesUntil(earlier, later);
    if (test){  
        if (timeBetween >= (ts1.movie).duration) {
            result = false;
        }
        else {
            result = true;
        }
    }
    else {
        if (timeBetween >= (ts2.movie).duration) {
            result = false;
        }
        else {
            result = true;
        }
    }
    return result;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time start = ts.startTime;
    Time finish = addMinutes(ts.startTime, (ts.movie).duration);

    TimeSlot nextMovieTime = {nextMovie,{finish}};

    return nextMovieTime;
}

void printTimeSlot(TimeSlot ts)
{
    Movie movie = ts.movie;
    Time endingTime = addMinutes(ts.startTime, movie.duration);

    printMovie(movie);
    cout << " [starts at "; printTime(ts.startTime); cout << ", ends by "; printTime(endingTime); cout << "]";
}

void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) {
        case ACTION: 
            g = "ACTION"; 
            break;
        case COMEDY: 
            g = "COMEDY";
            break;
        case DRAMA: 
            g = "DRAMA";
            break;
        case ROMANCE: 
            g = "ROMANCE";
            break;
        case THRILLER: 
            g = "THRILLER";
            break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

Time addMinutes(Time time0, int min)
{
    int hours = time0.h;
    int minutes = time0.m;    
    Time newTime;

    if ((minutes + min) >= 60)
    {
        int addHours = (minutes + min) / 60;
        int addMinutes = (minutes + min) % 60;
        newTime.h = hours + addHours;
        newTime.m = addMinutes;
    }
    else
    {
        int addHours = 0;
        int addMinutes = minutes + min;

        Time newTime;
        newTime.h = hours + addHours;
        newTime.m = addMinutes;
    }

    return newTime;
}

int minutesSinceMidnight(Time time)
{
    int hours = time.h * 60;
    int minutes = time.m;

    int minutesSince = hours + minutes;

    return minutesSince;
}

int minutesUntil(Time earlier, Time later)
{
    int hoursEarlier = earlier.h * 60;
    int minutesEarlier = earlier.m;
    int hoursLater = later.h * 60;
    int minutesLater = later.m;

    int minutesTill = (hoursLater + minutesLater) - (hoursEarlier + minutesEarlier);

    return minutesTill;
}

void printTime(Time time)
{
    cout << time.h << ":" << time.m;
}