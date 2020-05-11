/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Project 2

takes an input and outputs the pronounciation of the inputted word.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

//takes an input of pronounciation and outputs words with tehs 
string identical(string pronounciation);

//string that takes an input of a word and outputs the phonetics of the word
string dictionary(string word);

//function which takes string s, before, and after, and modifies before and after
//as the first component of the string before the space, and after.
void splitOnSpace(string s, string & before, string & after);

int main()
{
    string input; 
    cout << "Enter a word: ";
    cin >> input;
    string word = "";
    for (int i = 0; i < input.length(); i++)
    {
        char chr = toupper(input[i]);
        word += chr; 
    }
    string pronounciation = dictionary(word);
    if (pronounciation == "Not found.")
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Pronounciation: " << pronounciation << endl;   
        string identicals = identical(word);
        cout << "Identical: " << identicals << endl;
    }   
}

    string identical(string word)
    {
        string line, trash;
        string beforeSpace, afterSpace;
        int junk;
        string test;

        string identical = "";
        ifstream fin("cmudict.0.7a.txt");
        if (fin.fail())
        {
            cerr << "File cannot be found." << endl;
            exit(1);
        }
        for (int junk = 0; junk < 54; junk++)
        {
            getline(fin, trash);
        }
        cout << endl;

        string pronounce = dictionary(word);

        while(getline(fin, line))
        {
            //cout << x << " " << y << endl;
            //getline(fin, line);
            splitOnSpace(line, beforeSpace, afterSpace);
            if (beforeSpace != word)
            {
                if (afterSpace == pronounce)
                {
                    //cout << beforeSpace << endl;
                    //cout << afterSpace << endl;
                    identical += beforeSpace + " ";
                }            
            }
        }
        fin.close();
        return identical;
    }

string dictionary(string word)
{
    string line, trash, pronounce, dictionaryWord;
    string beforeSpace, afterSpace;
    string file;
    int junk;
    bool test = true;

    ifstream fin("cmudict.0.7a");
    if (fin.fail())
    {
        cerr << "File cannot be found." << endl;
        exit(1);
    }
    for (int junk = 0; junk < 54; junk++)
    {
        getline(fin, trash);
        //cout << trash << endl;
    }
    cout << endl;

    for (int i = 0; i < 133342; i++)
    {
        getline(fin, line);
        //cout << line << " " << i << endl;
        splitOnSpace(line, beforeSpace, afterSpace);
        //cout << beforeSpace << setw(12) << afterSpace << endl;
        if (beforeSpace == word)
        {
            pronounce = afterSpace;
            //cout << i << endl;
            //cout << "success" << endl;
            //test = false;
            break;
        }
        else
        {
            pronounce = "Not found.";
        }
    }
    
    fin.close();
    //cout << line << endl;
    return pronounce;
}

void splitOnSpace(string s, string & before, string & after)
{
    before = "";
    after = "";

    int i = 0;
    while (i < s.size() && !isspace(s[i]))
    {
        before = before + s[i];
        i++;
    }
    i++; //next character after the first word
    while (i < s.size())
    {
        after = after + s[i];
        i++;
    }
}