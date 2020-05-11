/* 
Author: Leonardo Matone
Instructor: Katherine 
Assignment: Lab 7A

Goal: to read input from cin and print out each input 
line with leading spaces removed
*/

#include <iostream>
#include <cctype>
using namespace std;

//takes input of a string and removes leading spaces
string removeLeadingSpaces(string line);

int main()
{  
    string line;
    //while there are lines to input, take input.
    while(getline(cin, line))
    {
        string newLine = removeLeadingSpaces(line); // for every line, call function
        cout << newLine << endl; //print out the modified function
    }
}

string removeLeadingSpaces(string line)
{
    int count = 0; //initial count
    string newLine = ""; // initial output
    for (int i = 0; i < line.size(); i++) //loop through each character in size
    {
        if (isspace(line[i])) //if the character is a space
        {
            count++; // count if char is space
        }
        else
        {
            break; //when we hit a char that isn't a space, break with current count
        }
    }
    for (int j = count; j < line.size(); j++) //loop from count to the last character in line
    {
        newLine += line[j]; // add every character in line after count to output string
    }
    return newLine; //output string.
}