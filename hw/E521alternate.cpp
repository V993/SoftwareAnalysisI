
//doesn't reverse the word, takes the first part 
//and flips it into the second and vice versa

#include <iostream>
#include <string>
using namespace std;

//computes a string in reverse.
string reverse(string str);

int main()
{
    string input;
    cout << "\tEnter string to reverse : ";
    cin >> input;
    cout << endl;
    string reversed = reverse(input);
    cout << "\tReversed string         : " << reversed << endl;
}

string reverse(string str)
{    
    string result = str;
    int len = str.length();
    if (len % 2 == 0)
    {
        for (int i = 0; i < len / 2; i++)
        {   
            result[i] = str[i + (len/2)];
            result[i + (len/2)] = str[i];
        }
    }
    else 
    {
        for (int i = 0; i < len / 2; i++)
        {   
            if (i == len / 2)
            {
                result[i] = str[i];
            }
            else
            {
                result[i] = str[i + (len/2)];
                result[i + (len/2)] = str[i];
            }
        }        
    }
    return result;
}