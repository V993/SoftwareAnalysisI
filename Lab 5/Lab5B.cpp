/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Lab 1B

defines a function isDivisibleBy which returns a bool

*/

#include <iostream>
using namespace std; 

//declare function which will return bool value
bool isPrime(int n)
{	
	bool test;
	int i = 2;

	if (n == 2)
	{
		test = true;
	}
	else if (n < 2)
	{
		test = false;
	}
	else
	{
		while (i < n)
		{
			if (n % i == 0)
			{
				test = false;
				break;
			}
			else
			{
				test = true;
			}
			i++;
		}
	}
	return test;
}

//declare function which will return a bool value:
bool isDivisibleBy(int n, int d) // takes two arguments
{
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
	//declarations/input
	int n;
	cout << "Enter an integer greater than 2: " << endl;
	cin >> n;

	bool test = isPrime(n);

	if (test == true)
	{
		cout << "Entered number is prime." << endl;
	}
	else
	{
		cout << "Entered number is not prime." << endl;
	}
}



