/* 
Author: Leonardo Matone
Instructor: Katherine 
Assignment: Lab 7B

Goal: enhances the Lab 7A. takes input line by line, and counts
the number of open and closed { } in it, keeping track of the
blocks currently open at each line.
*/

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

//takes input of a string and character and ouputs the number of occurences
int countChar(string line, char c);
//takes input of a string and removes leading spaces
string removeLeadingSpaces(string line);

int main()
{  
    string line;
    //while there are lines to input, take input.

    int i = 0;
    int open = 0, close = 0, tabs = 0;
    while(getline(cin, line))
    {
        string newLine = removeLeadingSpaces(line); // for every line, call function
        if (newLine[0] != '}')
        {
            for (int i = 0; i < tabs; i++)
            {
                cout << "\t";
            }           
        }
        else
        {
            for (int i = 0; i < tabs - 1; i++)
            {
                cout << "\t";
            }
        }
 
        cout << newLine << endl;
        open += countChar(newLine, '{');
        //cout << i << " " << open << endl;
        close += countChar(newLine, '}');
        //cout << "  " << close << endl;
        tabs = open - close;
        //cout << "  " << tabs << endl;
        i++;
    }
}

int countChar(string line, char c)
{
    int count = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == c)
        {
            count++;
        }
    }
    return count++;
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