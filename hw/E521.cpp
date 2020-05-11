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

// computes a string in reverse.
string reverse(string str);

int main()
{
    string input;
    cout << "\tEnter string to reverse : ";
    cin >> input;
    cout << endl;
    string reversed = reverse(input);
    cout << "\tReversed string         : " << reversed << endl;

    return 0;
}

string reverse(string str)
{    
    // include base case
    if (str == "")
    {
        return "";
    }

    char firstChar = str[str.length() - 1]; // to get the last character in the string
    string remainder = str.substr(0, str.length() - 1); // to get the remaining characters that come before the last one

    string reversing = firstChar + reverse(remainder);  // add the last character (which is now the first character) to the 
                                                        // remainder characters. This repeats until we get an empty string


    return reversing; // we return this new string, with the last character now first, and repeat until the base case is met 
                      // and we return an empty string.
    // return (str[str.length() - 1] + reverse(str.substr(0, str.length() - 1)));
}