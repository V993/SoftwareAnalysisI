/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 13B

Goal: use recursion to print a sum of numbers in a range

*/

#include <iostream>
using namespace std;

void printRange(int left, int right);

int sumRange(int left, int right);

int main()
{
    int sum = sumRange(1, 3); //initial function call
    cout << "This is: " << sum << endl;
}

int sumRange(int left, int right)
{
    if (left <= right) //if left bound is less than/equal to right bound
    {
        return (left + sumRange(left + 1, right)); //add the sumrange of left+1 to left for sum
    }
    else{ //base case
        return 0; //return left 
    }
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