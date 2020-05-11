/*

Write a recursive function

string reverse(string str)
that computes the reverse of a string. For example, 
reverse("flow") should return "wolf". Hint: Reverse 
the substring starting at the second character, then 
add the first character at the end. For example, to
reverse "flow", first reverse "low" to "wol", then add 
the "f" at the end.

*/

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
            result[i] = str[len - (i + 1)];
            result[(len - (i + 1))] = str[i];
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
                result[i] = str[len - (i +  1)];
                result[(len - (i + 1))] = str[i];
            }
        }        
    }
    return result;
}