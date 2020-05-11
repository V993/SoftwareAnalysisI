/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 13A

Goal: use recursion to print a range of numbers

*/

#include <iostream>
using namespace std;

void printRange(int left, int right);

int main()
{
    printRange(-2, 10);
}

void printRange(int left, int right)
{
    if (left <= right)
    {
        cout << left << " ";
        printRange(left + 1, right);
    }
    else {
        cout << endl;
    }
}