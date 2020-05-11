/*
Leonardo Matone
KAtherine Howitt

Quiz 7
*/

#include <string>
#include <iostream>
using namespace std;

void remove_e(string & sentence);

int main()
{
    string sentence = "Hello from everyone here";
    cout << "Original string: " << sentence << endl << endl;
    remove_e(sentence);
    cout << "Modified string: " << sentence << endl;
}

void remove_e(string & sentence)
{    
    int len = sentence.length();
    char chr; 
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        chr = sentence[i];
        if (chr != 'e')
        {
            sentence += chr;
            count++;
        }
    }
    sentence = sentence.substr(len, count);
}