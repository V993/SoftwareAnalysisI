/* 
Author: Leonardo Matone
Instructor: Katherine 
Assignment: Lab 6B

Goal: Successfully implement a caesar cypher in c++
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

//Caesar cipher encryption.
string encryptCaesar(string plaintext, int shift);

//function to shift one character shift number of times.
char shiftChar(char chr, int shift);

int main()
{	
    //declarations
    string plaintext;
    int shift;
    
    //inputs
    cout << "Enter phrase: ";
    getline(cin, plaintext); // take the whole line of input
    cout << endl;
    cout << "Enter shift: ";
    cin >> shift;
    cout << endl;

    //using the function encryptCaesar to take plaintext and shift to output a cipher
    string encrypted = encryptCaesar(plaintext, shift);
    cout << "Ciphered text: " << encrypted << endl;
}

string encryptCaesar(string plaintext, int shift)
{
    //defining the length of the plaintext, which will be our stop in the for loop
    int len = plaintext.length();

    //our ciphertext starts as an empty string, we add characters as we go along
    string newWord = "";
    for (int i = 0; i < len; i++)
    {
        char chr = plaintext[i]; //cycling through each character
        //cout << chr << endl;
        char newChar = shiftChar(chr, shift); //using the helperfunction newChar to take shift and chr to output chars
        newWord += newChar; //compiling each character into our new word
    }
   // cout << newWord << endl;
    return newWord;
}

char shiftChar(char chr, int shift)
{
    //declarations
    char newChar; 
    int num, offset, wrap;
    // testing if the input is an alphabetic character
    if (isalpha(chr))
    {
        num = int(chr); //if it is, we convert it into its ascii number
        if ((num >= int('A')) && (num <= int('Z'))) // if it's uppercase
        {
            offset = (num - int('A')) + shift; //offset is the ascii number minus the ascii of uppercase A plus the shift
            wrap = offset % 26; //we wrap the alphabet if it leaves
            newChar = char(int('A') + wrap); //converting it back into characters plus the wrap/shift
            return newChar; //return it
        }
        else if ((num >= int('a')) && (num <= int('z'))) //same but for lowercase
        {
            offset = (num - int('a')) + shift;
            wrap = offset % 26;
            newChar = char(int('a') + wrap);
            return newChar;
        }
    }
    else
    {
        return chr; //if it's not alphabetical
    }
}