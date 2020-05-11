/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: E6.8

Write a function:
    "bool equals(int a[], int a_size, int b[], int b_size)""
which checks whether two arrays have the same elements in the same order
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size);

int main()
{
    int val, val2; 
    int size;

    cout << "Enter an array size: ";
    cin >> size;
    cout << endl;
    static int a_size = size;
    static int b_size = size;

    int a[a_size];
    int b[b_size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a value for array A, position " << i << ": ";
        cin >> val;
        cout << endl;
        a[i] = val;
    }
    for (int j = 0; j < size; j++)
    {
        cout << "Enter a value for array B, position " << j << ": ";
        cin >> val2;
        cout << endl;
        b[j] = val2;
    }
    bool test = equals(a, a_size, b, b_size);
    if (test)
    {
        cout << "Two arrays are identical." << endl;
    }
    else
    {
        cout << "Arrays are different." << endl;
    }
}
bool equals(int a[], int a_size, int b[], int b_size)
{
    bool test;
    if (a_size == b_size)
    {
        for (int i = 0; i < a_size; i++)
        {
            if (a[i] == b[i])
            {
                test = true;
            }
            else
            {
                test = false;
                break;
            }
        }
    }
    else {return false;}
    return test;
}