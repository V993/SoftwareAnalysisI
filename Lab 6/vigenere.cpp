/* 
Author: Leonardo Matone
Instructor: Katherine 
Assignment: Lab 6C

Goal: Successfully implement a Vigenere cypher in c++
*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

//vigenere function
string encryptVigenere(string plaintext, string keyword);

//funtion which takes characters from vigenere and returns the shifted character
char encrypt(char chr, int shift);

int main()
{
    //declarations
    string plaintext, keyword;

    //inputs
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << endl; 
    cout << "Enter keyword: ";
    getline(cin, keyword);
    cout << endl;

    //referencing Vigenere with inputs
    string codedWord = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext: " << codedWord << endl; //output
}

string encryptVigenere(string plaintext, string keyword)
{
   // cout << plaintext << endl;
 
    //declarations 
    int len = plaintext.length(); //determines the length of the word
    int kLen = keyword.length();  //determines the length of the keyword
    int j = 0;
    //cout << len << endl;
    int shift;
    char chr, shifted;

    string codedWord = ""; //sets up an empty string we will add characters to
    for (int i = 0; i < len; i++) //for every character in plaintext
    {
        chr = plaintext[i];       //determining the character we will encode
        if (isspace(chr))         //if the character is a space, we just add it to the new word
        {
            codedWord += chr;
        }
        else if (isalpha(chr))    //if it's an alphabetic character
        {
            if (j < kLen)         //if our test variable j is less than kLen, we run for the value of j
            {
                shift = int(keyword[j]) - int('a'); //the shift is the keyword character minus the ascii 'a'
                // cout << i << " " << shift << endl;
                char shifted = encrypt(chr, shift); //referencing our helper function to encrypt with our shift and character
                codedWord += shifted;               //adding the coded character into the coded word     
            }
            else if (j >= kLen)   //if our test variable j is greater than or equal to j, we run for j = 0
            {   
                j = 0;
                shift = int(keyword[j]) - int('a'); //the shift is the keyword character minus the ascii 'a'
                char shifted = encrypt(chr, shift); //referencing our helper function to encrypt with our shift and character
                codedWord += shifted;               //adding the coded character into the coded word 
            }
            // cout << i << setw(3) << j << setw(3) << shift <<endl; 
            j++;           
        }
        else
        {
            codedWord += chr;
        }
    }
    return codedWord;
}

char encrypt(char chr, int shift)
{
    char newChar;
    int num, offset, wrap;
    if (isalpha(chr))
    {
        num = int(chr);
        if ((num >= int('A')) && (num <= int('Z')))
        {
            offset = (num - int('A')) + shift;
            wrap = offset % 26;
            newChar = char(int('A') + wrap);
            return newChar;
        }
        else if ((num >= int('a')) && (num <= int('z')))
        {
            offset = (num - int('a')) + shift;
            wrap = offset % 26;
            newChar = char(int('a') + wrap);
            return newChar;
        }
    }
    else
    {
        return chr;
    }
}


