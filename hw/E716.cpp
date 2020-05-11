/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Homework E7.16

Task: Define a structure Point. A point has an x and y component. 
Write a function double distance(Point a, Point b) that computes 
the distance from a to b. Write a program that reads the coordinates 
of the points, calls your function, and displays the result.

*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x,y;
}a,b;

double distance(Point a, Point b);

int main()
{

    cout << "Enter x value for point 1: ";
    cin >> a.x;
    cout << endl;
    cout << "Enter y value for point 1: ";
    cin >> a.y;
    cout << endl;
    cout << "Enter x value for point 2: ";
    cin >> b.x;
    cout << endl;
    cout << "Enter y value for point 2: ";
    cin >> b.y;
    cout << endl;
    double dist = distance(a, b);
    cout << "Distance is: " << dist << endl;
}

double distance(Point a, Point b)
{
    double xDiff = a.x - b.x;
    double yDiff = a.y - b.y;

    double xSquared = pow(xDiff, 2.0);
    double ySquared = pow(yDiff, 2.0);

    double xDiffer = sqrt(xSquared);
    double yDiffer = sqrt(ySquared);

    double distance = sqrt((pow(xDiffer, 2)) + (pow(yDiffer, 2)));

    return distance;
}