/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Homeowrk E3.1
Write a program that reads an integer prints whether it is negative, zero, or positive.
*/
#include <iostream>
using namespace std; 

int main()
{
	int i;
	cout << "Enter an integer: " << endl;
	cin >> i;

	if (i < 0)
	{
		cout << "Negative" << endl;
	}
	else if (i > 0)
	{
		cout << "Positive" << endl;
	}
	else if (i == 0)
	{
		cout << "Zero" << endl;
	}
}