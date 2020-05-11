/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Lab 13C

Goal: use recursion to sum an array

*/

#include <iostream>
using namespace std;

void printRange(int left, int right);

int sumRange(int left, int right);

int sumArray(int *arr, int size);

int main()
{
    int size = 3;
    int arr[] = {1, 2, 3};

    int sum1 = sumArray(arr, size); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 43

    // delete[] arr;         // deallocate it
}

int sumArray(int *arr, int size)
{
    if (size > 0)
    {
        // return the last index of the array plus the other indexes in reverse order.
        return (arr[size - 1] + sumArray(arr, (size - 1)) );
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