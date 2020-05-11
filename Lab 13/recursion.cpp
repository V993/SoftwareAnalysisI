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

bool nestedParens(string s);

bool divisible(int *prices, int size);

bool divisibles(int *prices, int size, int first, int second);

int main()
{
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    cout << divisible(prices, 9) << endl;
    return 0;
}

bool divisibles(int *prices, int size, int first, int second) // helper function for divisible
{
    if (size == 0) // if the size is zero, test first against second for result
    {
        return (first == second);
    }
    else if (divisibles(prices, size -1, first + prices[size -1], second)) //recursive run of divisibles with decremented size, and added price to first
    {
        return true;
    }
    else if (divisibles(prices, size -1, first, second + prices[size -1])) //recursive run of divisibles with decremented size, and added price to second
    {
        return true;
    }
    else{ 
        return false;
    }
}

bool divisible(int *prices, int size)
{
    bool result = divisibles(prices, size, 0, 0); //send information to helper function with initial first and second values of zero
    return result;
}

bool nestedParens(string s)
{
    if (s == "")
    {
        return true;
    }
    else if (s.length() % 2 != 0)
    {
        return false;
    }
    else if (!(s[0] == '(' && s[s.length() - 1] == ')'))
    {
        return false; 
    }
    else {
        return nestedParens(s.substr(1, s.length() - 2));
    }
}

bool isAlphanumeric(string s)
{
    if (s != "")
    {
        if (isalpha(s[0]) || isdigit(s[0])) {

            return (isAlphanumeric(s.substr(1, s.length()-1)));
        }
        else return false;
    }
    else {
        return true;
    }
}
//
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
//
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
//
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