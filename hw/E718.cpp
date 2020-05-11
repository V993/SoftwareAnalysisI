/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Homework E7.18

Task: Define a structure Triangle that contains three 
Point members. Write a function that computes the perimeter 
of a Triangle. Write a program that reads the coordinates 
of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x,y;
}a,b;

struct Triangle{
    Point x;
    Point y;
    Point z;
}x,y,z;

double distance(Point a, Point b);

double perimeter(Triangle test);

int main()
{
    // Point a = {0, 1};
    // Point b = {1, 0};
    // Point c = {1, 1};

    Point a, b, c;
    cout << "Enter point a: ";
    cin >> a.x >> a.y;
    cout << endl;
    cout << "Enter point b: ";
    cin >> b.x >> b.y;
    cout << endl;
    cout << "Enter point c: ";
    cin >> c.x >> c.y;
    cout << endl;

    Triangle test;
    test.x = a;
    test.y = b;
    test.z = c;

    double peri = perimeter(test);
    cout << "Perimiter of Triangle: " << peri << endl;
}

double perimeter(Triangle test)
{
    Point a = test.x;
    Point b = test.y;
    Point c = test.z;

    double x = distance(a, b);
    double y = distance(b, c);
    double z = distance(a, c);

    double peri = x + y + z;
    return peri;
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