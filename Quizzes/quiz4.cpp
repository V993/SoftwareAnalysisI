/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Quiz4

Takes input from a datafile and returns information from file

*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main()
{
	int i;

	ifstream test("data.txt");
	if (test.fail())
	{
		cerr << "File cannot be opened for reading." << endl;
		exit(1);
	}

	string line; 
	for (i = 0; i < 10; i++)
	{
		getline(test, line);
		cout << line << endl;
	}
	test.close();
}