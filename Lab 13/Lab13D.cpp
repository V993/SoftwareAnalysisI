/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 13C

Goal: use recursion to determine if a string is alphannumeric

*/

#include <iostream>
#include <cctype>
using namespace std;

void printRange(int left, int right);

int sumRange(int left, int right);

int sumArray(int *arr, int size);

bool isAlphanumeric(string s);

int main()
{
    cout << isAlphanumeric("ABCD") << endl;        // true (1)
    cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
    cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
}

bool isAlphanumeric(string s)
{
    if (s != "")
    {
        if (isalpha(s[0]) || isdigit(s[0])) {

            return (isAlphanumeric(s.substr(1, s.length())));
        }
        else return false;
    }
    else {
        return true;
    }
}

int sumArray(int *arr, int size)
{
    if (size >= 0)
    {
        // return the last index of the array plus the other indexes in reverse order.
        return (arr[size-1] + sumArray(arr, (size - 1)) );
    }
    else {
        return 0;
    }
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