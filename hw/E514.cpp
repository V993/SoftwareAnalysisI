/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Homework 5.14

write a function which swaps the values of a and b 
if a is greater than b and otherwise leaves a and 
b unchanged.

*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b);

int main()
{
    int num1, num2, num3;

    cout << "Enter a number: " << endl;
    cin >> num1;
    cout << "Enter a number: " << endl;
    cin >> num2;

    sort2(num1, num2);

    cout << "Organized: " << num1 << " " << num2 << endl;
}

void sort2(int& a, int& b)
{
    int c = a;
    if (a > b)
    {
        a = b;
        b = c;
       ; 
    }
    else 
        a = a;
        b = b;
}