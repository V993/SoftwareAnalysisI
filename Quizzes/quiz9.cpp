/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Quiz 9

Goal: Returns the difference of unbalanced open and closed blocks of brackets in the input.

*/

#include <iostream>
using namespace std;

int unbalanced_brackets(string input);

int main()
{
    string bracks;
    cout << "Enter brackets: ";
    cin >> bracks;
    cout << endl;

    int out = unbalanced_brackets(bracks);
    cout << "Output: " << out << endl;
}

int unbalanced_brackets(string input)
{
    int count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        char chr = input[i];
        if (chr == '}')
        {
            count--;
        }
        if (chr == '{')
        {
            count++;
        }
    }
    return count;
}