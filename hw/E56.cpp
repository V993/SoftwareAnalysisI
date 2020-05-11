/*

Write a function

string middle(string str)

that returns a string containing the middle character in str if the 
length of str is odd, or the two middle characters if the length is even. 
For example, middle("middle") returns "dd".
*/

#include <iostream> 
#include <string>
using namespace std;

//declaring string middle function
string middle(string str)
{
    string mid;
    int len = str.size(); //finding the size of our string
    //cout << len << endl;

    if (len % 2 == 0)     //for if even
    {
        mid = str.substr((len/2 - 1), 2);
        //print the substring of length 2, starting at the integer
        //division of len by 2 minus 1 (the first character) and going
        //on to the second character 

    }
    else if (len % 2 != 0)
    {   
        mid = str.substr(len/2, 1); 
    }
    return mid;
}

int main()
{
    string mid, str;
    cout << "Enter a string: " << endl;
    cin >> str;
    mid = middle(str);
    cout << mid << endl;
}