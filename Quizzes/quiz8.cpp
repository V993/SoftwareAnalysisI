/*
Author: Leonardo Matone
Instructor: Katherine Howitt

Assignment: Quiz 8

Task: class Date, print Date

*/

#include <iostream>

using namespace std;

class Date{
public:
    int year;
    int month;
    int day;
    string day_of_week;
}year,month,day,day_of_week;

void printDate(Date * input);

int main()
{
    Date today;

    today.day_of_week = "Wednesday";
    today.month = 11;
    today.year = 2019;
    today.day = 13;

    Date * input = &today;
    printDate(input);
}

void printDate(Date * input)
{
    cout << (*input).day_of_week << ", " << (*input).month << "/" << (*input).day << "/" << (*input).year << endl;
}


