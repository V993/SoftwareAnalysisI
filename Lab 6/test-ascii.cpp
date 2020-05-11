/* 
Author: Leonardo Matone
Instructor: Katherine 
Assignment: Lab 6A


*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{	
	string line, s;
	cout << "Input: ";
	getline(cin, s); // take the whole line of input
	cout << endl;
	
//	cout << s << endl;
	// cycle through each character in the range of s-length
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i])) //test if alphabetical, then run cast
		{
			cout << s[i] << " " << static_cast<int>(s[i]) << endl;	
		}
		else if (isspace(s[i])) // test if space, provided specific instance
		{
			cout << "  " << 32 << endl;
		}
		else	//if all else fails, yolo it
		{
			cout << s[i] << " " << static_cast<int>(s[i]) << endl;	
		}
	}
}