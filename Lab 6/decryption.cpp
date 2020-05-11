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

string encryptCaesar(string plaintext, int shift);
char shiftChar(char chr, int shift);
string encryptVigenere(string plaintext, string keyword);
char encrypt(char chr, int shift);
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);
char deencrypt(char chr, int shift);

int main()
{
    string plaintext, keyword;
    int shift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << endl;
    cout << endl;

        cout << "= Caesar =" << endl;
        cout << "Enter shift: ";
        cin >> shift;
        cout << endl;

    string encryptedCaesar = encryptCaesar(plaintext, shift);
    cout << "Ciphertext: " << encryptedCaesar << endl;

    string decryptedCaesar = decryptCaesar(encryptedCaesar, shift);
    cout << "Decrypted: " << decryptedCaesar << endl;
    cout << endl;

        cout << "= Vigenere =" << endl;
        cout << "Enter keyword: ";
        cin >> keyword;
        cout << endl;

    string encryptedVigenere = encryptVigenere(plaintext, keyword);
    cout << "Ciphertext: " << encryptedVigenere << endl;

    string decryptedVigenere = decryptVigenere(encryptedVigenere, keyword);
    cout << "Decrypted: " << decryptedVigenere << endl;
    cout << endl;
    cout << endl;
}

string decryptVigenere(string encrypted, string keyword)
{
    int len = encrypted.length();
    int kLen = keyword.length();
    int j = 0; 

    int shift;
    char chr, shifted;

    string decodedWord = "";
    for (int i = 0; i < len; i++)
    {
        chr = encrypted[i];
        if (isspace(chr))
        {
            decodedWord += chr;
        }
        else if (isalpha(chr))    //if it's an alphabetic character
        {
            if (j < kLen)         //if our test variable j is less than kLen, we run for the value of j
            {
                shift = int(keyword[j]) - int('a'); //the shift is the keyword character minus the ascii 'a'
                // cout << i << " " << shift << endl;
                char shifted = deencrypt(chr, shift); //referencing our helper function to encrypt with our shift and character
                decodedWord += shifted;               //adding the coded character into the coded word     
            }
            else if (j >= kLen)   //if our test variable j is greater than or equal to j, we run for j = 0
            {   
                j = 0;
                shift = int(keyword[j]) - int('a'); //the shift is the keyword character minus the ascii 'a'
                char shifted = deencrypt(chr, shift); //referencing our helper function to encrypt with our shift and character
                decodedWord += shifted;               //adding the coded character into the coded word 
            }
            // cout << i << setw(3) << j << setw(3) << shift <<endl; 
            j++;           
        }
        else
        {
            decodedWord += chr;
        }
    }
    return decodedWord;
}

char deencrypt(char chr, int shift)
{
    char newChar;
    int num, offset, wrap;
    if (isalpha(chr))
    {
        num = int(chr); //if it is, we convert it into its ascii number
        if ((num >= int('A')) && (num <= int('Z'))) // if it's uppercase
        {
            offset = num - shift - int('A');
            if (offset >= 0)
            {
                wrap = offset;
            }
            else
            {
                wrap =  26 + offset;
            }
            //cout << offset << setw(3) << wrap << setw(3) << shift << endl;
            newChar = char(int('A') + wrap);
           
        }
        else if ((num >= int('a')) && (num <= int('z'))) //same but for lowercase
        {
            offset = num - shift - int('a');
            if (offset >= 0)
            {
                wrap = offset;
            }
            else
            {
                wrap =  26 + offset;
            }
            //cout << offset << setw(3) << wrap << setw(3) << shift << endl;
            newChar = char(int('a') + wrap);
           
        }
    }
    else
    {
        newChar = chr;
    }
    return newChar;
}

string encryptVigenere(string plaintext, string keyword)
{
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

string decryptCaesar(string encrypted, int shift)
{
    int len = encrypted.length();
    char chr, newChar;
    int num, offset, wrap;
    
    string decrypted = "";

    for (int i = 0; i < len; i++)
    {
        chr = encrypted[i];
        if (isalpha(chr))
        {
            num = int(chr); //if it is, we convert it into its ascii number
            if ((num >= int('A')) && (num <= int('Z'))) // if it's uppercase
            {
                offset = num - shift - int('A');
                if (offset >= 0)
                {
                    wrap = offset;
                }
                else
                {
                    wrap =  26 + offset;
                }
                //cout << offset << setw(3) << wrap << setw(3) << shift << endl;
                newChar = char(int('A') + wrap);
                decrypted += newChar;
            }
            else if ((num >= int('a')) && (num <= int('z'))) //same but for lowercase
            {
                offset = num - shift - int('a');
                
                if (offset >= 0)
                {
                    wrap = offset;
                }
                else
                {
                    wrap =  26 + offset;
                }
                //cout << offset << setw(3) << wrap << setw(3) << shift << endl;
                newChar = char(int('a') + wrap);
                decrypted += newChar;
            }
        }
        else
        {
            decrypted += chr;
        }
    }
    return decrypted;
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