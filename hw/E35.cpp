//E3.5

/*

//Write a program that reads three numbers and prints “increasing” 
//if they are in increasing order, “decreasing” if they are in decreasing 
//order, and “neither” otherwise. Here, “increasing” means “strictly 
//increasing”, with each value larger than its predecessor. The sequence
//3 4 4 would not be considered increasing.

Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Homework E3.5

*/

#include <iostream>
using namespace std;

int main()
{
	//inputs/declarations
	int num1, num2, num3;
	cout << "Enter number 1: " << endl;
	cin >> num1;
	cout << "Enter number 2: " << endl;
	cin >> num2;
	cout << "Enter number 3: " << endl;
	cin >> num3;

	//three if statements with subsequent if statements to test for the nature of the input
	if (num1 > num2) 
	{
		if (num2 > num3)
		{
			cout << "decreasing" << endl;
		}
		else
		{
			cout << "neither" << endl;
		}
	}
	if (num2 > num1)
	{
		if (num3 > num2)
		{
			cout << "increasing" << endl;
		}
		else
		{
			cout << "neither" << endl;
		}
	}
	if (num3 > num2)
	{
		if (num2 > num1)
		{
			cout << "increasing" << endl;
		}
		else
		{
			cout << "neither" << endl;
		}
	}
	else
	{
		cout << "untested eventuality." << endl;
	}
}