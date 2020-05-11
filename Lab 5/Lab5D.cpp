/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Lab 1C

defines a function isDivisibleBy which returns a bool

*/

#include <iostream>
using namespace std; 

int  nextPrime(int n);

//declare function which will return bool value
bool isPrime(int n);

//declare function which will return a bool value:
bool isDivisibleBy(int n, int d); // takes two arguments

//declare function which will return the count of primes in a 
int countPrimes(int a, int b);

//declare function which will return 
bool isTwinPrime(int n);

int main()
{
	//declarations/input
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;

	bool twinPrime = isTwinPrime(num)
	cout << "The number of prime numbers in the bound is: " << count << endl;
}

bool isTwinPrime(int n)
{
	int n_2 = n - 2;
	int n_3 = n + 2;

	bool test = isPrime(n);
	if (test)
	{
		bool test_2 = isPrime(n_2);
		bool test_3 = isPrime(n_3);
		if (test_2 || test_3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int countPrimes(int a, int b)
{
    int num = a;
    int count = 0;
  
	while((num >= a) && (num <= b))
	{
		bool test = isPrime(num);
		
		if (test)
		{
			count++;
		}
		num++;
	}	
		
		
    return count;
}

int nextPrime(int n)
{
    int num = 0; //initial value of num
    int i = 2;
    while (n < (n+1000))   { // testing values in a loop until we hit a prime number
        int nextNum = n + 1; // testing the number after the input
        if (nextNum == 2)    //for the instance that the next number is 2 
        {
            num = nextNum;
        }
        else if (nextNum <= 0)
        {
        		nextNum = 1;

        }
        else
        {
            while (i < nextNum)
            {
                if (nextNum % i == 0)
                {
                    num = 0;
                   // cout << nextNum << " divisible by: " << i << endl;
                    i = 2;
                    break;  // now that we know the number is not prime,
                            //we don't really need to test the other numbers.
                }
                else
                {
                   // cout << nextNum << " not divisible by: " << i << endl;
                    num = nextNum; //assigning the prime number to num so we can return
                }
                i++;
                //  cout << i << endl;
            }
	    }
        n++;
        if (num == nextNum) // if it is prime, return the value
        {
            break;
        }
    }
	return num;
}

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