/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Project 2

takes an input and outputs the pronounciation of the inputted word.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string test, trash;
    int junk;
    bool testing = true;
    ifstream fin("cmudict.0.7a.txt");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }

    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
        cout << trash << endl;
    }
    cout << endl;
    //getline(fin, test);
    //cout << test << endl;
    
    do
    {   
        getline(fin, test);
        if (test == "")
        {
            testing = false;
            break;
        }
        cout << test << endl;
    }while(testing);
}