/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Lab 1A

defines a function isDivisibleBy which returns a bool

*/

#include <iostream>
using namespace std;

//declare function which will return a bool value:
bool isDivisibleBy(int n, int d) // takes two arguments
{
	if (d == 0)
	{
		return false;
	}
	if (n % d == 0) //test to see if there is a remainder in the division
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n, j;
	cout << "num1: " << endl;
	cin >> n;
	cout << "num2: " << endl;
	cin >> j;

	bool test = isDivisibleBy(n, j);

	if (test == true)
	{
		cout << "Divisible by!" << endl;
	}
	if (test == false)
	{
		cout << "Not divisible by!" << endl;
	}
}


