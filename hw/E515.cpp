/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Homework 5.14

swaps the values of a, b and c
if a is greater than b and otherwise leaves a and 
b unchanged.

*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b);

void sort3(int& a, int& b, int& c);

int main()
{
    int num1, num2, num3;

    cout << "Enter a number: " << endl;
    cin >> num1;
    cout << "Enter a number: " << endl;
    cin >> num2;
    cout << "Enter a number: " << endl;
    cin >> num3;

    sort3(num1, num2, num3);

    cout << "Organized: " << num1 << " " << num2 << " " << num3 << endl;
}

void sort3(int& a, int& b, int& c)
{
    sort2(b, c);

    sort2(a, c);

    sort2(a, b);
}

void sort2(int& a, int& b)
{
    int c = a;
    if (a > b)
    {
        a = b;
        b = c;
    }
    else 
        a = a;
        b = b;
}